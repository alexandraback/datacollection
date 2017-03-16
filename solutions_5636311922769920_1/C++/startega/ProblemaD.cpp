
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

long Primo(long n);

int main()
{
	FILE *In, *Out;
	long T, K, C, S;
	long i, j, k;
	
	unsigned char cadena[32];
	unsigned long long factor;
	long div[9];
	unsigned long long Sol;
	long ip, n;
	long dig[100];

	//In = fopen("D-small-attempt1.in", "r");
	//In = fopen("prueba.txt", "r");
	In = fopen("D-large.in", "r");

	//Out = fopen("D-small-attempt1.out", "w");
	//Out = fopen("prueba.out", "w");
	Out = fopen("D-large.out", "w");

	fscanf(In, "%d", &T);

	for (i = 0; i < T; i++)
	{
		fprintf(Out, "Case #%d:", i + 1);

		fscanf(In, "%d", &K);
		fscanf(In, "%d", &C);
		fscanf(In, "%d", &S);

		if (C * S < K)
		{
			fprintf(Out, " IMPOSSIBLE\n");
			continue;
		}

		for (j = 0; j < S; j++)
		{
			if (j * C >= K)
				break;

			for (k = 0; k < C && k < K; k++)
				dig[k] = (j * C + k) % K;

			Sol = 0;
			factor = 1;

			for (k = 0; k < C && k < K; k++)
			{
				Sol += dig[k] * factor;
				factor *= K;
			}
			fprintf(Out, " %lld", Sol + 1);
		}
		fprintf(Out, "\n");
	}


	fclose(In);
	fclose(Out);

    return 0;
}
