#include <stdio.h>

#define MAX_ENERGY 10000001

#define MAX(x, y) ((x)<(y)?(y):(x))

int dyn[MAX_ENERGY];
int dyn2[MAX_ENERGY];
int value[10001];

int main() {

  int T;

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int E, R, N;
    scanf("%d%d%d", &E, &R, &N);

    int *cur, *next;

    for (int i = 0; i <= E; i++) {
      dyn[i] = dyn2[i] = 0;
    }

    cur = dyn;
    next = dyn2;

    for (int i = 0; i < N; i++) {
      int val;
      scanf("%d", &val);

      for (int e = 0; e <= E; e++) {
        for (int j = 0; j <= e; j++) {
          int index = e - j + R;
          if (index > E) index = E;
          next[index] = MAX(cur[e] + j * val, next[index]);
          //printf("index = %d; curr = %d; maybe = %d; energy used = %d; next = %d\n", index, cur[index], cur[e] + j * val, j, next[index]);
        }
      }

      /*
      for (int i = 0; i <= E; i++) {
        printf("%d ", next[i]);
      }
      printf("\n");
      */

      int *tmp = cur;
      cur = next;
      next = tmp;

      for (int i = 0; i <= E; i++) {
        next[i] = 0;
      }
    }

    unsigned long long int ans = 0;
    for (int i = 0; i <= E; i++) {
      ans = MAX(cur[i], ans);
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  
  return 0;
}
