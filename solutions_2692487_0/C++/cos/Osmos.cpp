#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

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

ll a , n;
ll seq[10000];
void solve() {
  scanf("%lld %lld", &a, &n);
  REP(i, n) { scanf("%lld", &seq[i]); }
  sort(seq, seq + n);
  ll ans = n;
  if (a != 1) {
    ll use = 0;
    REP(i, n) {
      ans = min(ans, use + (n - i));
      while (a <= seq[i]) { a += a - 1; use++; }
      a += seq[i];
    }
    ans = min(ans, use);
  }
  printf("%lld\n", ans);
}
