#include <cstdio>
#include <cstdint>
#include <cmath>


uint64_t getFlipValue(uint64_t origNum) {
	uint64_t flipNum = 0;

	while (origNum != 0) {
		flipNum *= 10;
		flipNum += origNum % 10;
		origNum /= 10;
	}
	
	return flipNum;
}

uint64_t getReverseFlipValue(uint64_t origNum) {
	uint64_t flipNum = 0;
	if (origNum % 10 == 0) {
		return origNum;
	}

	while (origNum != 0) {
		flipNum *= 10;
		flipNum += origNum % 10;
		origNum /= 10;
	}

	return flipNum;
}

int main(int argc, char** argv) {
	printf_s("Google Code Jam 2015\n");

	if (argc != 3) {
		printf_s("Please enter the name of the input and output files only.\n");
		return 0;
	}

	FILE *inputFile = NULL, *outputFile = NULL;
	fopen_s(&inputFile, argv[1], "r");
	fopen_s(&outputFile, argv[2], "w");

	if (inputFile == NULL || outputFile == NULL) {
		printf_s("Unable to open the file.\n");
		return 0;
	}

	uint64_t numOfTestCases = 0;
	fscanf_s(inputFile, "%llu", &numOfTestCases);
	printf_s("There are %llu number of test cases.\n", numOfTestCases);


	//Code here
	for (uint64_t i = 0; i < numOfTestCases; i++) {
		uint64_t targetNum = 0;
		fscanf_s(inputFile, "%llu", &targetNum);


		uint64_t steps = 1;
		uint64_t currentValue = 1;
		uint64_t flipValue = 0;

		/*
		while (currentValue != targetNum) {

			flipValue = getFlipValue(currentValue);
			if (flipValue > currentValue && flipValue <= targetNum){
				currentValue = flipValue;
			}
			else {
				currentValue++;
			}

			steps++;
		}
		printf_s("Case #%lu: t_%lu r_%lu.\n", i + 1, targetNum, steps);

		steps = 0;
		currentValue = targetNum;
		flipValue = 0;
		while (0 != currentValue) {

			flipValue = getReverseFlipValue(currentValue);
			if (flipValue < currentValue){
				currentValue = flipValue;
			}
			else {
				currentValue--;
			}

			steps++;
		}
		printf_s("Case #%lu: t_%lu r_%lu.\n", i + 1, targetNum, steps);
		*/

		steps = 1;
		currentValue = 1;
		flipValue = 0;
		uint64_t futureThreshold = 10;
		while (currentValue != targetNum) {
			if (currentValue < 1000) {
				futureThreshold = 10;
			}
			else if (currentValue < 100000) {
				futureThreshold = 100;
			}
			else if (currentValue < 1000000) {
				futureThreshold = 1000;
			}
			else if (currentValue < 100000000) {
				futureThreshold = 10000;
			}
			else if (currentValue < 10000000000) {
				futureThreshold = 100000;
			}
			else if (currentValue < 1000000000000) {
				futureThreshold = 1000000;
			}
			else if (currentValue < 100000000000000) {
				futureThreshold = 10000000;
			}


			uint64_t nextJumpValue = 0;
			uint64_t nextJumpCount = 0;
			uint64_t tempJumpValue = 0;
			uint64_t tempJumpCount = 0;
			for (uint64_t i = currentValue + 1; i % futureThreshold != 0; i++) {
				tempJumpCount++;
				tempJumpValue = getFlipValue(i);
				if (i > tempJumpValue) {
					tempJumpValue = i;
				}
				else if (tempJumpValue > targetNum) {
					tempJumpValue = i;
				}

				if (tempJumpValue > nextJumpValue && tempJumpValue <= targetNum) {
					nextJumpValue = tempJumpValue;
					if (tempJumpValue != i) {
						nextJumpCount = tempJumpCount+1;
					}
					else {
						nextJumpCount = tempJumpCount;
					}
				}
			}

			currentValue = nextJumpValue;
			steps += nextJumpCount;

			if ((currentValue + 1) % futureThreshold == 0 && currentValue != targetNum) {
				currentValue++;
				steps++;
			}
			//printf_s("%lu\n", currentValue);
		}
		printf_s("Case #%llu: t_%llu r_%llu c_%llu.\n", i + 1, targetNum, steps, currentValue);

		fprintf_s(outputFile, "Case #%llu: %llu\n", i + 1, steps);

	}



	fclose(inputFile);
	fclose(outputFile);
}