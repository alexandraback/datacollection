#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct tagREQSTARS
{
   tagREQSTARS()
	{
      b1 = false;
      b2 = false;
	}

   tagREQSTARS(int n1, int n2)
	{
		r1 = n1;
      r2 = n2;
      b1 = false;
      b2 = false;
	}

	int
		r1,
      r2;

   bool
      b1,
      b2;

} REQSTARS;

int
	T;

int main(int argc, char *argv[])
{
   FILE
	   *fpi = fopen("B-large.in", "r"),
	   *fpo = fopen("B-large.out", "w");

	fscanf(fpi, "%d", &T);
	for (int i = 0; i < T; i++)
		{
		int
			N;

      REQSTARS
         rs[1000];

		fscanf(fpi, "%d", &N);
		for (int j = 0; j < N; j++)
			{
			fscanf(fpi, "%d", &rs[j].r1);
			fscanf(fpi, "%d", &rs[j].r2);
         }

      int
         nStars = 0,
         nLevels = 0;

		while (true)
			{
start:
         for (int j = 0; j < N; j++)
            {
            if (rs[j].b2)
               continue;

            if (nStars >= rs[j].r2)
               {
               nStars += rs[j].b1 ? 1 : 2;
               nLevels += 1;
               rs[j].b1 = true;
               rs[j].b2 = true;
               goto start;
               }
            }

         if (nStars >= 2 * N)
            {
      		fprintf(fpo, "Case #%d: %d\n", i + 1, nLevels);
            break;
            }

         int
            nBest = -1,
            nMax  = -1;

         for (int j = 0; j < N; j++)
            {
            if (rs[j].b1)
               continue;

            if (nStars >= rs[j].r1 && rs[j].r2 > nMax)
               {
               nBest = j;
               nMax  = rs[j].r2;
               }
            }

         if (nBest == -1)
            {
      	   fprintf(fpo, "Case #%d: Too Bad\n", i + 1);
            break;
            }

         nStars += 1;
         nLevels += 1;
         rs[nBest].b1 = true;
         }
		}

	fclose(fpi);
	fclose(fpo);
	return 0;
}
