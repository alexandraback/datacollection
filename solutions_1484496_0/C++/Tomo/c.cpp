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

const int MAXS = 10000000;
const int MAXN = 500;

vector<int> S[MAXS];
int         A[MAXN];
int         N;

inline bool same(int x, int y) {
  if (__builtin_popcount(x) != __builtin_popcount(y)) return false;
  vector<int> a, b;

  REP(i, N) if ((x >> i) & 1) a.push_back(A[i]);
  REP(i, N) if ((y >> i) & 1) b.push_back(A[i]);

  return a == b;
}

inline void pr(int x) {
  int L = __builtin_popcount(x);
  for (int i = 0, j = 0; i < N; ++i) {
    if (!((x >> i) & 1)) continue;
    printf("%d%s", A[i], ++j == L ? "" : " ");
  }
  printf("\n");
}

void solve() {
  REP(i, MAXS) S[i].clear();
  REP(s, 1 << N) {
    int sum = 0; REP(j, N) if ((s >> j) & 1) sum += A[j];
    S[sum].push_back(s);
  }

  int a = -1, b = -1;
  REP(i, MAXS) if (S[i].size() > 1) {
    int _a = S[i][0], _b = -1;
    REPS(j, 1, S[i].size()) {
      if (same(_a, S[i][j])) continue;
      _b = S[i][j]; break;
    }
    if (_b != -1) {
      a = _a; b = _b; break;
    }
  }

  if (a == -1 && b == -1) printf("Impossible\n"); else pr(a), pr(b);
}

int main() {
  int T; scanf("%d", &T);
  REP(tc, T) {
    scanf("%d", &N); REP(i, N) scanf("%d", &A[i]);
    printf("Case #%d:\n", tc+1); solve(); fflush(stdout);
  }
  return EXIT_SUCCESS;
}
