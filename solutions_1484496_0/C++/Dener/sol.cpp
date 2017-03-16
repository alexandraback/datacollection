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

vector< long long > chis;
int n;

map< long long, int > getMask;

inline int getBit(int mask, int i)
{
  return (mask>>i)&1;
}

inline void solve(int testnumber)
{
  printf("Case #%d:\n", testnumber+1);
  getMask.clear();
  scanf("%d", &n);
  chis.resize(n);
  for (int i = 0;i < n; i++)
    cin >> chis[i];
  
  for (int mask = 1; mask < (1<<n); mask++)
  {
    long long cursum = 0;
    for (int i = 0; i < n; i++)
      if (getBit(mask, i))
	cursum += chis[i];
      
    if (getMask.find(cursum) != getMask.end())
    {
      int secmask = getMask[cursum];
      
      for (int i = 0; i < n; i++)
	if (getBit(mask, i))
	  printf("%d ", chis[i]);
      printf("\n");
      for (int i = 0; i < n; i++)
	if (getBit(secmask, i))
	  printf("%d ", chis[i]);
      printf("\n");
      
      return;
    }
    else
      getMask[cursum] = mask;
  }
  printf("Impossible\n");
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