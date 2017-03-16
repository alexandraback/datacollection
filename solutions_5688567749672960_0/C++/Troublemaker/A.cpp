
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdint.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "A"
//#define DATASET "practice"
//#define CHECK_RESULTS
#define DATASET "small"
//#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET ".in.txt");
ofstream fsOut(TASKNUM "-" DATASET ".out.txt");

class TTestCase
{
private:
    long long N;
    long long y;

#ifdef CHECK_RESULTS
    int check_y;
#endif

    void Load();
    void Init();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
{
    Load();
    Init();
    Run();
}



void TTestCase::Run()
{
   vector<long long> d;
   d.resize(N+1);
   fill(d.begin(), d.end(), N);
   d[1] = 1;

   for(long long i = 1; i < N; ++i)
   {
      d[i + 1] = min(d[i + 1], d[i] + 1);
      long long inv = 0;
      long long ii = i;
      while(ii != 0)
      {
         inv *= 10;
         inv += ii % 10;
         ii /= 10;
      }
      if(inv <= N)
         d[inv] = min(d[inv], d[i] + 1);
   }
   y = d[N];
}

void TTestCase::Load()
{
    cin >> N;
#ifdef CHECK_RESULTS
    cin >> check_y;
#endif
}

void TTestCase::Init()
{
}

TTestCase::~TTestCase()
{
//    cout << std::fixed << std::setprecision(10) << X << endl;
//    fsOut << std::fixed << std::setprecision(10) << X << endl;
    cout << y;
#ifdef CHECK_RESULTS
    cout << "  " << check_y;
#endif
    cout << endl;
    fsOut << y;
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
