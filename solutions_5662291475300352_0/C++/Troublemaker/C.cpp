
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

#define TASKNUM "C"
//#define DATASET "practice"
//#define CHECK_RESULTS
#define DATASET "small"
//#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET ".in.txt");
ofstream fsOut(TASKNUM "-" DATASET ".out.txt");

struct S
{
   int D;
   int H;
   int M;
};

class TTestCase
{
private:
    int N;
    vector<S> h;
    int summH;
    
    int y;


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









struct HIKER
{
   int R;
   int M;
   double T;
};


bool neq(double a, double b)
{
   return a != b;
}

void TTestCase::Run()
{
   y = summH;

   vector<HIKER> hikers(summH);
   for(int i = 0, j = 0, k = 0; i < summH; ++i)
   {
      hikers[i].R = 0;
      hikers[i].M = h[j].M + k;
      hikers[i].T = (360. - h[j].D)/360. * hikers[i].M;
      ++k;
      if(k == h[j].H)
      {
         ++j;
         k = 0;
      }
   }

   sort(hikers.begin(), hikers.end(), [](HIKER &h1, HIKER & h2){return h1.T < h2.T; });
   if(hikers[0].T + hikers[0].M > hikers[1].T)
      y = 0;
   else
      y = 1;
   return;




   int passes = 0;
   do
   {
      int score = y;

      sort(hikers.begin(), hikers.end(), [](HIKER &h1, HIKER & h2){return h1.T < h2.T; });

      score += hikers[0].R;
      hikers[0].R = 0;
      int j;
      for(j = 1; j < summH; ++j)
      {
         if(neq(hikers[j].T, hikers[0].T))
            break;
         score += hikers[j].R;
         hikers[j].R = 0;
      }
      score -= j;

      for(int i = 0; i < j; ++i)
      {
         hikers[i].T += hikers[i].M;
         ++hikers[i].R;
         ++passes;
      }

      if(score < y)
      {
         y = score;
      }
      else
      {
         break;
      }
   } while(1);

}

void TTestCase::Load()
{
   cin >> N;
   h.resize(N);
   summH = 0;
   for(int i=0; i<N; ++i)
   {
      cin >> h[i].D >> h[i].H >> h[i].M;
      summH += h[i].H;
   }
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
