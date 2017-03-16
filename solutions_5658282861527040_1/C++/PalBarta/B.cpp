#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gmpxx.h"
typedef mpz_class bigint; 
using namespace std;

// PART I. - INPUT-OUTPUT STRUCTURES

class TestCase 
{
public:
	unsigned long long A, B, K;

	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> A >> B >> K;
	}
};

struct TestCaseResult
{
	unsigned long long result;
	TestCaseResult()
	{
		
	}

	void printResultToFile(ofstream& outputFile, int index)
	{
		outputFile << "Case #" << index + 1 << ": " << result; 
		
	}
};

// PART II. - PROBLEM SPECIFIC FUNCTIONS

bool comp (int i,int j) { return (i<j); }

void processTestCase(TestCase& t, TestCaseResult& r)
{
	unsigned long long A = t.A;
	unsigned long long B = t.B;
	unsigned long long K = t.K;
	unsigned long long all = A*B;
	unsigned long long agreater = K < A ? (A - K) : 0;
	unsigned long long bgreater = K < B ? (B - K) : 0;
	unsigned long long bothgreater = agreater*bgreater;

	if (bothgreater > 0)
	{
		r.result = all - bothgreater;
	}
	else
	{
		r.result = all;
		return;
	}
	/*
	unsigned long long Abinl, Bbinl, Kbinl;
	Abinl = Bbinl = Kbinl = 0;
	do
    {
        Abinl++;
    } while (A >>= 1);
	do
    {
        Bbinl++;
    } while (B >>= 1);
	do
    {
        Kbinl++;
    } while (K >>= 1);

	A = t.A;
	B = t.B;
	K = t.K;

	unsigned long long Ach = 1;
	unsigned long long Bch = 1;
	unsigned long long Kch = 1;
	for (unsigned long long  i=0; i < Abinl; i++)
    {
        Ach*=2;
    }
	for (unsigned long long  i=0; i < Bbinl; i++)
    {
        Bch*=2;
    }
	for (unsigned long long  i=0; i < Kbinl; i++)
    {
        Kch*=2;
    }*/

	//unsigned long long inc = 0;
	for (unsigned long long a = K;  a < A; a++)
	for (unsigned long long b = K; b < B; b++)
	{
		unsigned long long rr = a&b;
		if (rr < K)
		{
			r.result++;
			//inc++;
		}
	}

	/*long long aleft = (Abinl - Kbinl);
	long long bleft = (Bbinl - Kbinl);

	long long doubleones = min(aleft, bleft);

	if (doubleones <= 0)
		return;

	r.result += doubleones * (aleft-1)*(bleft-1)*inc;*/

}

// PART III. - BOILERPLATE CODE FOR INPUT-OUTPUT PROCESSING

class InputData
{
	vector<TestCase> testCases;

private:
	bool readInputFile(const string& inputFilePath);

public:
	InputData(const string& inputFilePath);
	
	int getNumberOfTestCases() { return testCases.size(); }
	TestCase& getTestCase(int index) { return testCases[index];}
};

class ResultData
{
	vector<TestCaseResult> testCaseResults;

public:
	
	bool writeOutputFile(const string& outputFilePath);
	void addResult(TestCaseResult result) { testCaseResults.push_back(result); }
	void addResult(int index, TestCaseResult result) { testCaseResults.insert(testCaseResults.begin() + index, result); }

};

bool ResultData::writeOutputFile(const string& outputFilePath)
{
	ofstream outputFile(outputFilePath);
	
	if (!outputFile.is_open())
		return false;

	for (unsigned int i=0; i < testCaseResults.size(); i++)
	{
		TestCaseResult testCaseResult = testCaseResults[i];
		testCaseResult.printResultToFile(outputFile, i);
		if (i != testCaseResults.size() - 1)
			outputFile << endl;
	}

	return true;
}

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

void processInputData(InputData& inputData, ResultData& resultData)
{
	int numberOfTestCases = inputData.getNumberOfTestCases();
	for (int testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
	{
		TestCase testCase = inputData.getTestCase(testCaseIndex);
		TestCaseResult result;
		cout << '\r' << "Test cases processed: " << testCaseIndex << "/" << numberOfTestCases;
		processTestCase(testCase, result);
		resultData.addResult(testCaseIndex, result);
	}
}

void main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc < 3)
	{
		cerr << "Incorrect parameters. Usage: application.exe <input file path> <output file path>" << endl;
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