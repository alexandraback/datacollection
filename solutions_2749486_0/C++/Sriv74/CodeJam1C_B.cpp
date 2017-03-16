#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
int
	T;

char
   s[501];

char best_dir(int x, int y, int tx, int ty, int n)
{
/*
   int
      dx = tx - x,
      dy = ty - y;

   if (dx >= n)
      return ('E');

   if (dx <= -n)
      return ('W');

   if (dy >= n)
      return ('N');

   if (dy <= -n)
      return ('S');
*/
   int
      r = rand() % 4;

   switch (r)
      {
      case 0: return ('E');
      case 1: return ('W');
      case 2: return ('N');
      }

   return ('S');
}

char *get_val(int tx, int ty)
{
   for (int t = 0; t < 1000000; t++)
      {
      int
         x = 0,
         y = 0;

      char
         b;

      memset(s, 0, 501);
      for (int n = 1; n <= 500; n++)
         {
         b = best_dir(x, y, tx, ty, n);
         s[n - 1] = b;

         switch (b)
            {
            case 'E': x += n; break;
            case 'W': x -= n; break;
            case 'N': y += n; break;
            case 'S': y -= n; break;
            }

         if (x == tx && y == ty)
            return (s);
         }
      }

   return ("FAIL");
}

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("B-small.in", "r"),
	   *fpo = fopen("B-small.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
      int
         tx,
         ty;

		fscanf(fpi, "%d", &tx);
		fscanf(fpi, "%d", &ty);

      fprintf(fpo, "Case #%d: %s\n", i + 1, get_val(tx, ty));
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
