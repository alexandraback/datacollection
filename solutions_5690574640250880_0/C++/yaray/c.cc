#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP1(i, n) FOR(i, 1, n+1)
#define REP(i, n) FOR(i, 0, n)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

double rd()
{
  double x;
  scanf("%lf", &x);
  return x;
}

void arrange(int r, int c, int h, int w, int m)
{
  if (h <= r && w <= c)
    REP(i, r) {
      REP(j, c)
        putchar(i == r-1 && j == c-1 ? 'c' : i >= r-h && j >= c-w && --m < 0 ? '.' : '*');
      puts("");
    }
  else {
    int full_cols = m/r, partial = m%r;
    REP(i, r) {
      REP(j, c)
        putchar(i == r-1 && j == c-1 ? 'c' : i >= r-w && j >= c-h && !(j < c-h+full_cols || j == c-h+full_cols && i < r-w+partial) ? '.' : '*');
      puts("");
    }
  }
}

int main()
{
  int cases = ri();
  REP1(cid, cases) {
    int r = ri(), c = ri(), m = ri(), x = max(r, c), y = min(r, c), n = r*c-m;
    printf("Case #%d:\n", cid);
    if (r == 1) {
      arrange(1, c, 1, c, m);
      goto L1;
    }
    if (c == 1) {
      arrange(r, 1, r, 1, m);
      goto L1;
    }
    if (n == 4) { // r > 1 && c > 1
      arrange(r, c, 2, 2, 0);
      goto L1;
    }
    if (n == 6) { // r > 1 && c > 1
      arrange(r, c, 2, 3, 0);
      goto L1;
    }
    if (r == 2 && m%2 == 0 && m/2 <= c-2) {
      REP(i, 2) {
        REP(j, c)
          putchar(i == r-1 && j == c-1 ? 'c' : j < m/2 ? '*' : '.');
        puts("");
      }
      goto L1;
    }
    if (c == 2 && m%2 == 0 && m/2 <= r-2) {
      REP(i, r) {
        REP(j, 2)
          putchar(i == r-1 && j == c-1 ? 'c' : i < m/2 ? '*' : '.');
        puts("");
      }
      goto L1;
    }
    if (m == r*c-1) {
      arrange(r, c, r, c, m);
      goto L1;
    }
    FOR(w, 3, x+1) {
      int q = n/w, s = n%w, h = q+!!s;
      if (min(w, h) <= y && max(w, h) <= x && (s ? q >= 2 && s >= 2 : q >= 3)) {
        arrange(r, c, h, w, s ? w-s : 0);
        goto L1;
      }
    }
    if (r == c && m == c-1 && r >= 4) {
      int l = sqrt(2*m);
      if (l*(l+1) < 2*m) l++;
      REP(i, r) {
        REP(j, c)
          putchar(i == r-1 && j == c-1 ? 'c' : i < l && j < l && (i+j < l-1 || i+j == l-1 && i >= l*(l+1)/2-m) ? '*' : '.');
        puts("");
      }
      goto L1;
    }
    puts("Impossible");
L1:;
  }
}
