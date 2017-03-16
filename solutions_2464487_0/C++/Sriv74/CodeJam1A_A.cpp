#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int
	T;

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("A-small.in", "r"),
	   *fpo = fopen("A-small.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
      _int64
         r,
         t;

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
//      fprintf(fpo, "Case #%d: %lf\n", i + 1, r1);
      fprintf(fpo, "Case #%d: %d\n", i + 1, (int)floor(r1));
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
