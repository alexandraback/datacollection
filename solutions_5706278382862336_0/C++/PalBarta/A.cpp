#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gmpxx.h"
#include <math.h>
typedef mpz_class bigint; 
using namespace std;

// PART I. - INPUT-OUTPUT STRUCTURES

class TestCase 
{
public:
	long long P;
	long long Q;
	
	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> P;
		char c;
		inputFile.read(&c, 1);
		inputFile >> Q;
	}
};

struct TestCaseResult
{
	int result;
	TestCaseResult()
	{
		
	}

	void printResultToFile(ofstream& outputFile, int index)
	{
		outputFile << "Case #" << index + 1 << ": "; 
		
		if (result == -1)
			outputFile << "impossible";
		else
			outputFile << result;
	}
};

// PART II. - PROBLEM SPECIFIC FUNCTIONS

bool comp (int i,int j) { return (i<j); }

bool log2int (long long x, long long& p)
{
	p = 0;
	while (((x % 2) == 0) && x > 1)
	{
		x /= 2;
		p++;
	}

	return (x == 1);
}

long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; 
	 a = b%a;  
	 b = c;
  }
  return b;
}

void processTestCase(TestCase& t, TestCaseResult& r)
{
	long long gc = gcd(t.P, t.Q);

	if (gc != 1)
	{
		t.P = t.P / gc;
		t.Q = t.Q / gc;
	}

	long long p;
	if ( !log2int(t.Q, p) )
	{
		r.result = -1;
		return;
	}
	else
	{
		long long anc = 1;
		while (t.P < t.Q / 2)
		{
			t.Q = t.Q / 2;
			anc++;
		}
		r.result = anc;
	}
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