#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "InputData.h"
#include "ResultData.h"

using namespace std;

#define MINE '*'
#define CLICK 'c'
#define EMPTY_CELL '.'

void placeMinesOn3x3(TestCaseResult& result, int numOfMines)
{
	if (numOfMines == 0)
	{

	}
	else if (numOfMines == 1)
	{
		result.field[2*result.colNum + 2] = MINE;
	}
	else if (numOfMines == 3)
	{
		result.field[2*result.colNum + 0] = MINE;
		result.field[2*result.colNum + 1] = MINE;
		result.field[2*result.colNum + 2] = MINE;
	}
	else if (numOfMines == 5)
	{
		result.field[2*result.colNum + 0] = MINE;
		
		result.field[2*result.colNum + 1] = MINE;
		result.field[2*result.colNum + 2] = MINE;

		result.field[0*result.colNum + 2] = MINE;
		result.field[1*result.colNum + 2] = MINE;
	}
	else if (numOfMines == 8)
	{
		result.field[0*result.colNum + 1] = MINE;
		result.field[0*result.colNum + 2] = MINE;

		result.field[1*result.colNum + 0] = MINE;
		result.field[1*result.colNum + 1] = MINE;
		result.field[1*result.colNum + 2] = MINE;

		result.field[2*result.colNum + 0] = MINE;
		result.field[2*result.colNum + 1] = MINE;
		result.field[2*result.colNum + 2] = MINE;
	}
	else if (numOfMines == 9)
	{
		result.field[0*result.colNum + 0] = MINE;
		result.field[0*result.colNum + 1] = MINE;
		result.field[0*result.colNum + 2] = MINE;

		result.field[1*result.colNum + 0] = MINE;
		result.field[1*result.colNum + 1] = MINE;
		result.field[1*result.colNum + 2] = MINE;

		result.field[2*result.colNum + 0] = MINE;
		result.field[2*result.colNum + 1] = MINE;
		result.field[2*result.colNum + 2] = MINE;
	}

}

void placeMinesOn2xN(TestCase& testCase, TestCaseResult& result)
{
	if (testCase.R == 2)
	{
		for (int c = testCase.C - 1; c > testCase.C - 1 - testCase.M / 2; c--)
		{
			result.field[0*testCase.C + c] = MINE;
			result.field[1*testCase.C + c] = MINE;
		}
	}

	if (testCase.C == 2)
	{
		for (int r = testCase.R - 1; r > testCase.R - 1 - testCase.M / 2; r--)
		{
			result.field[r*testCase.C + 0] = MINE;
			result.field[r*testCase.C + 1] = MINE;
		}
	}

}

