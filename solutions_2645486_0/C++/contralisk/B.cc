#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long i64;
typedef unsigned long long u64;

//#define debug(args...) fprintf(stderr, args)
#define debug(...)

using namespace std;

int e, r, n;
int a[10000];
int s[10000];

int index_with_max_value(int x, int y) {
  int k = x;
  for (++x; x < y; ++x)
    if (a[x] > a[k])
      k = x;
  return k;
}

void calc(int x, int y, int ex, int ey) {
  debug("x=%d y=%d ex=%d ey=%d\n", x, y, ex, ey);
  int k = index_with_max_value(x, y);
  int left = min(e, ex + r * (k - x));
  int right = max(0, ey - r * (y - k - 1));
  s[k] = left - right;
  debug("k=%d l=%d r=%d s=%d\n", k, left, right, s[k]);
  if (k > x)
    calc(x, k, ex, left - r);
  if (k + 1 < y)
    calc(k + 1, y, right + r, ey);
}

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    scanf("%d%d%d", &e, &r, &n);
    debug("Case #%d: e=%d r=%d n=%d\n", test, e, r, n);
    if (r > e)
      r = e;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    calc(0, n, e, 0);
    u64 result = 0;
    for (int i = 0; i < n; ++i)
      result += a[i] * s[i];
    printf("Case #%d: %llu\n", test, result);
  }
  return 0;
}
