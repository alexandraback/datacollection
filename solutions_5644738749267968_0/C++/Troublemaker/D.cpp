
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "D"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    int Result[2];
    unsigned N;
	vector<double> s1, s2;

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
    cin >> N;
	s1.resize(N);
	s2.resize(N);
	FOR(i,0,N)
		cin >> s1[i];
	FOR(i,0,N)
		cin >> s2[i];
}

void TTestCase::Run()
{
	Result[0] = Result[1] = 0;
	sort(s1.begin(), s1.end(), greater<double>());
	sort(s2.begin(), s2.end(), greater<double>());

	{
		deque<double> d1(s1.begin(), s1.end());
		deque<double> d2(s2.begin(), s2.end());

		FOR(i,0,N)
		{
			if(d1.front() > d2.front())
			{
				++Result[1];
				d1.pop_front();
				d2.pop_back();
			}
			else
			{
				d1.pop_front();
				d2.pop_front();
			}
		}
	}

	{
		deque<double> d1(s1.begin(), s1.end());
		deque<double> d2(s2.begin(), s2.end());

		FOR(i,0,N)
		{
			if(d1.back() > d2.back())
			{
				++Result[0];
				d1.pop_back();
				d2.pop_back();
			}
			else
			{
				d1.pop_back();
				d2.pop_front();
			}
		}
	}
}


TTestCase::~TTestCase()
{
    cout << Result[0] << " " << Result[1] << endl;
    fsOut << Result[0] << " " << Result[1] << endl;
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
