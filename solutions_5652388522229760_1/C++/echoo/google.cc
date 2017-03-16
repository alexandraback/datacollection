#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  for (int x = 1; x <= T; ++x) {
    printf("Case #%d: ", x);
    long long N = 0;
    scanf("%lld", &N);
    if (0 == N) {
      printf("INSOMNIA\n");
    } else {
      bool seen[10];
      memset(seen, 0, sizeof(seen));
      int seen_c = 0;
      int i = 1;
      for (; seen_c < 10; ++i) {
        long long y = N * i;
        while (y != 0) {
          int d = y % 10;
          if (seen[d] == false) {
            ++seen_c;
            seen[d] = true;
          }
          y = y / 10;
        }
      }
      printf("%lld\n", i * N - N);
    }
  }
}
