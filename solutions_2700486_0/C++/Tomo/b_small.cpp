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

const int MAXN = 24;

double memo[MAXN][MAXN][MAXN][MAXN];
bool   done[MAXN][MAXN][MAXN][MAXN];
int    N, X, Y;

double f(int n, int left, int right, int level) {
  if (level > 0) {
    int w = 2*(level-1);
    if (abs(X) + abs(Y) <= w) return 1.0;
    if (abs(X) + abs(Y) <= 2*level) {
      if (X < 0 && Y < left)  return 1.0;
      if (X > 0 && Y < right) return 1.0;
    }
  }
  if (n == 0) return 0.0;
  if (done[n][left][right][level]) return memo[n][left][right][level];

  double& res = memo[n][left][right][level];
  res = 0.0;

  int w = 2*level;
  if (left == w && right == w) {
    res = f(n-1, 0, 0, level+1);
  } else if (left == w) {
    res = f(n-1, left, right+1, level);
  } else if (right == w) {
    res = f(n-1, left+1, right, level);
  } else {
    res = (f(n-1, left+1, right, level) + f(n-1, left, right+1, level)) / 2.0;
  }

  return done[n][left][right][level] = true, res;
}

int main() {
  int T; scanf("%d", &T);

  REP(tc, T) {
    scanf("%d%d%d", &N, &X, &Y);
    memset(done, 0, sizeof(done));
    printf("Case #%d: %.8lf\n", tc+1, f(N, 0, 0, 0)); fflush(stdout);
  }

  return EXIT_SUCCESS;
}
