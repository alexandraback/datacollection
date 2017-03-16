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

	fpIn = fopen("LARGE.in", "r");
	fpOut = fopen("lixo.out", "w");

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
		cout << "Case #" << i+1 << ": ";

		//-- percorre a segunda linha --//
		if (xMod<yMod) {
			calcY=0;
			for (calcX=0; calcX!=X; incr++) {
				if (Y == incr && X!=Y) {
					calcY = incr;
					if (Y > 0) {
						cout << "N";
					}
					else {
						cout << "S";
					}
				}
				else if (calcX + incr > X ) {
					calcX -= incr;
					cout << "W";
				}
				else {
					calcX += incr;
					cout << "E";
				}
			}
			for (; calcY!=Y; incr++) {
				if (calcY + incr > Y ) {
					calcY -= incr;
					cout << "S";
				}
				else {
					calcY += incr;
					cout << "N";
				}
			}
		}
		else {
			calcX=0;
			for (calcY=0; calcY!=Y; incr++) {
				if (X == incr X!=Y) {
					calcX = incr;
					if (X > 0) {
						cout << "E";
					}
					else {
						cout << "W";
					}
				}
				else if (calcY + incr > Y ) {
					calcY -= incr;
					cout << "S";
				}
				else {
					calcY += incr;
					cout << "N";
				}
			}
			for (; calcX!=X; incr++) {
				if (calcX + incr > X ) {
					calcX -= incr;
					cout << "W";
				}
				else {
					calcX += incr;
					cout << "E";
				}
			}
		}

		cout << endl;
		//sprintf(cSaida, "Case #%d: %s\n", i+1, resp);
		//fputs(cSaida, fpOut);
	}


	fcloseall();

}
