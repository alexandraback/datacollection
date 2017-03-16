
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
  int n, L;
  string Name;

  struct D
  {
    int left, right, l;
  };

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
  string s;
  while(s.empty())
  {
    getline(cin, s);
  }
  int pos = s.find(' ');
  Name = s.substr(0, pos);
  s = s.substr(pos + 1, string::npos);
  stringstream ss(s, ios_base::in);
  ss >> n;
//  cin >> n;
}

bool Cons(char c)
{
  switch(c)
  {
  case 'a':case 'e':case 'i':case 'o':case 'u':
    return false;
  }
  return true;
}

void TTestCase::Run()
{
  Result = 0;
  vector<D> data;

  D d;
  d.l = d.left = d.right = 0;

  for(int i=0; i<Name.size(); ++i)
  {
    if(Cons(Name[i]))
    {
      ++d.l;
    }
    else
    {
      d.l = 0;
    }

    if(d.l == n)
    {
      d.left = i + 1 - n;
      data.push_back(d);
      --d.l;
    }
  }
  for(int i=0; i<data.size(); ++i)
  {
    data[i].right = Name.size() - data[i].left - data[i].l;
  }

  int m = 0;
  for(int i=0; i<data.size(); ++i)
  {
//    if(data[i].l >= n)
    {
      int temp = data[i].left;
      data[i].left -= m;
      m = temp + 1;
    }
  }








  for(int i=0; i<data.size(); ++i)
  {
    if(data[i].l >= n)
    {
      Result += (data[i].left + 1) * (data[i].right + 1);
    }
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
