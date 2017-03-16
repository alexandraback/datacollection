
#include "stdafx.h"
#include <stdio.h>
#include <string.h>


int main()
{
	FILE *In, *Out;
	long n;
	long i, j, k;
	unsigned char dig[10];

	char sNum[100];
	long lNum0, lNum;
	long p;

	//In = fopen("A-small-attempt2.in", "r");
	//In = fopen("prueba.txt", "r");
	In = fopen("A-large.in", "r");

	//Out = fopen("A-small-attempt2.out", "w");
	Out = fopen("A-large.out", "w");

	fscanf(In, "%d", &n);

	printf("%d\n", n);

	for (i = 0; i < n; i++)
	{
		memset(dig, 0, 10);

		fscanf(In, "%d", &lNum0);

		printf("%d\n", lNum0);

		if (lNum0 == 0)
		{
			fprintf(Out, "Case #%d: INSOMNIA\n",i + 1);
			continue;
		}

		p = 1;
		lNum = lNum0;

		while (1)
		{
			printf("\t%d\n", lNum);
			sprintf(sNum, "%d", lNum);

			for (j = 0; sNum[j]; j++)
				dig[sNum[j] - 48] = 1;

			for (k = 0; k < 10; k++)
			{
				if (!dig[k])
					break;
			}
			if (k == 10)
			{
				fprintf(Out, "Case #%d: %d\n", i+ 1, lNum);
				break;
			}
			lNum += lNum0;
		}
	}

	fclose(In);
	fclose(Out);

    return 0;
}

