
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <deque>
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
private:
    deque<char> Result;

    string S;

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
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
    for (char c : S)
    {
        if (Result.size() == 0)
            Result.push_back(c);
        else {
            if (c >= Result[0]) {
                Result.push_front(c);
            }
            else
                Result.push_back(c);
        }
    }
}


TTestCase::~TTestCase()
{
    for (char c : Result) {
        cout << c;
        fsOut << c;
    }
    cout << endl;
    fsOut << endl;
}

void TTestCase::Print()
{
#ifndef PRINT
    return;
#endif
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
