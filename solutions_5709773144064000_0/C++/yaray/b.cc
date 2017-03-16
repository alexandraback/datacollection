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

int main()
{
  int cases = ri();
  REP1(cid, cases) {
    double c = rd(), f = rd(), x = rd(), tim = 0, ans = DBL_MAX;
    int maxf = (int)ceil(x/2);
    for (int i = 0; ; i++) {
      if (tim >= ans) break;
      ans = min(ans, tim+x/(2+i*f));
      tim += c/(2+i*f);
    }
    printf("Case #%d: %.7lf\n", cid, ans);
  }
}
