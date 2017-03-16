#include <stdio.h>
#include <stdlib.h>

int main() {
  int T, i, A, B, K;
  scanf("%d", &T);
  for(i = 0; i < T; i++) {
    int answer = 0, j, k;
    scanf("%d %d %d", &A, &B, &K);
    for(j = 0; j < A; j++) {
      for(k = 0; k < B; k++) {
        if((j & k) < K) answer++;
      }
    }
    printf("Case #%d: %d\n", i + 1, answer);
  }
}
