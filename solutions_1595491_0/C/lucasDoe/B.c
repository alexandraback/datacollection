#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX 101

char cambiar(char car);

int main()
{
   int tests, x, y;
   int i, n, s, p, vote;
   int a, b, best, posible;
   char linea[MAX];

// Read the number of test cases.
   gets(linea);
   sscanf(linea, "%d", &tests);

   for(x = 1; x <= tests; x++)
   {
   // Read the test case.
      scanf("%d", &n);
      scanf("%d", &s);
      scanf("%d", &p);

      if (p == 1)
      {
         a = b = 0;
      }
      else
      {
         a = 3*p-3;
         b = 3*p-5;
      }

      y = 0;
      posible = 0;
      for(i = 0; i < n; i++)
      {
         scanf("%d", &vote);
         if (vote > a)
            y++;
         else if (vote > b)
            posible++;
      }

      y += ((posible < s) ? posible : s);

      printf("Case #%d: %d\n", x, y);
   }

   return 0;
}
