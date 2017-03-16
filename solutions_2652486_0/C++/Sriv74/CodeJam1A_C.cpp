#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int
	T;

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("C-small-1.in", "r"),
	   *fpo = fopen("C-small-1.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
      int
         R,
         N,
         M,
         K,
         v,
         a[10];

		fscanf(fpi, "%d", &R);
		fscanf(fpi, "%d", &N);
		fscanf(fpi, "%d", &M);
		fscanf(fpi, "%d", &K);

      fprintf(fpo, "Case #%d:\n", i + 1);

      for (int j = 0; j < R; j++)
         {
         for (int k = 0; k < 10; k++)
            a[k] = 0;

         for (int k = 0; k < K; k++)
            {
            int
               c5 = 0,
               c3 = 0,
               c2 = 0,
               c4 = 0,
               l;

      		fscanf(fpi, "%d", &v);

            while (v % 5 == 0)
               {
               c5++;
               v /= 5;
               }

            while (v % 3 == 0)
               {
               c3++;
               v /= 3;
               }

            while (v % 4 == 2)
               {
               c2++;
               v /= 2;
               }

            l = N - c5 - c3 - c2;

            if (l && v % 4 == 0)
               {
               v /= (1 << l);
               if (v > 1)
                  while (v >>= 1)
                     c4++;
               }

            if (c2 > a[2])
               a[2] = c2;

            if (c3 > a[3])
               a[3] = c3;

            if (c4 > a[4])
               a[4] = c4;

            if (c5 > a[5])
               a[5] = c5;
            }

         for (int k = 0; k < a[2]; k++)
            fprintf(fpo, "2");

         for (int k = 0; k < a[3]; k++)
            fprintf(fpo, "3");

         for (int k = 0; k < a[4]; k++)
            fprintf(fpo, "4");

         for (int k = 0; k < a[5]; k++)
            fprintf(fpo, "5");

         int
            t = a[2] + a[3] + a[4] + a[5];

         for (int k = t; k < N; k++)
            fprintf(fpo, "4");

         fprintf(fpo, "\n");
         }
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
