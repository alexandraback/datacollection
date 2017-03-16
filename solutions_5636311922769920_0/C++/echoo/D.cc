#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d:", i);
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);
    long long G = 1;
    for (int j = 1; j < C; ++j) {
      G *= K;
    }
    long long P = 1;
    for (int j = 1; j <= K; ++j) {
      printf(" %lld", P);
      P += G;
    }
    printf("\n");
  }
}
