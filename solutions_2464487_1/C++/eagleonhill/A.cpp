#include <cstdio>
#include <cmath>

long long work() {
  long long r, t;
  scanf("%lld%lld", &r, &t);
  long long a = 0, b = sqrt(t) + 1;

  while (a != b) {
    long long c = (a + b + 1) >> 1;
    if (c - t * 1.0 / (2 * c + 2 * r - 1) <= 0) {
      a = c;
    } else {
      b = c - 1;
    }
  }
  return a;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: %lld\n", i, work());
  }
}
