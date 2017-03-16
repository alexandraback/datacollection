#include "stdio.h"
#define SIZE 128
int main()
{
   int t; int n; int s; int p; int scores[SIZE];
   int base; int rem; int q;
   scanf("%d", &t);
   for (int jill = 0; jill < t; ) {
      scanf("%d %d %d", &n, &s, &p);
      for (int jack = 0; jack < n; jack++) scanf("%d", &scores[jack]);
      q = 0; for (int jack = 0; jack < n; jack++) {
         base = scores[jack] / 3; rem = scores[jack] % 3;
         if (base >= p) q++;
         else if (p - base == 1 && rem > 0) q++;
         else if (p - base == 1 && rem == 0 && base > 0 && s > 0) { q++; s--; }
         else if (p - base == 2 && rem == 2 && s > 0) { q++; s--; }
      }
      printf("Case #%d: %d\n", ++jill, q);
   }
   return 0;
}
