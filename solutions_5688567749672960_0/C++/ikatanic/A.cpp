#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 16;

llint f[MAX];
llint pw[MAX];

llint rev(llint x) {
  llint y = 0;
  while (x) {
    y = y*10 + (x%10);
    x /= 10;
  }
  return y;
}

llint solve(string s) {
  int n = (int)s.size() - 1;
  llint ans = 0;
  for (int i = n; i >= 0; --i)
    ans += (s[i] - '0') * pw[i];
  ans -= pw[n];
  assert(ans >= 0);

  if (ans == 0) return ans;

  int m = n/2+1;
  bool ima = false;
  REP(i, m) ima |= s[i] != '0';

  if (ima) {
    llint cost = -1 + (n > 0);
    for (int i = 0; i <= n; ++i)
      cost += (s[i] - '0') * pw[min(i, n-i)];
    ans = min(ans, cost);
  } else {
    llint left = 0;
    for (int i = n; i >= m; --i)
      left = left * 10 + (s[i] - '0');
    left--;
    
    llint cost = 1 + rev(left) + pw[m] - 1;
    ans = min(ans, cost);
  }

  return ans;
}

llint solve_real(string n) {
  assert(n[0] != '0');
  reverse(n.begin(), n.end());
  return f[ (int)n.size() - 1 ] + solve(n);
}

int main(void) {
  pw[0] = 1;
  FOR(i, 1, MAX)
    pw[i] = pw[i-1] * 10;

  f[0] = 1;
  string s = "";
  for (int i = 1; i < MAX; ++i) {
    s += "9";
    f[i] = f[i-1] + solve(s) + 1;
  }

  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    char s[111];
    scanf("%s", s);
    printf("Case #%d: ", tp);
    printf("%lld\n", solve_real(s));
  }
  return 0;
}
