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

const long double EPS = 1e-12;
const int MAXN   = 200;
const int NITER  = 100;

int S[MAXN];
int N, X;

bool ok(int i, long double p) {
  long double score = S[i] + X * p;
  long double P = p;

  REP(j, N) if (j != i)
    P += max((long double)0.0, (score - S[j]) / X);

  return P - 1.0 > -EPS;
}

int main() {
  int T; scanf("%d", &T);
  REP(tc, T) {
    scanf("%d", &N); X = 0; 
    REP(i, N) scanf("%d", &S[i]), X += S[i];

    printf("Case #%d:", tc+1);
    REP(i, N) {
      long double lo = 0, hi = 1;
      REP(_, NITER) {
        long double mid = (lo + hi) / 2.0;
        if (ok(i, mid)) hi = mid; else lo = mid;
      }

      printf(" %.8Lf", lo * 100.0);
    }
    printf("\n"); fflush(stdout);
  }

  return EXIT_SUCCESS;
}
