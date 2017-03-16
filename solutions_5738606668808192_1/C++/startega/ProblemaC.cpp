
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

long Primo(long n);

int main()
{
	FILE *In, *Out;
	long T, N, J;
	long i, j, k;
	
	int base;
	long double Numero;

	unsigned char cadena[32];
	unsigned long factor;
	long div[9];
	int nSol;
	long resto, resto0;
	long primo[1000];
	long ip, n;

	//In = fopen("C-small-attempt1.in", "r");
	//In = fopen("prueba.txt", "r");
	In = fopen("C-large.in", "r");

	//Out = fopen("C-small-attempt1.out", "w");
	//Out = fopen("prueba.out", "w");
	Out = fopen("C-large.out", "w");

	fscanf(In, "%d", &T);
	fscanf(In, "%d", &N);
	fscanf(In, "%d", &J);

	nSol = 0;
	
	n = 2;
	ip = 0;
	while (1)
	{
		if (!Primo(n))
		{
			primo[ip] = n;
			ip++;
			if (ip == 1000)
				break;
		}
		n++;
	}


	fprintf(Out, "Case #1:\n");

	cadena[0] = 1;
	for (i = 1; i < N - 1; i++)
		cadena[i] = 0;
	cadena[N - 1] = 1;
	/*
	cadena[0] = 1;
	cadena[1] = 1;
	cadena[2] = 1;
	cadena[3] = 0;
	cadena[4] = 1;
	cadena[5] = 1;
	*/

	while (1)
	{
		for (base = 2; base < 11; base++)
		{
			for (ip = 0; ip < 1000; ip++)
			{
				resto = 0;
				for (i = 0; i < N; i++)
				{
					if (cadena[i])
					{
						resto0 = 1;
						for (j = 0; j < i; j++)
							resto0 = (resto0 * base)%primo[ip];
						resto += resto0;
					}
				}

				if (resto % primo[ip] == 0)
				{
					div[base - 2] = primo[ip];
					break;
				}
			}
			if (ip == 1000)
				break;
		}

		if (base == 11)
		{
			nSol++;

			for (i = 0; i < N; i++)
				fprintf(Out, "%d", cadena[N - i - 1]);

			for (i = 0; i < 9; i++)
				fprintf(Out, " %d", div[i]);

			fprintf(Out, " \n");
		}

		if (nSol == J)
			break;

		//Siguiente
		for (i = 1; i < N && cadena[i] == 1; i++)
			cadena[i] = 0;
		cadena[i] = 1;
	}


	fclose(In);
	fclose(Out);

    return 0;
}

long Primo(long n)
{
	long p;

	for (p = 2; p < n && p < pow(n, 0.5) + 1; p++)
	{
		if (n % p == 0)
			return p;
	}

	return 0;
}
