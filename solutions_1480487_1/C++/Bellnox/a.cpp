#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

int a[256];
int n, s;
int p[256];

int main() 
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++)
  {
    printf("Case #%d:", t + 1);
    cin >> n;
    s = 0;
    for(int i = 0; i < n; i++)
    {
      p[i] = i;
      cin >> a[i];
      s += a[i];
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = i + 1; j < n; j++)
      {
	if(a[p[i]] > a[p[j]])
	  swap(p[i], p[j]);
      }
    }
    int si = 0;
    int ind = 0;
    for(; ind < n; ind++)
    {
      si += a[p[ind]];
      if(ind == n - 1 || si + s <= a[p[ind + 1]] * (ind + 1))
	break;
    }
    double sv = (si + s + 0.0) / (ind + 1.0);
    for(int i = 0; i < n; i++)
    {
      bool m = 1;
      for(int j = 0; j <= ind; j++)
      {
	if(p[j] == i)
	  m = 0;
      }
      printf(" %.6lf", m ? 0 : 100.0 * (sv - a[i] + 0.0) / s);
    }
    printf("\n");
  }
  return 0;
}