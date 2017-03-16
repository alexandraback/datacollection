#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
		int
			A,
         B;

      double
         mult = 1.0,
         p,
         back,
         best,
         keep;

		fscanf(fpi, "%d", &A);
		fscanf(fpi, "%d", &B);
      best = B + 2;

		for (int j = 1; j <= A; j++)
         {
			fscanf(fpi, "%lf", &p);
         mult *= p;
         back = A - j + mult * (B - j + 1) + (1 - mult) * (2 * B - j + 2);

         if (back < best)
            best = back;
         }

      keep = mult * (B - A + 1) + (1 - mult) * (2 * B - A + 2);
      if (keep < best)
         best = keep;

      fprintf(fpo, "Case #%d: %lf\n", i + 1, best);
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
