// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Engine.h"

void UMyBlueprintFunctionLibrary::SayHello_Internal() {
	if (GEngine) {
		const int32 AlwaysAddKey = -1;

		GEngine->AddOnScreenDebugMessage(AlwaysAddKey,
			5.0f,
			FColor::Purple,
			TEXT("Hello World!")
		);
	}
}

void UMyBlueprintFunctionLibrary::SaySomething_Internal(const TArray<FString>& InWords)
{
	FString OutString(TEXT("SaySomething Called:"));
	for (const auto& Word : InWords)
		OutString += Word;

	if (GEngine) {
		const int32 AlwaysAddKey = -1;

		GEngine->AddOnScreenDebugMessage(AlwaysAddKey,
			5.0f,
			FColor::Purple,
			OutString
		);
	}
}

bool UMyBlueprintFunctionLibrary::DeleteFile(const FString& path)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	bool result = PlatformFile.DeleteFile(*path);
	return result;
}
