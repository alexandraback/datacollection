
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "B"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    double Result;
    double C, F, X;

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
    cin >> C >> F >> X;
}

double Simple(double speed, double amount)
{
	return amount / speed;
}

double Construct(double speed, double cost)
{
	return cost / speed;
}

void TTestCase::Run()
{
	double prev = 0;
	Result = Simple(2, X);
	double speed = 2;

	for(;;)
	{
		double new_result = prev + Construct(speed, C) + Simple(speed + F, X);
		if(new_result < Result)
		{
			Result = new_result;
			prev += Construct(speed, C);
			speed += F;
		}
		else
		{
			break;
		}
	}
}


TTestCase::~TTestCase()
{
	cout << std::setprecision(9);
	fsOut << std::setprecision(9);

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
