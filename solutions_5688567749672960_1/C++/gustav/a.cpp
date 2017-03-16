#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 2000005;

int rev(int x) {
  int ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}

llint p10[20];

void solve_real() {
  llint n;
  scanf("%lld", &n);

  llint now = 1;
  llint cost = 0;
  int power = 1;
  while (n / now >= 10) {
    if (now == 1) {
      cost += 9;
      now += 9;
      ++power;
      continue;
    }
    llint nxt = now * 10;
    cost += p10[power / 2] - 1;
    now += p10[power / 2] - 1;
    cost += 1;
    now = rev(now);
    cost += nxt - now;
    now = nxt;
    ++power;
  }

  assert(now <= n);
  llint sol = cost + n - now;

  REP(digs, 15) {
    llint ccost = cost + rev(n / p10[digs]);
    llint cnow = now + rev(n / p10[digs]);
    cnow = rev(cnow);
    ccost += 1;
    if (cnow <= n) {
      sol = min(sol, ccost + n - cnow);
    }

    if (n / p10[digs] > 0) {
      ccost = cost + rev(n / p10[digs] - 1);
      llint cnow = now + rev(n / p10[digs] - 1);
      cnow = rev(cnow);
      ccost += 1;
      if (cnow <= n) {
	sol = min(sol, ccost + n - cnow);
      }
    }
  }

  printf("%lld\n", sol + 1);
}

int main(void) 
{
  p10[0] = 1;
  FOR(i, 1, 18) p10[i] = p10[i - 1] * 10;

  int T; scanf("%d", &T);
  FOR(tc, 1, T + 1) {
    printf("Case #%d: ", tc);
    solve_real();
  }
  return 0;
}
