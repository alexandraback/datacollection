#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  int t, T;
  scanf("%d", &t);
  for(T = 1; T <= t; T++){
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int i, j, cnt = 0;
    for(i = 0; i < a; i++){
      for(j = 0; j < b; j++)
        if((i & j) < k){
          cnt++;
          //printf("%d %d\n", i, j);
        }
    }
    printf("Case #%d: %d\n", T, cnt);
  }
  return 0;
}