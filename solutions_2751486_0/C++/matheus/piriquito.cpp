#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#include <iostream>
#include "iostream.h"

typedef long long LL;

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fpIn, *fpOut;
	char cQtd[20];
	int iQtdTotal;

	//pre_calcular();

	fpIn = fopen("A-small-attempt0.in", "r");
	fpOut = fopen("A-small-attempt0.out", "w");

	if (fpIn == NULL)
	{
		std::cout << "Erro ao ler arquivo de entrada!";
		system("pause");
		return 0;
	}
	if (fpOut == NULL)
	{
		cout << "Erro ao ler arquivo de saida!";
 		system("pause");
		return 0;
	}

	fgets(cQtd, 20, fpIn);
	iQtdTotal = strtoul(cQtd, NULL, 10);

	//cout << "Qtd Total: " << iQtdTotal << endl;
    char cSaida[20];

	//-- percorre a primeira linha --//
	for (int i=0; i < iQtdTotal; i++) {
		char linha[300];
		char *cpLinha;
		int resp = 0;
		char a1[100];
		int a2;

		int tam;

		fgets(linha, 300, fpIn);
		cpLinha = strstr(linha, " ");
		strncpy (a1, linha, strlen(linha)-strlen(cpLinha));
		a1[strlen(linha)-strlen(cpLinha)] = 0;
		cpLinha++;
		tam = strlen(a1);
		a2 = strtoull(cpLinha, NULL, 10);	//others_qtd


		//-- percorre a segunda linha --//
		for (int j = 0; j <= tam-a2; j++) {
			int seguidos = 0;
			int m=j;
			int maxim=0;
			for (int k = a2-1; k < tam; k++) {

				while (m <= k) {

					if (a1[m] != 'a' && a1[m] != 'A' &&
							a1[m] != 'e' && a1[m] != 'E' &&
							a1[m] != 'i' && a1[m] != 'I' &&
							a1[m] != 'o' && a1[m] != 'O' &&
							a1[m] != 'u' && a1[m] != 'U') {
								seguidos++;
							}
					else {
						seguidos = 0;
					}
					maxim = max(seguidos,maxim);
					m++;
				}
				if (maxim >= a2) {
					resp++;
				}
			}
			//a2++;
		}

		sprintf(cSaida, "Case #%d: %d\n", i+1, resp);
		fputs(cSaida, fpOut);
	}


	fcloseall();

	system("pause");
}
