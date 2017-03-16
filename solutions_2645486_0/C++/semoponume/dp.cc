#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)
#define AUTO(v,e) __typeof__(e) v = (e)
#define FOR(it,c) for(AUTO (it,(c).begin()); (it) != (c).end(); ++(it))

typedef long long ll;

int v[12345];
int a[12345][12];
int E, R, N;

int
solve (int i, int e)
{
  if (i == N) return 0;
  assert (e >= 0);
  if (a[i][e] < 0)
    {
      REP (ep, e + 1)
        {
          a[i][e]
            = max (a[i][e], v[i] * ep + solve (i + 1, min (E, e - ep + R)));
        }
    }
  return a[i][e];
}

int
main ()
{
  int t;
  cin >> t;
  REP (k, t)
    {
      cin >> E >> R >> N;
      REP (i, N) cin >> v[i];
      memset (a, 255, sizeof a);
      printf ("Case #%d: %d\n", k + 1, solve (0, E));
    }
}
