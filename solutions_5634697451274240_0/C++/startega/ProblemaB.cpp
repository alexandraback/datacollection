
#include "stdafx.h"
#include <stdio.h>
#include <string.h>


int main()
{
	FILE *In, *Out;
	long n;
	long i, j, k;

	char cadena[101];
	long lNum0, lNum;
	long p;
	int lon;
	unsigned char ant;

	In = fopen("B-small-attempt0.in", "r");
	//In = fopen("prueba.txt", "r");
	//In = fopen("A-large.in", "r");

	Out = fopen("B-small-attempt0.out", "w");
	//Out = fopen("prueba.out", "w");
	//Out = fopen("A-large.out", "w");

	fscanf(In, "%d", &n);


	for (i = 0; i < n; i++)
	{
		fscanf(In, "%s", cadena);
		printf("%s\n", cadena);

		lon = strlen(cadena);
		p = 0;

		while (1)
		{
			for (j = 1; j < lon && cadena[j] == cadena[j - 1]; j++);

			if (j == lon)
			{
				if (cadena[0] == '+')
					fprintf(Out, "Case #%d: %d\n", i + 1, p);
				else
					fprintf(Out, "Case #%d: %d\n", i + 1, p + 1);
				break;
			}

			for (k = 0; k < j ; k++)
			{
				if (cadena[k] == '+')
					cadena[k] = '-';
				else
					cadena[k] = '+';
			}
			p++;
		}
	}

	fclose(In);
	fclose(Out);

    return 0;
}

