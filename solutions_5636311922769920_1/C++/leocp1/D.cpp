#include<bitset>
#include<stddef.h>
#include<stdio.h>

void printTiles(size_t K, size_t C, size_t S) {
  size_t x;
  for (size_t i = 0; i < K; i += C) {
    x = 0;
    for (size_t j = i; j < i + C; j++) {
      x = K * x + ((j < K) ? j : K - 1);
    }
    printf("%zu ", x + 1); //1 indexed
  }
  printf("\n");
  return ;
}

int main(void) {
  size_t T = 0;
  size_t K = 0;
  size_t C = 0;
  size_t S = 0;
  scanf("%zu\n", &T);
  for (size_t i = 1; i <= T; i++) {
    scanf("%zu %zu %zu\n", &K, &C, &S);
    printf("Case #%zu: ", i);
    if (C * S >= K) {
      printTiles(K, C, S);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
