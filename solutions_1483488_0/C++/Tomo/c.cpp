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

const int D[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

static inline int digits(int x) {
  int res = 0;
  while (x > 0) ++res, x /= 10;
  return res;
}

int count_recycled(int a, int b) {
  int res = 0;

  REPS(x, a, b+1) {
    int y = x, L = digits(x) - 1;
    set<int> seen;
    REP(i, L) {
      int d = y % 10; y /= 10; y += D[L] * d;
      if (y > x && y <= b && seen.find(y) == seen.end())
        ++res, seen.insert(y);
    }
  }

  return res;
}

int main() {
  int T; scanf("%d", &T);
  REP(tc, T) {
    int A, B; scanf("%d%d", &A, &B);
    printf("Case #%d: %d\n", tc+1, count_recycled(A, B));
    fflush(stdout);
  }
  return EXIT_SUCCESS;
}
