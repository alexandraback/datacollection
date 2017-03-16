#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>

#include "InputData.h"
#include "ResultData.h"

using namespace std;


void processTestCase(TestCase& testCase, TestCaseResult& result)
{
	vector<double> naomiBlocks = testCase.naomiBlocks;
	vector<double> kenBlocks = testCase.kenBlocks;
	// Deceitful war
	for (int i = 0; i < testCase.N; i++)
	{
		// Naomi chooses
		unsigned int naomiChosenIndex = 0;
		double naomiChosen = naomiBlocks[0];
		double naomiTold;
		if (naomiChosen < kenBlocks.front())
		{
			naomiTold = kenBlocks.back() - 0.00001;
		}
		else
		{
			naomiTold = kenBlocks.back() + 0.00001;
		}
		naomiBlocks.erase(naomiBlocks.begin());

		// Ken chooses next biggest
		int kenChosenIndex = -1;
		for (int j = 0; j < kenBlocks.size(); j++)
		{
			if (kenBlocks[j] > naomiTold)
			{
				// Ken won
				assert(kenBlocks[j] > naomiChosen);
				kenChosenIndex = j;
				kenBlocks.erase(kenBlocks.begin() + kenChosenIndex);
				break;
			}
		}
		
		// Naomi won
		if (kenChosenIndex == -1)
		{
			assert(kenBlocks[0] < naomiChosen);
			result.deceitfulWarScore++;
			kenBlocks.erase(kenBlocks.begin());
		}

		// Round ends
	}

	naomiBlocks = testCase.naomiBlocks;
	kenBlocks = testCase.kenBlocks;

	// Normal war
	for (int i = 0; i < testCase.N; i++)
	{
		// Naomi chooses
		unsigned int naomiChosenIndex = rand() % naomiBlocks.size();
		double naomiChosen = naomiBlocks[naomiChosenIndex];
		naomiBlocks.erase(naomiBlocks.begin() + naomiChosenIndex);

		// Ken chooses next biggest
		int kenChosenIndex = -1;
		for (int j = 0; j < kenBlocks.size(); j++)
		{
			if (kenBlocks[j] > naomiChosen)
			{
				// Ken won
				kenChosenIndex = j;
				kenBlocks.erase(kenBlocks.begin() + kenChosenIndex);
				break;
			}
		}
		
		// Naomi won
		if (kenChosenIndex == -1)
		{
			result.normalWarScore++;
			kenBlocks.erase(kenBlocks.begin());
		}

		// Round ends
	}
}

void processInputData(InputData& inputData, ResultData& resultData)
{
	int numberOfTestCases = inputData.getNumberOfTestCases();
	for (int testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
	{
		TestCase testCase = inputData.getTestCase(testCaseIndex);
		TestCaseResult result;
		processTestCase(testCase, result);
		resultData.addResult(testCaseIndex, result);
	}
}

void main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc < 3)
	{
		cerr << "Incorrect parameters. Usage: magic-trick.exe <input file path> <output file path>" << endl;
		return;
	}

	// Prepare data structures
	string inputFilePath = argv[1];
	InputData inputData(inputFilePath);
	ResultData resultData;

	// Process data
	processInputData(inputData, resultData);

	// Write results
	string outputFilePath = argv[2];
	resultData.writeOutputFile(outputFilePath);
}