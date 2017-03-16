#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// check for i * C + 1, ..., min(i * C + C, K)
long long get(long long i, long long K, long long C) {
   long long index = 0;
   for (int c = 0; c < C; c++) {
      if (C * i + c + 1 > K) {
         index = index * K;
      } else {
         index = index * K + C * i + c;
      }
   }
   index = index + 1;
   return index;
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 0; t< T; t++) {
      int K, C, S;
      scanf("%d %d %d", &K, &C, &S);
      printf("Case #%d:", t+1);

      int minS = (K + C - 1) / C;

      if (S < minS) {
         printf(" IMPOSSIBLE");
         /*
      } else if (C == 1) {
         for (int i = 0; i < minS; i++) {
            printf(" %d", i+1);
         }
      } else if (K == 1) {
         printf(" 1");
         */
      } else {
         for (int i = 0; i < minS; i++) {
            printf(" %lld", get(i, K, C));
         }
      }
      printf("\n");
   }
   return 0;
}
