
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#define PRINT

#define TASKNUM "B"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    int Result;
    string S;

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
    : Result(-1)
{
	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> S;
}

void TTestCase::Run()
{
    S.push_back('+');
    Result = 0;
    for(int i = 0; i < S.size() - 1; ++i) {
        if(S[i] != S[i+1])
            ++Result;
    }
}


TTestCase::~TTestCase()
{
	cout << Result << endl;
	fsOut << Result << endl;
}

void TTestCase::Print()
{
#ifndef PRINT
    return;
#endif
}








int main()
{
    if(!fsIn.is_open())
    {
        cout << "No input file found";
    }
    cin.rdbuf( fsIn.rdbuf() );

    int numberOfCases;
    cin >> numberOfCases;

	for( int caseNum = 1; caseNum <= numberOfCases; ++caseNum )
	{
        TTestCase testCase;

        
        cout << "Case #" << caseNum << ": ";
        fsOut << "Case #" << caseNum << ": ";
	}
	
	cout << "Finished";
    for(;;);
	return 0;
}
