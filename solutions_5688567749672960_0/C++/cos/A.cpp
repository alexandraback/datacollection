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
    // puts("");
    solve();
  }
}

ll calcDigit(ll n) {
  if (n == 0) { return 1; }
  ll v = 0;
  while (n > 0) {
    v++;
    n /= 10;
  }
  return v;
}

ll upDigit(ll d) {
  if (d == 1) { return 10; }
  ll hd1 = (d + 1) / 2;
  ll sum1 = 0;
  while (hd1 > 0) {
    sum1 = sum1 * 10 + 9;
    hd1--;
  }
  ll hd2 = d / 2;
  ll sum2 = 0;
  while (hd2 > 0) {
    sum2 = sum2 * 10 + 9;
    hd2--;
  }
  return sum1 + sum2 + 1;
}

ll calc(ll n) {
  vector<ll> seq;
  ll m = n;
  ll digit_sum = 0;
  while (m > 0) {
    seq.push_back(m % 10);
    digit_sum += m % 10;
    m /= 10;
  }
  if (digit_sum == 1) { return 0; }
  ll sum1 = 0;
  ll d1 = 1;
  reverse(seq.begin(), seq.end());
  REP(i, seq.size() / 2) {
    sum1 += seq[i] * d1;
    d1 *= 10;
  }
  if (sum1 == 1) { sum1 = 0; }

  ll sum2 = 0;
  ll d2 = 1;
  reverse(seq.begin(), seq.end());
  REP(i, (seq.size() + 1) / 2) {
    sum2 += seq[i] * d2;
    d2 *= 10;
  }
  if (sum2 == 0) {
    return calc(n - 1) + 1;
  }
  // cout << sum1 << " " << sum2 << endl;
  return sum1 + sum2;
}

void solve() {
  ll n;
  scanf("%lld", &n);
  ll ans = 0;
  if (n <= 19) { ans = n; goto end; }
  {
    ll target_digit = calcDigit(n);
    ll digit = 1;
    while (digit != target_digit) {
      ans += upDigit(digit);
      digit++;
    }
    ans += calc(n);
  }
end:
  printf("%lld\n", ans);
}
