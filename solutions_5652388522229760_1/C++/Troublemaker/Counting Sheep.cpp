
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define PRINT

#define TASKNUM "A"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    long long Result;
    unsigned N;

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
    cin >> N;
}

void TTestCase::Run()
{
    if (N == 0) {
        Result = 0;
        return;
    }
    set<int> s;
    for(long long i = 1; ; ++i) {
        Result = N * i;
        long long tmp = Result;
        while (tmp) {
            s.insert(tmp % 10);
            tmp /= 10;
        }
        if(s.size() == 10)
            break;
    }

}


TTestCase::~TTestCase()
{
	if(Result == 0)
	{
		cout << "INSOMNIA" << endl;
		fsOut << "INSOMNIA" << endl;
	}
	else
	{
		cout << Result << endl;
		fsOut << Result << endl;

	}
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
