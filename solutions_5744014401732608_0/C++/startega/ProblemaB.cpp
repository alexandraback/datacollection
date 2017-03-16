
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

long Pot(long n);

int main()
{
	FILE *In, *Out;

	long T, B, M;
	long i, j, k;
	unsigned char matriz[50][50];

	long n;
	

	//In = fopen("prueba.in", "r");
	In = fopen("B-small-attempt0.in", "r");
	//In = fopen("B-large.in", "r");

	//Out = fopen("prueba.out", "w");
	Out = fopen("B-small-attempt0.out", "w");
	//Out = fopen("B-large.out", "w");

	fscanf(In, "%d", &T);


	for (i = 0; i < T; i++)
	{
		fprintf(Out, "Case #%d: ", i + 1);

		fscanf(In, "%d", &B);
		fscanf(In, "%d", &M);

		for (j = 0; j < 50; j++)
		{
			for (k = 0; k < 50; k++)
				matriz[j][k] = 0;
		}

		if (M >  B-1)
		{
			fprintf(Out, "IMPOSSIBLE\n");
			continue;
		}

		fprintf(Out, "POSSIBLE\n");

		for (j = 0; j < M - 1; j++)
		{
			matriz[j][j + 1] = 1;
			matriz[j][B - 1] = 1;
		}
		matriz[j][B - 1] = 1;


		for (j = 0; j < B; j++)
		{
			for (k = 0; k < B; k++)
				fprintf(Out, "%d", matriz[j][k]);

			fprintf(Out, "\n");
		}
	}

	fclose(In);
	fclose(Out);

    return 0;
}
