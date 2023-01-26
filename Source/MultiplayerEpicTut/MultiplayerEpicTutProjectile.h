// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiplayerEpicTutProjectile.generated.h"

UCLASS()
class MULTIPLAYEREPICTUT_API AMultiplayerEpicTutProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMultiplayerEpicTutProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	virtual void Destroyed() override;
	UFUNCTION(Category = "Projectile")
	void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// sphere component to test collision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USphereComponent* SphereComponent;

	// static mesh used to provide a visual representation of the object
	class UStaticMeshComponent* StaticMesh;

		//Movement component for handling projectile movement
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

		// particle used when the projectile impacts against another object
		UPROPERTY(EditAnywhere, Category = "Effects")
			class UParticleSystem* ExplosionEffect;

		// the damage type and damage that will be done by this projectile
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
			TSubclassOf<class UDamageType> DamageType;

		// Damage dealt by this projectile
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
			float Damage;
};
