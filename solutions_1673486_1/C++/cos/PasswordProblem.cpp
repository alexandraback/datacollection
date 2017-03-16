#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const long double EPS = 1e-9;
static const long double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

long double seq[100100];
long double p[100010];
long double sum[100010];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) {
    scanf("%Lf", &seq[i]);
  }
  seq[n] = 1.0;
  p[0] = (1.0 - seq[0]);
  sum[0] = 0.0;
  REP(i, n) {
    p[i + 1] = (1.0 - p[i]) * (1.0 - seq[i + 1]);
    sum[i + 1] = sum[i] + p[i];
  }
  long double fail = m + 1;
  sum[n + 1] = sum[n] + p[n];
  long double ans = 2 + m;
  ans = min(ans, 1.0 * (m - n + 1) + (1.0 - p[n]) * fail);
  FOREQ(back, 0, n) {
    long double lans = 0.0;
    long double ng = sum[back];
    lans = 1.0 * (n - back + m - back + 1) + ng * fail;
    ans = min(ans, lans);
  }
  printf("%.8Lf\n", ans);
}
