#include <cstdio>
using namespace std;

inline long long GCD(long long a, long long b) {
  long long t;
  while (a > 0) {
    t = b % a;
    b = a;
    a = t;
  }
  return b;
}

inline bool is2m(long long a) {
  long long one = 1;
  while ((a & one) == 0) {
    a >>= 1;
  }
  return a == 1;
}

int main() {
  int T;
  scanf("%d", &T);
  long long p, q;
  for (int ca = 1; ca  <= T; ++ ca) {
    scanf("%lld/%lld", &p, &q);
    printf("Case #%d: ", ca);
    long long g = GCD(p, q);
    if (g > 1) {
      p /= g;
      q /= g;
    }
    if (!is2m(q)) {
      printf("impossible\n");
    } else {
      int k = 0;
      int j = 0;
      while (p > 1) {
        ++ k;
        p >>= 1;
      }
      while (q > 1) {
        q >>= 1;
        ++ j;
      }
      if (j > 40) {
        printf("impossible\n");
      } else {
        printf("%d\n", j - k);
      }
    }
  }
  return 0;
}
