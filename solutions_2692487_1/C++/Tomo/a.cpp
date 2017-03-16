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

const int MAXN = 128;

int x[MAXN];

int main() {
  int T; scanf("%d", &T);

  REP(tc, T) {
    int A, N; scanf("%d%d", &A, &N);
    REP(i, N) scanf("%d", &x[i]);
    sort(x, x+N);

    int res = N, cur = 0;
    try {
      REP(i, N) {
        while (A <= x[i]) {
          if (A == 1) throw 42;
          ++cur; A = 2*A - 1;
        }

        A += x[i];
        res = min(res, cur + (N-i-1));
      }
    } catch (...) {}

    printf("Case #%d: %d\n", tc+1, res);
    fflush(stdout);
  }

  return EXIT_SUCCESS;
}
