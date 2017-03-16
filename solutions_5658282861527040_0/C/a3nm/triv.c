#include<stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  int ncase;
  for (ncase = 0; ncase < T; ncase++) {
    int A, B, K;
    unsigned int i, j;
    int ans = 0;
    scanf("%d %d %d", &A, &B, &K);
    for (i=0; i<A; i++)
      for (j=0; j<B; j++) {
        int lucky = i&j;
        //printf("lucky %d\n", lucky);
        if (lucky < K) {
          //printf("win by %d %d\n", i, j);
          ans++;
        } else {
          //printf("fail by %d %d\n", i, j);
        }
      }
    printf("Case #%d: %d\n", ncase+1, ans);
  }
  return 0;
}
