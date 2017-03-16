#include <algorithm>
#include <cstdio>
using namespace std;
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n+1)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;

const int N = 10000;
char a[N+1];
int d[8][8] = {
  {0,1,2,3},
  {1,4,3,6},
  {2,7,4,1},
  {3,2,5,4},
}, dd[8][8];

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

ll rll()
{
  ll x;
  scanf("%lld", &x);
  return x;
}

struct Scan
{
  bool rtl;
  int n;
  Scan(int n, bool rtl) : n(n), rtl(rtl) {}
  int at(int i) { return (rtl ? a[n-1-i] : a[i])-'i'+1; }
  int run(int &x) {
    int y[8] = {}, (*d)[8] = rtl ? dd : ::d;
    fill_n(y, 8, -1);
    y[0] = 0;
    x = 0;
    REP(i, n) {
      x = d[x][at(i)];
      if (y[x] < 0)
        y[x] = i+1;
    }
    int xx = 0;
    REP(i, 4) {
      REP(j, 8)
        if (y[j] >= 0 && d[xx][j] == (rtl ? 3 : 1))
          return n*i+y[j];
      xx = d[xx][x];
    }
    return -1;
  }
};

int main()
{
  REP(i, 4)
    REP(j, 4) {
      d[i][4+j] = d[4+i][j] = d[i][j]^4;
      d[4+i][4+j] = d[i][j];
    }
  REP(i, 8)
    REP(j, 8)
      dd[j][i] = d[i][j];

  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    ll m = rll();
    scanf("%s", a);
    int l, r, x, y, xx = 0;
    l = Scan(n, false).run(x);
    r = Scan(n, true).run(y);
    REP(i, m%4)
      xx = d[xx][x];
    printf("Case #%d: %s\n", cc, xx == 4 && l >= 0 && r >= 0 && l+r < n*m ? "YES" : "NO");
  }
}
