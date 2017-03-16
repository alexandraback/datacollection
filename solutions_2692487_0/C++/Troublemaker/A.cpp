
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
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
  int Result;
  unsigned A, N;
  vector<int> M;
  vector<int> R;

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
  cin >> A >> N;
  M.resize(N);
  for(int i=0; i<N; ++i)
  {
    cin >> M[i];
  }
}

void TTestCase::Run()
{
  Result = 0;
  if(A == 1)
  {
    Result = N;
    return;
  }
  R.resize(N);

  sort(M.begin(), M.end());
  for(int i=0; i<N; ++i)
  {
    while(1)
    {
      if(A > M[i])
      {
        A += M[i];
        break;
      }
      else
      {
        ++Result;
        A += A-1;
      }
    }
    R[i] = Result + N - i - 1;
  }
  Result = N;
  for(int i=0; i<N; ++i)
  {
    if(R[i] < Result)
      Result = R[i];
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
