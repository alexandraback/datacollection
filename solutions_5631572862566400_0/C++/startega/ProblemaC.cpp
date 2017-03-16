
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	FILE *In, *Out;
	long T, N, J;
	long i, j, k;

	int F1[1000];
	int F;

	long n, nMax;


	In = fopen("C-small-attempt0.in", "r");
	//In = fopen("prueba.txt", "r");
	//In = fopen("C-large.in", "r");

	Out = fopen("C-small-attempt0.out", "w");
	//Out = fopen("prueba.out", "w");
	//Out = fopen("C-large.out", "w");

	fscanf(In, "%ld", &T);

	for (i = 0; i < T; i++)
	{

		fscanf(In, "%ld", &N);

		for (j = 0; j < N; j++)
		{
			fscanf(In, "%ld", &F);
			F1[j] = F - 1;
		}

		nMax = 1;
		for (j = 0; j < N; j++)
		{
			n = 1;
			F = j;

			while (1)
			{
				F = F1[F];
				if (F == j)
					break;

				n++;

				if (n > N)
				{
					n = 0;
					break;
				}
			}

			if (n > nMax)
				nMax = n;
		}

		fprintf(Out, "Case #%d: %d\n", i + 1, nMax);

	}


	fclose(In);
	fclose(Out);

    return 0;
}
