#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdint.h>
typedef int64_t i64;

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

int main()
{
  int cases = RI();
  REP1(cc, cases) {
    i64 l = 0, h = 10000000000, r, t;
    scanf("%" SCNd64"%" SCNd64, &r, &t);
    while (l < h - 1) {
      i64 x = (l + h) / 2;
      i64 y = (2*r+2*x-1)*x;
      if (2*r+2*x-1 <= t/x) l = x;
      //if (y <= t) l = x;
      else h = x;
    }
    printf("Case #%d: %" PRId64"\n", cc, l);
  }
}

