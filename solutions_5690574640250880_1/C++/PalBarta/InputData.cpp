#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void TestCase::readData(ifstream& inputFile)
{
	inputFile >> R >> C >> M;
}