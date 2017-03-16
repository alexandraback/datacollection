
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>
#include <iomanip>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "B"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

__int64 Fact[20];

__int64 F(int i)
{
  if(i == 0)
    return 1;
  if(Fact[i] != 0)
    return Fact[i];
  return i * F(i-1);
}

__int64 C(int n, int k)
{
  __int64 res = 1;
  for(int i=n; i>k; --i)
  {
    res *= i;
  }
  res /= F(n-k);
  return res;
}

class TTestCase
{
private:
  double Result;
  unsigned N, X, Y;


  void Load();
  void Run();
  void Print();
public:
  TTestCase();
  ~TTestCase();
};


TTestCase::TTestCase()
    : Result(0)
{
  Load();

  Run();
}

void TTestCase::Load()
{
  cin >> N >> X >> Y;
}

void TTestCase::Run()
{
  Result = 0;

  int I = ceil((1+sqrt(1.+8*N))/4) - 1;
  int I1 = (X + Y)/2;
  if(I1 > I)
  {
    Result = 0;
    return;
  }
  if(I1 < I)
  {
    Result = 1;
    return;
  }

  if(X == 0)
  {
    if( ceil((1+sqrt(1.+8*(N+1)))/4) - 1 > I)
    {
      Result = 1;
      return;
    }
    Result = 0;
    return;
  }
  int Height = Y + 1;
  int a = I;
  int n = a*2-1;
  int Attempts = N - (1+n)*n/2;
  if(Attempts >= I+1+Height)
  {
    Result = 1;
    return;
  }

  if(Attempts <= I+1)
  {
    __int64 denom = 1;
    denom <<= Attempts;

    double q=0;
    for(int i=Height; i<=Attempts; ++i)
    {
      q += C(Attempts, i);
    }

    Result = q/(double)denom;
  }
  else
  {
    int Attempts1 = Attempts - (I+1);
    __int64 denom = 1;
    denom <<= Attempts1;

    Height -= (Attempts - (I+1));

    double q=0;
    for(int i=Height; i<=Attempts1; ++i)
    {
      q += C(Attempts1, i);
    }

    Result = q/(double)denom;
  }
}


TTestCase::~TTestCase()
{
  cout.precision(6);
  fsOut.precision(6);
  //cout.fixed(1);
  cout << std::fixed << setprecision(6) << Result << endl;
  fsOut << std::fixed << setprecision(6) << Result << endl;
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

  for(int i=0; i<20; ++i)
    Fact[i] = 0;

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
