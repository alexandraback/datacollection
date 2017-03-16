#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned long long ull;

ull n;
ull visited[10000100];


void solve()
{
  scanf("%llu", &n);
  for (int i=0; i<=n; ++i) visited[i] = i;
  for (int i=1; i<=n; ++i)
  {
    visited[i] = min(visited[i], 1+visited[i-1]);
    int tmp = i;
    int rev = 0;
    while(tmp)
    {
      rev *= 10;
      rev += tmp%10;
      tmp/=10;
    }
    if (rev > i && visited[rev] > 1+visited[i]) visited[rev] = 1+visited[i];
  }
  printf("%llu", visited[n]);
  return;
}

int main()
{
  int C;
  cin >> C;
  for (int i=1; i<=C; ++i)
  {

    printf("Case #%d: ", i);
    solve();
    printf("\n");    
  }
  return 0;
}
