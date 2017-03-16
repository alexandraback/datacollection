#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "A"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
public:
private:
	int Result;
	int Smax;
	string S;

	void Load();
	void Run();


	void Print();
public:
	TTestCase();
	~TTestCase();
};


void TTestCase::Run()
{
	Result = 0;
	int count = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		if (count < i)
		{
			Result += i - count;
			count = i;
		}
		count += S[i] - '0';
	}
}






void TTestCase::Print()
{
#ifndef PRINT
	return;
#endif
}

TTestCase::TTestCase()
	: Result(0)
{
	Load();
	Run();
}

void TTestCase::Load()
{
	cin >> Smax;
	cin >> S;
}

TTestCase::~TTestCase()
{
	cout << Result << endl;
	fsOut << Result << endl;
}

int main()
{
	if (!fsIn.is_open())
	{
		cout << "No input file found";
	}
	cin.rdbuf(fsIn.rdbuf());

	int numberOfCases;
	cin >> numberOfCases;

	for (int caseNum = 1; caseNum <= numberOfCases; ++caseNum)
	{
		TTestCase testCase;


		cout << "Case #" << caseNum << ": ";
		fsOut << "Case #" << caseNum << ": ";
	}

	cout << "Finished";
	for (;;);
	return 0;
}
