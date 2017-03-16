#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX 101

char cambiar(char car);

int main()
{
   int i, x, tests;
   char linea[MAX], y[MAX];

// Read the number of test cases.
   gets(linea);
   sscanf(linea, "%d", &tests);


if (DEBUG)
{
   printf("%d", tests);
}


   for(x = 1; x <= tests; x++)
   {
   // Read the test case.
      gets(y);


if (DEBUG)
{
   printf("%d", strlen(y));
   printf("%s\n", y);
}


      for(i = 0; i < strlen(y); i++)
         y[i] = cambiar(y[i]);

      printf("Case #%d: %s\n", x, y);
   }

   return 0;
}

char cambiar(char car)
{
   switch(car)
   {
      case 'a': return 'y';
      case 'b': return 'h';
      case 'c': return 'e';
      case 'd': return 's';
      case 'e': return 'o';
      case 'f': return 'c';
      case 'g': return 'v';
      case 'h': return 'x';
      case 'i': return 'd';
      case 'j': return 'u';
      case 'k': return 'i';
      case 'l': return 'g';
      case 'm': return 'l';
      case 'n': return 'b';
      case 'o': return 'k';
      case 'p': return 'r';
      case 'q': return 'z';
      case 'r': return 't';
      case 's': return 'n';
      case 't': return 'w';
      case 'u': return 'j';
      case 'v': return 'p';
      case 'w': return 'f';
      case 'x': return 'm';
      case 'y': return 'a';
      case 'z': return 'q';
      default:  return car;
   }
}
