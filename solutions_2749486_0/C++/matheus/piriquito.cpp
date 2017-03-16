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

	fpIn = fopen("B-small-attempt1.in", "r");
	fpOut = fopen("B-small-attempt1.out", "w");

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
		char resp[200] = {0};
		LL N;
		LL X, Y;
		int incr = 1;

		fgets(linha, 300, fpIn);
		cpLinha = strstr(linha, " ");
		cpLinha++;
		X = strtoll(linha, NULL, 10);		//armin_mote
		Y = strtoll(cpLinha, NULL, 10);	//others_qtd

		int xMod = (X<0?X*-1:X);
		int yMod = (Y<0?Y*-1:Y);

		int calcX = 0, calcY = 0;

		//-- percorre a segunda linha --//
		if (xMod<yMod) {
			for (calcX=0; calcX!=X; incr++) {
				if (calcX + incr > X ) {
					calcX -= incr;
					resp[incr-1] = 'W';
				}
				else {
					calcX += incr;
					resp[incr-1] = 'E';
				}
			}
			for (calcY=0; calcY!=Y; incr++) {
				if (calcY + incr > Y ) {
					calcY -= incr;
					resp[incr-1] = 'S';
				}
				else {
					calcY += incr;
					resp[incr-1] = 'N';
				}
			}
		}
		else {
			for (calcY=0; calcY!=Y; incr++) {
				if (calcY + incr > Y ) {
					calcY -= incr;
					resp[incr-1] = 'S';
				}
				else {
					calcY += incr;
					resp[incr-1] = 'N';
				}
			}
			for (calcX=0; calcX!=X; incr++) {
				if (calcX + incr > X ) {
					calcX -= incr;
					resp[incr-1] = 'W';
				}
				else {
					calcX += incr;
					resp[incr-1] = 'E';
				}
			}
		}

		//sprintf(cSaida, "Case #%d: %s\n", i+1, resp);
		cout << "Case #" << i+1 << ": ";
		cout << resp << endl;
		//fputs(cSaida, fpOut);
	}


	fcloseall();

	system("pause");
}