int placeMinesOnBigField(TestCase& testCase, TestCaseResult& result)
{
	int minesLeft = testCase.M;
	int currentColumnIndex = testCase.C - 1;
	int currentRowIndex = testCase.R - 1;

	// Fill up to square
	while (currentColumnIndex != currentRowIndex)
	{
		if (currentColumnIndex < currentRowIndex)
		{
			for (int c = currentColumnIndex; c > 1; c--)
			{
				result.field[currentRowIndex*testCase.C + c] = MINE;
				minesLeft--;
				if (minesLeft == 0)
					return minesLeft;
			}
			if (minesLeft > 1)
			{
				result.field[currentRowIndex*testCase.C + 1] = MINE;
				result.field[currentRowIndex*testCase.C] = MINE;
				minesLeft -= 2;
				if (minesLeft == 0)
					return minesLeft;
			}
			else
			{
				// Done putting mines
				result.field[(currentRowIndex-1)*testCase.C + currentColumnIndex] = MINE;
				minesLeft--;
				return minesLeft;
			}
			currentRowIndex--;
		}
		else if (currentColumnIndex > currentRowIndex)
		{
			for (int r = currentRowIndex; r > 1; r--)
			{
				result.field[r*testCase.C + currentColumnIndex] = MINE;
				minesLeft--;
				if (minesLeft == 0)
					return minesLeft;
			}
			if (minesLeft > 1)
			{
				result.field[1*testCase.C + currentColumnIndex] = MINE;
				result.field[0*testCase.C + currentColumnIndex] = MINE;
				minesLeft -= 2;
				if (minesLeft == 0)
					return minesLeft;
			}
			else
			{
				// Done putting mines
				result.field[(currentRowIndex)*testCase.C + currentColumnIndex-1] = MINE;
				minesLeft--;
				return minesLeft;
			}
			currentColumnIndex--;
		}
	}

	// Decrease the size of the square to 3*3
	while(currentColumnIndex > 2 && currentRowIndex > 2)
	{
		// Fill last current row
		for (int c = currentColumnIndex; c > 1; c--)
		{
			result.field[currentRowIndex*testCase.C + c] = MINE;
			minesLeft--;
			if (minesLeft == 0)
				return minesLeft;
		}
		if (minesLeft > 1)
		{
			result.field[currentRowIndex*testCase.C + 1] = MINE;
			result.field[currentRowIndex*testCase.C] = MINE;
			minesLeft -= 2;
			if (minesLeft == 0)
					return minesLeft;
		}
		else
		{
			// Done putting mines
			result.field[(currentRowIndex-1)*testCase.C + currentColumnIndex] = MINE;
			minesLeft--;
			return minesLeft;
		}
		currentRowIndex--;

		// Fill last current column
		for (int r = currentRowIndex; r > 1; r--)
		{
			result.field[r*testCase.C + currentColumnIndex] = MINE;
			minesLeft--;
			if (minesLeft == 0)
				return minesLeft;
		}
		if (minesLeft > 1)
		{
			result.field[1*testCase.C + currentColumnIndex] = MINE;
			result.field[0*testCase.C + currentColumnIndex] = MINE;
			minesLeft -= 2;
			if (minesLeft == 0)
					return minesLeft;
		}
		else
		{
			// Done putting mines
			result.field[(currentRowIndex)*testCase.C + currentColumnIndex-1] = MINE;
			minesLeft--;
			return minesLeft;
		}
		currentColumnIndex--;
	}

	return minesLeft;
}

void processTestCase(TestCase& testCase, TestCaseResult& result)
{
	
	result.colNum = testCase.C;
	result.rowNum = testCase.R;
	result.isPossible = true;

	// Create field 
	result.field = new char[testCase.C * testCase.R];
	memset(result.field, EMPTY_CELL, sizeof(char) * testCase.C * testCase.R);
	result.field[0] = CLICK;
	if (testCase.M == 0)
	{
		return;
	}

	if (testCase.R == 1 || testCase.C == 1)
	{
		int index = testCase.R * testCase.C - 1;
		for (int m = 0; m < testCase.M; m++)
		{
			result.field[index] = MINE;
			index--;
		}
		return;
	}
	if (testCase.R == 2 || testCase.C == 2)
	{
		int difference = testCase.C*testCase.R - testCase.M;
		if (difference == 2 || difference == 3)
		{
			result.isPossible = false;
			return;
		}
		else if(difference == 1)
		{
			for (int i=1; i < testCase.C*testCase.R; i++)
			{
				result.field[i] = MINE;
			}
			return;
		}

		if (testCase.M % 2 == 1)
		{
			result.isPossible = false;
			return;
		}

		placeMinesOn2xN(testCase, result);
		return;
	}
	else if (testCase.R > 2 && testCase.C > 2)
	{
		// Reduce the problem to 3x3
		int difference = testCase.C*testCase.R - testCase.M;
		if (difference == 2 || difference == 3 || difference == 5 || difference == 7)
		{
			result.isPossible = false;
			return;
		}
		int minesLeft = placeMinesOnBigField(testCase, result);
		// Only the 3x3 corner is left
		placeMinesOn3x3(result, minesLeft);
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