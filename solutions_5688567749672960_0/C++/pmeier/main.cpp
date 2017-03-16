#include <cstdio>
#include <cstdint>
#include <cmath>

const uint32_t MAX_NUM_OF_PANCAKES = 1000;

uint32_t getFlipValue(uint32_t origNum) {
	uint32_t flipNum = 0;

	while (origNum != 0) {
		flipNum *= 10;
		flipNum += origNum % 10;
		origNum /= 10;
	}
	
	return flipNum;
}

uint32_t getReverseFlipValue(uint32_t origNum) {
	uint32_t flipNum = 0;
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

	uint32_t numOfTestCases = 0;
	fscanf_s(inputFile, "%lu", &numOfTestCases);
	printf_s("There are %lu number of test cases.\n", numOfTestCases);


	//Code here
	for (uint32_t i = 0; i < numOfTestCases; i++) {
		uint32_t targetNum = 0;
		fscanf_s(inputFile, "%lu", &targetNum);


		uint32_t steps = 1;
		uint32_t currentValue = 1;
		uint32_t flipValue = 0;

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
		uint32_t futureThreshold = 10;
		while (currentValue != targetNum) {
			if (currentValue < 1000) {
				futureThreshold = 10;
			}
			else if (currentValue < 100000) {
				futureThreshold = 100;
			}
			else {
				futureThreshold = 1000;
			}


			uint32_t nextJumpValue = 0;
			uint32_t nextJumpCount = 0;
			uint32_t tempJumpValue = 0;
			uint32_t tempJumpCount = 0;
			for (uint32_t i = currentValue + 1; i % futureThreshold != 0; i++) {
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
			printf_s("%lu\n", currentValue);
		}
		printf_s("Case #%lu: t_%lu r_%lu c_%lu.\n\n", i + 1, targetNum, steps, currentValue);

		fprintf_s(outputFile, "Case #%lu: %lu\n", i + 1, steps);

	}



	fclose(inputFile);
	fclose(outputFile);
}