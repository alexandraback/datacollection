#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int
	T;

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("A-large.in", "r"),
	   *fpo = fopen("A-large.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
      _int64
         r,
         t,
         x;

      double
         a,
         b,
         c,
         r1;

		fscanf(fpi, "%lld", &r);
		fscanf(fpi, "%lld", &t);

      a = 2.0;
      b = 2.0 * r - 1.0;
      c = t * -1.0;

      r1 = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);

      x = (int)floor(r1);
      if (x == 0) x = 1;

      fprintf(fpo, "Case #%d: %lld\n", i + 1, x);
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
