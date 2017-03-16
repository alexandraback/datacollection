#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

typedef long long ll;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

ll rl()
{
  ll x;
  scanf("%lld", &x);
  return x;
}

int d[20];

int gend(ll n)
{
  int m = 0;
  do d[m++] = n%10; while (n /= 10);
  reverse(d, d+m);
  return m;
}

ll rev(ll n)
{
  ll s = 0;
  do s = s*10+n%10; while (n /= 10);
  return s;
}

ll ltr(int l, int r)
{
  ll s = 0;
  FOR(i, l, r)
    s = s*10+d[i];
  return s;
}

ll rtl(int l, int r)
{
  ll s = 0;
  ROF(i, l, r)
    s = s*10+d[i];
  return s;
}

ll f(ll n, ll s)
{
  if (n <= 20) return n+s;
  if (n % 10 == 0)
    return f(n-1, s+1);

  int m = gend(n);
  ll ten = 1;
  REP(i, m-1) ten *= 10;

  if (d[0] > 1) { // [2-9]...
    ll nn = ten+rtl(0, m/2);
    return f(nn, s+1+n-rev(nn));
  }
  if (count(d+1, d+m/2, 0) == m/2-1) // 100...
    return f(ten, s+n-ten);
  return f(ten, s+rtl(0, m/2)+ltr(m/2, m));
}

int main()
{
  int cases = ri();
  REP1(cc, cases)
    printf("Case #%d: %lld\n", cc, f(rl(), 0));
}
