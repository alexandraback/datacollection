
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

class TTestCase
{
private:
  string Result;
  int X, Y;

  struct S
  {
    char from;
    int l;
    S(): l(0){}
  };

  S F[201][201];

//  queue<pair<int, int> > Q;


  void Load();
  void Run();
  void Print();
  void Go(int l, int x, int y);
public:
  TTestCase();
  ~TTestCase();
};


TTestCase::TTestCase()
    //: Result(0)
{
  Load();

  Run();
}

void TTestCase::Load()
{
  cin >> X >> Y;
}

/*void TTestCase::Go(int l, int x, int y, char from)
{
/*  if(x < 0 || y < 0 || x > 201 || y > 201)
    return;
  if(F[x][y] > l)
  {
    F[x][y].l = l;
    F[x][y].from = from;
  }

  for(int a = 0; a<4; ++a)
  int r = rand() % 4;
  if(r == 0)
  {

  }* /

}*/

void TTestCase::Run()
{
//  Result = 0;

  Result.clear();
  Result.reserve(500);

  while(X > 0)
  {
    Result.push_back('W');
    Result.push_back('E');
    --X;
  }
  while(X < 0)
  {
    Result.push_back('E');
    Result.push_back('W');
    ++X;
  }
  while(Y > 0)
  {
    Result.push_back('S');
    Result.push_back('N');
    --Y;
  }
  while(Y < 0)
  {
    Result.push_back('N');
    Result.push_back('S');
    ++Y;
  }

}


TTestCase::~TTestCase()
{
  cout << Result.c_str() << endl;
  fsOut << Result.c_str() << endl;
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
