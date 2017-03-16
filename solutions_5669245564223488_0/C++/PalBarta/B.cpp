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
	int N;
	vector<string> s;

	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> N;

		string car;
		getline(inputFile, car);

		for (int i=0; i < N; i++)
		{
			inputFile >> car;
			s.push_back(car);
		}

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

unsigned long long factorial(unsigned int n)
{
    unsigned long long ret = 1;
    for(unsigned int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

void processTestCase(TestCase& t, TestCaseResult& r)
{
	int in[256];
	memset(in, 0, 256*sizeof(int));
	int out[256];
	memset(out, 0, 256*sizeof(int));
	int samebe[256];
	memset(samebe, 0, 256*sizeof(int));

	int inIndex[256];
	memset(inIndex, -1, 256*sizeof(int));
	int outIndex[256];
	memset(outIndex, -1, 256*sizeof(int));
	int usedInSet[256];
	memset(usedInSet, -1, 256*sizeof(int));

	vector<string> notsamebe;
	for (int i = 0; i < t.s.size(); i++)
	{
		string car = t.s[i];
		char firstc = *car.begin();
		char lastc = *(car.end()-1);
		bool checklast = false;
		for (int ci = 0; ci < car.length(); ci++)
		{
			if (!checklast)
			{
				if (car[ci] != firstc)
				{
					if (car[ci] == lastc)
						checklast = true;
					else
					{
						r.result = 0;
						return;
					}
				}
			}
			if (checklast && car[ci] != lastc)
			{
				r.result = 0;
				return;
			}
		}
		
		if (firstc == lastc)
		{
			samebe[firstc]++;
		}
		else
		{
			in[firstc]++;
			out[lastc]++;
			
			string w;
			w += firstc;
			w += lastc;

			notsamebe.push_back(w);
			inIndex[firstc] = notsamebe.size() - 1;
			outIndex[lastc] = notsamebe.size() - 1;
		}
	}

	for (int i=0; i < 256; i++)
	{
		if (in[i] > 1 || out[i] > 1)
		{
			r.result = 0;
			return;
		}
	}

	unsigned int setNum = 0;

	string currSet = "";

	bool run = true;
	if (notsamebe.size() == 0)
	{
		setNum = 0;
		run = false;
	}
	else
	{
		currSet = notsamebe[0];
		notsamebe[0] = "";
	}

	if (notsamebe.size() == 1)
	{
		setNum = 1;
		run = false;
	}
	
	
	while(run)
	{
		bool found = true;
		while (found)
		{
			char wfc = currSet[0];
			char wlc = currSet[1];

			usedInSet[wfc] = usedInSet[wlc] = 1;

			if (inIndex[wlc] == -1 && outIndex[wfc] == -1)
			{
				found = false;
			}

			if (inIndex[wlc] != -1)
			{
				currSet[1] = notsamebe[inIndex[wlc]][1];
				notsamebe[inIndex[wlc]] = "";
			}
		

			if (outIndex[wfc] != -1)
			{
				currSet[0] = notsamebe[outIndex[wfc]][0];
				notsamebe[outIndex[wfc]] = "";
			}
		}
		setNum++;
		run = false;
		for (int i = 0; i < notsamebe.size(); i++)
		{
			if (notsamebe[i] != "")
			{
				currSet = notsamebe[i];
				run = true;
			}
		}
	}

	const long long m = 1000000007;

	r.result = 1;

	for (int i = 0; i < 256; i++)
	{
		if (samebe[i] != 0)
		{
			r.result *= factorial(samebe[i]);

			if (usedInSet[i] == 1)
			{
				setNum++;
			}
		}
	}

	r.result *= factorial(setNum);

	r.result = r.result%m;
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