#include<stdio.h>
#include<stdlib.h>

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 0; t< T; t++) {
      int K, C, S;
      scanf("%d %d %d", &S, &C, &K);
      printf("Case #%d:", t+1);
      for (int i = 0; i < S; i++) {
         printf(" %d", i+1);
      }
      printf("\n");
   }
   return 0;
}
