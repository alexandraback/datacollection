#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "InputData.h"

InputData::InputData(const string& inputFilePath)
{
	readInputFile(inputFilePath);
}

bool InputData::readInputFile(const string& inputFilePath)
{
	ifstream inputFile(inputFilePath);

	if (!inputFile.is_open())
		return false;

	string line;
	getline(inputFile, line);
	istringstream inputStringStream(line);
	int numOfTestCases = 0;
	inputStringStream >> numOfTestCases;

	for (int i = 0; i < numOfTestCases; i++)
	{
		TestCase testCase;
		testCase.readData(inputFile);
		testCases.push_back(testCase); 
	}

	return true;
}


TestCase::TestCase()
{

}

TestCase::~TestCase()
{

}

bool sortFunction (double i,double j) { return (i<j); }

void TestCase::readData(ifstream& inputFile)
{
	inputFile >> N;
	for (int i=0; i < N; i++)
	{
		double w;
		inputFile >> w;
		naomiBlocks.push_back(w);
	}
	for (int i=0; i < N; i++)
	{
		double w;
		inputFile >> w;
		kenBlocks.push_back(w);
	}

	sort(naomiBlocks.begin(), naomiBlocks.end(), sortFunction);
	sort(kenBlocks.begin(), kenBlocks.end(), sortFunction);
}