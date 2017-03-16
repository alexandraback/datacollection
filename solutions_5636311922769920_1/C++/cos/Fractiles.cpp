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
    // puts("");
    solve();
  }
}

ll k, c, s;
void solve() {
  scanf("%lld %lld %lld", &k, &c, &s);
  if ((k + (c - 1)) / c > s) {
    puts("IMPOSSIBLE");
    return;
  }
  vector<ll> ans;
  ll target = 0;
  while (target < k) {
    ll pos = 0;
    REP(i, c) {
      ll offset = target < k ? target : 0;
      pos = pos * k + offset;
      target++;
    }
    ans.push_back(pos);
  }
  REP(i, ans.size()) {
    if (i != 0) { putchar(' '); }
    printf("%lld", ans[i] + 1);
  }
  puts("");
}
