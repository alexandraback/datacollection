
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ordena.cpp"

int main()
{
	FILE *In, *Out;
	long T, N, J, P, S, K;
	long iJ, iP, iS, nK[3];
	long i, j, k;

	long Outfit[1000][3];

	long n;

	//In = fopen("prueba.in", "r");
	In = fopen("C-small-attempt2.in", "r");
	//In = fopen("C-large.in", "r");

	//Out = fopen("prueba.out", "w");
	Out = fopen("C-small-attempt2.out", "w");
	//Out = fopen("C-large.out", "w");

	fscanf(In, "%ld", &T);

	for (i = 0; i < T; i++)
	//for (i = 0; i < 6; i++)
	{
		fscanf(In, "%d", &J);
		fscanf(In, "%d", &P);
		fscanf(In, "%d", &S);
		fscanf(In, "%d", &K);

		n = 0;

		for (iS = 0; iS < S; iS++)
		{
			for (iP = 0; iP < P; iP++)
			{
				for (iJ = 0; iJ < J; iJ++)
				{
					nK[0] = 0;
					nK[1] = 0;
					nK[2] = 0;

					for (k = 0; k < n; k++)
					{
						if (Outfit[k][0] == iJ &&
							Outfit[k][1] == iP)
							nK[0]++;
						
						if (Outfit[k][0] == iJ &&
							Outfit[k][2] == iS)
							nK[1]++;

						if (Outfit[k][1] == iP &&
							Outfit[k][2] == iS)
							nK[2]++;
						{
							if (nK[0] > K-1)
								break;
							if (nK[1] > K-1)
								break;
							if (nK[2] > K-1)
								break;
						}
					}

					if (k == n)
					{
						Outfit[n][0] = iJ;
						Outfit[n][1] = iP;
						Outfit[n][2] = iS;
						n++;
					}
				}
			}
		}


		fprintf(Out, "Case #%d: %d\n", i + 1, n);

		for (j = 0; j < n; j++)
			fprintf(Out, "%d %d %d\n", Outfit[j][0] + 1, Outfit[j][1] + 1, Outfit[j][2] + 1);
	}


	fclose(In);
	fclose(Out);

    return 0;
}
