#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1
#define MAX 101
#define LENG 8

void itoa(int value, char * string);
int prueba(int i, int b);

int main()
{
   int tests, x, y;
   char linea[MAX];
   int a, b, i;

// Read the number of test cases.
   gets(linea);
   sscanf(linea, "%d", &tests);

   for(x = 1; x <= tests; x++)
   {
   // Read the test case.
      gets(linea);
      sscanf(linea, "%d%d\n", &a, &b);

      y = 0;
      for(i = a; i < b; i++)
         y += prueba(i, b);

      printf("Case #%d: %d\n", x, y);
   }

   return 0;
}

void itoa(int value, char * string)
{
   char tmp;
   int i = 0, j;

   do
   {
      string[i++] = '0' + (value % 10);
      value /= 10;
   } while(value != 0);

   for(j = 0; j < i/2; j++)
   {
      tmp = string[j];
      string[j] = string[i-j-1];
      string[i-j-1] = tmp;
   }
   string[i] = '\0';
}

int prueba(int i, int b)
{
   int n, j, k, resul = 0;
   char number[LENG], mod[LENG];

   itoa(i, number);
   n = strlen(number);

   for(j = 1; j < n; j++)
   {
      for(k = 0; k < n; k++)
         mod[k] = number[(j+k)%n];
      if ((atoi(mod) > i) &&
          (atoi(mod) <= b))
         resul++;
   }

   return resul;
}
