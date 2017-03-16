
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
#define DATASET "practice"
//#define DATASET "small"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET ".in.txt");
ofstream fsOut(TASKNUM "-" DATASET ".out.txt");

class TTestCase
{
private:
    int R, C, W;
    int y;


    void Load();
    void Init();
    void Run();
public:
    TTestCase();
    ~TTestCase();
};



int solve(int c, int w)
{
   if(c % w == 0)
      return c / w + w-1;
   return c / w + w;
}

void TTestCase::Run()
{
   y = solve(C, W) + (R-1) * (C/W);
}











void TTestCase::Load()
{
    cin >> R >> C >> W;
}

void TTestCase::Init()
{
}

TTestCase::~TTestCase()
{
//    cout << std::fixed << std::setprecision(10) << X << endl;
//    fsOut << std::fixed << std::setprecision(10) << X << endl;
    cout << y << endl;
    fsOut << y << endl;

}

TTestCase::TTestCase()
{
    Load();
    Init();
    Run();
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
