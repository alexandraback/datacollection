#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)
#define AUTO(v,e) __typeof__(e) v = (e)
#define FOR(it,c) for(AUTO (it,(c).begin()); (it) != (c).end(); ++(it))

int l[123][123];

bool
solve (int n, int m)
{
  for (;;)
    {
      int imin, jmin, min = 128;
      REP (i, n) REP (j, m)
        {
          if (l[i][j] >= 0 && l[i][j] < min)
            min = l[i][j], jmin = j, imin = i;
        }
      if (min > 100) return true;
      REP (i, n)
        if (l[i][jmin] >= 0 && l[i][jmin] != min)
          goto fill_row;
      REP (i, n)
        l[i][jmin] = -1;
      continue;
    fill_row:
      REP (j, m)
        if (l[imin][j] >= 0 && l[imin][j] != min)
          return false;
      REP (j, m)
        l[imin][j] = -1;
    }
}

int
main ()
{
  int t;
  scanf ("%d", &t);
  REP (k, t)
    {
      int n, m;
      scanf ("%d%d", &n, &m);
      REP (i, n) REP (j, m) scanf ("%d", &l[i][j]);
      printf ("Case #%d: %s\n", k + 1, solve (n, m) ? "YES" : "NO");
    }
}
