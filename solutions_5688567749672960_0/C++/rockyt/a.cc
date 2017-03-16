#include <bits/stdc++.h>
#define N 10000001
typedef long long ll;

inline
ll rev(ll v) {
  ll ans = 0;
  while (v) {
    ans = ans * 10 + v % 10;
    v /= 10;
  }
  return ans;
}

inline
ll solve(ll n) {
  ll ans = 0;
  while (n > 20) {
    while (n % 10 != 1) {
      --n;
      ++ans;
    }
    ll best = n;
    ll cst = rev(n);
    for (ll v = n / 10, pw = 10, diff = 0, r = n; v > 9; v /= 10, pw *= 10) {
      r -= (v % 10) * pw;
      diff += (v % 10) * pw;
      if (cst > diff + rev(r)) {
        best = r;
        cst = diff + rev(r);
      }
    }
    // get to best
    ans += cst - rev(best);
    n = rev(best);
    // reverse
    if (best != rev(best)) {
      ++ans;
    }
    // get to a power of 10
    for (ll v = n, pw = 1; v > 1; v /= 10, pw *= 10) {
      ll d = (v % 10) * pw;
      ans += d;
      n -= d;
    }
  }
  ans += n;
  return ans;
}

int main() {
  int t; scanf("%d", &t);
  for (int cs = 1; cs <= t; ++cs) {
    ll n; scanf("%lld", &n);
    printf("Case #%d: %lld\n", cs, solve(n));
  }
  return 0;
}
