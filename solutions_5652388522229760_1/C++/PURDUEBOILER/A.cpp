#include<stdlib.h>
#include<stdio.h>

int digits[10];

int check(int N) {
   while (N > 0) {
      digits[N%10] = 1;
      N /= 10;
   }
   for (int i = 0; i < 10; i++) {
      if (!digits[i])
         return 0;
   }
   return 1;
}

int lastDigit(int N) {
   if (N == 0)
      return 0;
   int X = N;
   while (!check(X)) {
      X += N;
   }
   return X;
}

int main() {
   int T, N;

   scanf("%d", &T);
   for (int i = 0; i < T; i++) {
      scanf("%d", &N);
      for (int j= 0 ; j < 10; j++) {
         digits[j] = 0;
      }
      int X = lastDigit(N);
      printf("Case #%d: ", i+1); 
      if (X) {
         printf("%d\n", X);
      } else {
         printf("INSOMNIA\n");
      }
   }
   return 0;
}
