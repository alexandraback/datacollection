#include "stdio.h"
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#define SIZE 2000001
int main()
{
   int t; int a; int b; int q;
   int tags[SIZE]; int digit; int derp; int mag; int jack; int jill;
   scanf("%d", &t);
   for (jill = 0; jill < t; ) {
      scanf("%d %d", &a, &b);
      q = 0; for (jack = a; jack <= b; jack++) tags[jack] = 0;
      for (jack = a; jack <= b; jack++) {
         if (tags[jack] != 0) continue;
         mag = 1; derp = jack;
         while (derp) { mag = mag * 10; derp = derp / 10; }
         derp = jack; mag = mag / 10;
         while (1) {
            while (0 == (digit = derp % 10)) derp = derp / 10;
            derp = digit * mag + derp / 10;
            if (derp == jack) break;
            if (derp > b || derp < a) continue;
            tags[derp] = -1; tags[jack]++;
         }
      }
      for (jack = a; jack <= b; jack++) if (tags[jack] > 0) q = q + tags[jack]*(tags[jack] + 1)/2;
      printf("Case #%d: %d\n", ++jill, q);
   }
   return 0;
}
