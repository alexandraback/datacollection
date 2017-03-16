#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    int K, C, S;
    scanf("%d%d%d", &K, &C, &S);
    printf("Case #%d:", i);
    if (S < K-C+1) {
      printf(" IMPOSSIBLE\n");
    } else {
      for (int i = 0; i < K; i += C) {
        long long idx = i;
        for (int j = 1; j < C; ++j) {
          idx *= K;
          if (i+j < K)
            idx += i+j;
        }
        printf(" %lld", idx+1);
      }
      printf("\n");
    }
  }
}
