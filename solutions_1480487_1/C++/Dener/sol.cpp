#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

const double eps = 1e-8;
vector< double > p;
int n;
double X;

const int iterCount = 300;

inline bool canStay(int i, double percent)
{
  double ostpercent = 1.0 - percent;
  double lim = p[i] + X*percent;
  
  for (int j = 0; j < n; j++)
  {
    if (i == j)
      continue;
    
    double need = max(0.0, (lim - p[j]) / X);
    
    if (need > ostpercent + eps)
      return true;
    ostpercent -= need;
  }
  
  return false;
}

inline void solve(int testnumber)
{
  X = 0;
  scanf("%d", &n);
  p.resize(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &p[i]);
    X += p[i];
  }
  
  cout.precision(30);
  cout.setf(ios::fixed);
  printf("Case #%d: ", testnumber+1);
  
  for (int i = 0; i < n; i++)
  {
    if (canStay(i, 0))
    {
      printf("0 ");
      continue;
    }
    
    double l = 0;
    double r = 1;
    for (int q = 0; q < iterCount; q++)
    {
      double m = (l+r)/2;
      
      if (canStay(i, m))
	r = m;
      else
	l = m;
    }
    
    cout << (l+r)*50 << ' ';
  }
  printf("\n");
};

int main()
{
  int testcount;
  scanf("%d\n", &testcount);
  
  for (int i = 0; i < testcount; i++)
  {
    solve(i);
  }
}