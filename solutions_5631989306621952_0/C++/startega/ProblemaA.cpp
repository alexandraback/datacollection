
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
	FILE *In, *Out;

	long i, j, k;
	long T;
	char SI[1001];
	char SO[1001];
	char sAux[2];

	In = fopen("A-small-attempt0.in", "r");
	//In = fopen("prueba.txt", "r");
	//In = fopen("A-large.in", "r");

	Out = fopen("A-small-attempt0.out", "w");
	//Out = fopen("prueba.out", "w");
	//Out = fopen("A-large.out", "w");

	fscanf(In, "%ld", &T);

	memset(sAux, 0, 2);

	for (i = 0; i < T; i++)
	{
		fscanf(In, "%s", SI);

		memset(SO, 0, 1001);

		for (j = 0; SI[j]; j++)
		{
			if (j==0 || SI[j] >= SO[0])
			{
				for (k = j; k > 0; k--)
					SO[k] = SO[k - 1];

				SO[0] = SI[j];
			}
			else
				SO[j] = SI[j];
		}

		SO[strlen(SI)] = 0;

		fprintf(Out, "Case #%d: %s\n", i + 1, SO);
	}


	fclose(In);
	fclose(Out);

    return 0;
}

