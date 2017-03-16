#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdint.h>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef int64_t i64;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

i64 RL()
{
  i64 x;
  scanf("%" SCNd64, &x);
  return x;
}

bool check(i64 x)
{
  i64 xx = x, y = 0;
  for (; x; x /= 10)
    y = y * 10 + x % 10;
  return y == xx;
}

int main()
{
  int n = 0;
  i64 a[92];

  for (i64 i = 1; i <= 10000000; i++)
    if (check(i) && check(i * i))
      a[n++] = i * i;

  int cases = RI();
  REP1(cc, cases) {
    i64 lo = RL(), hi = RL();
    printf("Case #%d: %d\n", cc, int(upper_bound(a, a + n, hi) - lower_bound(a, a + n, lo)));
  }
}
