#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
typedef long long i64;

char digits[200];

bool is_fair(i64 x) {
  int len = 0;
  while (x) {
    digits[len++] = x % 10;
    x /= 10;
  }
  int k = len / 2;
  for (int i = 0; i < k; ++i)
    if (digits[i] != digits[len - i - 1])
      return false;
  return true;
}

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    i64 a, b;
    scanf("%lld%lld", &a, &b);
    i64 count = 0;
    i64 za = ceil(sqrt(a));
    i64 zb = floor(sqrt(b) + 1e-100);
    for (i64 k = za; k <= zb; ++k) {
      if (!is_fair(k))
        continue;
      i64 s = k * k;
      if (!is_fair(s))
        continue;
      ++count;
    }
    printf("Case #%d: %lld\n", test, count);
  }
  return 0;
}
