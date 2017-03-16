#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    char buf[20];
    int seen = 0;
    bool digits[10] = {};
    int N, R = 0;
    scanf("%d", &N);
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", i);
      continue;
    }
    while (seen != 10) {
      R += N;
      sprintf(buf, "%d", R);
      for (char* p = buf; *p; ++p) {
        if (!digits[*p-'0']) {
          digits[*p-'0'] = true;
          ++seen;
        }
      }
    }
    printf("Case #%d: %d\n", i, R);
  }
}
