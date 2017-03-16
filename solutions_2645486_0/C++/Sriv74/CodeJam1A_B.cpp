#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int
	T,
   E,
   R,
   N,
   v[10],
   m[6][10],
   g;

int max_gain(int e, int nstartindex)
{
   if (nstartindex >= N)
      return (0);

   if (m[e][nstartindex] != -1)
      return (m[e][nstartindex]);

   int
      max = 0;

   for (int t = 0; t <= e; t++)
      {
      g = t * v[nstartindex] + max_gain(MIN(e - t + R, E), nstartindex + 1);
      if (g > max)
         max = g;
      }

   m[e][nstartindex] = max;
   return (max);
}

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("B-small.in", "r"),
	   *fpo = fopen("B-small.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
		fscanf(fpi, "%d", &E);
		fscanf(fpi, "%d", &R);
		fscanf(fpi, "%d", &N);

      for (int j = 0; j < N; j++)
   		fscanf(fpi, "%d", &v[j]);

      for (int j = 0; j <= E; j++)
         for (int k = 0; k < N; k++)
            m[j][k] = -1;

      g = max_gain(E, 0);
      fprintf(fpo, "Case #%d: %d\n", i + 1, g);
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
