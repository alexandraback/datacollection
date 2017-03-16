#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdint>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "B"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
public:
private:
	int Result;
	int D;
	vector<int> P;
    int Pmax;

	void Load();
	void Run();
	void Print();
public:
	TTestCase();
	~TTestCase();
};


void TTestCase::Run()
{
    Result = Pmax;
    for (auto p = 1; p < Pmax; ++p)
    {
        int rec = p;
        for (auto i = 0; i < P.size(); ++i)
        {
            rec += (P[i] - 1)/p;
        }
        Result = min(Result, rec);
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
	cin >> D;
	P.resize(D);
    Pmax = 0;
    for (auto i = 0; i < D; ++i)
    {
        cin >> P[i];
        Pmax = max(P[i], Pmax);
    }
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
