#include "stdio.h"
#define LIMIT 1 + 100000
#define PRECISION 1000000
int main()
{
   int T; int A; int B;
   float p[LIMIT]; float pcum[LIMIT]; float exp[LIMIT]; int q; float qf;
   scanf("%d", &T);
   for (int test = 0; test < T; test++) {
      scanf("%d %d", &A, &B);
      for (int jack = 0; jack < A; jack++) scanf("%f", &p[jack]);
      //printf("Read Ps : "); for (int jack = 0; jack < A; jack++) printf("%f|", p[jack]); printf("\n");
      pcum[0] = p[0];
      for (int jack = 1; jack < A; jack++) pcum[jack] = pcum[jack-1]*p[jack];
      //printf("Calc PCs : "); for (int jack = 0; jack < A; jack++) printf("%f|", pcum[jack]); printf("\n");
      exp[0] = B + 1 + A;
      for (int jack = 1; jack < A+1; jack++) exp[jack] = pcum[jack-1] * (B - A + 2*(A - jack) + 1) + (1 - pcum[jack-1])*(B - A + 2*(A-jack) + 1 + B + 1);
      //printf("EXPs : "); for (int jack = 0; jack < A+1; jack++) printf("%f|", exp[jack]); printf("\n");
      q = 0; for (int jack = 0; jack < A+1; jack++) if (exp[jack] <= exp[q]) q = jack;
      if (exp[q] > (B + 1 + 1)) qf = B + 1 + 1; else qf = exp[q];
      printf("Case #%d: %f\n", test+1, qf);
   }
   return 0;
}
