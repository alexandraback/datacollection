#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "InputData.h"
#include "ResultData.h"

using namespace std;

double cookiesPerSecond = 2.0;

void processTestCase(TestCase& testCase, TestCaseResult& result)
{
	double currentCPS = 2.0;
	double timeSpent = 0.0;
	double numOfCookies = 0.0;
	while(true)
	{
		double timeNeededToFinishWithoutAnotherFarm = testCase.X / currentCPS;
		double timeNeededToBuyAnotherFarm = testCase.C / currentCPS;

		// Check if we need less time to finish than to buy a farm
		if (timeNeededToFinishWithoutAnotherFarm < timeNeededToBuyAnotherFarm)
		{
			// Not buying another farm
			timeSpent += timeNeededToFinishWithoutAnotherFarm;
			break;
		}

		// Wait until we have enough cookies to buy an another farm
		timeSpent += timeNeededToBuyAnotherFarm;
		numOfCookies += timeNeededToBuyAnotherFarm * currentCPS;
		
		timeNeededToFinishWithoutAnotherFarm = (testCase.X - numOfCookies) / currentCPS;
		double timeNeededToFinishAfterBuyingFarm = testCase.X / (currentCPS + testCase.F);

		if (timeNeededToFinishWithoutAnotherFarm < timeNeededToFinishAfterBuyingFarm)
		{
			// Not buying another farm
			timeSpent += timeNeededToFinishWithoutAnotherFarm;
			break;
		}
		else
		{
			// Buying another farm
			currentCPS += testCase.F;
			numOfCookies -= testCase.C;
		}
	}
	result.answer = timeSpent;
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