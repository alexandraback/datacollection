#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long ll;
typedef __int128 lll;

ll get_factor(lll x) {
  for (lll y = 2; y * y <= x && y < 10000; ++y)
    if (x % y == 0)
      return y;
  return 1;
}

int main(void) {
  ll factor[11];
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, J;
    scanf("%d%d", &N, &J);

    printf("Case #%d:\n", t);

    for (ll x = (1LL << (N - 1)) + 1; x < (1LL << N); x += 2) {
      int d;
      for (d = 2; d <= 10; ++d) {
        lll z = 0;
        for (int i = 0; i < N; ++i)
          z = d * z + ((x >> (N - i - 1)) & 1);
        factor[d] = get_factor(z);
        // printf("x=%lld d=%d z=%lld factor=%lld\n", x, d, (ll)z, factor[d]);
        if (factor[d] == 1)
          break;
      }
      
      if (d == 11) {
        char out[40];
        for (int i = 0; i < N; ++i)
          out[i] = '0' + ((x >> (N - i - 1)) & 1);
        out[N] = 0;

        // printf("%d ", J);
        printf("%s", out);
        for (int d = 2; d <= 10; ++d)
          printf(" %lld", factor[d]);
        printf("\n");

        if (--J == 0)
          break;
      }
    }
  }
  return 0;
}
