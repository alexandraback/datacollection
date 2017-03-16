#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

#define REP(i, n)      for (int (i) = 0, __n = (int)(n); (i) < __n; ++(i))
#define REPS(i, s, n)  for (int (i) = (s), __n = (int)(n); (i) < __n; ++(i))
#define REPD(i, n)     for (int (i) = (n); (i) >= 0; --(i))
#define FOREACH(i, x)  for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define SIZE(x)        (int)((x).size())

int main() {
  int T; scanf("%d", &T);

  REP(tc, T) {
    int N, S, P, ok = 0, surprising = 0;
    scanf("%d%d%d", &N, &S, &P);

    REP(i, N) {
      int x; scanf("%d", &x); x -= P;
      if (x < 0) continue;
      if (x >= 2 * max(0, P-1)) ++ok; else if (x >= 2 * max(0, P-2)) ++surprising;
    }

    printf("Case #%d: %d\n", tc+1, ok + min(surprising, S));
  }

  return EXIT_SUCCESS;
}
