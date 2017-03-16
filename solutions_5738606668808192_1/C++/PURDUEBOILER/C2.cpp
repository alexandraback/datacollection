#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define FIX_N 32

char number[FIX_N+1];

long long  mypow(long long a, int b) {
   long long c = 1;
   for (int i = 0; i < b; i++) {
      c *= a;
   }
   return c;
}

void generateNumber(int j) {
   for (int i = 0; i < FIX_N; i++) {
      number[i] = '0';
   }
   number[0]         = '1';
   number[FIX_N/2-1] = '1';
   number[FIX_N/2]   = '1';
   number[FIX_N-1]   = '1';
   int i = 0;
   while (j > 0) {
      number[FIX_N/2-2-i] = number[FIX_N-2-i] = j % 2 + '0';
      j /= 2;
      i++;
   }
}

int main() {
   int T;
   scanf("%d", &T);
   for (int i = 0; i < FIX_N+1; i++) number[i] = 0;

   for (int t = 0; t < T; t++) {
      int N, J;
      scanf("%d %d", &N, &J);
      printf("Case #%d:\n", t + 1);
      for (int j = 0; j < J; j++) {
         generateNumber(j);
         printf("%s", number);
         for (long long i = 2; i <= 10; i++) {
            //printf("\n%lld %d\n", i, (FIX_N/2));
            long long v = mypow(i, (FIX_N/2)) + 1;
            printf(" %lld", v);
         }
         printf("\n");
      }
   }
   return 0;
}
