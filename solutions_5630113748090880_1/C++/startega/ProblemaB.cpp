
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
	FILE *In, *Out;

	long T, N;
	long i, j, k, l;
	long H[2501], H0;

	int S1[50], S2[50];
	long n;


	//In = fopen("B-small-attempt0.in", "r");
	//In = fopen("prueba.txt", "r");
	In = fopen("B-large.in", "r");

	//Out = fopen("B-small-attempt0.out", "w");
	//Out = fopen("prueba.out", "w");
	Out = fopen("B-large.out", "w");

	fscanf(In, "%d", &T);


	for (i = 0; i < T; i++)
	{
		fscanf(In, "%d", &N);

		memset(H, 0, sizeof(long) * 2501);

		for (j = 0; j < 2 * N - 1; j++)
		{
			for (k = 0; k < N; k++)
			{
				fscanf(In, "%ld", &H0);
				H[H0]++;
			}
		}

		n = 0;
		for (j = 0; j < 2501; j++)
		{
			if (H[j] % 2 == 1)
			{
				S1[n] = j;
				n++;
			}
		}

		for (j = 0; j < N; j++)
		{
			for (k = 0; k < j && S2[k] < S1[j]; k++);

			for (l = j; l > k; l--)
				S2[l] = S2[l - 1];

			S2[k] = S1[j];
		}

		fprintf(Out, "Case #%d:", i + 1);

		for (j = 0; j < N; j++)
			fprintf(Out, " %d", S2[j]);

		fprintf(Out, "\n");

	}

	fclose(In);
	fclose(Out);

    return 0;
}

