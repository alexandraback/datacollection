// GCJ20150C0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
// Ci-dessous pour ne plus être gêné par les erreur de compilation
// dûes à scanf, strcpy, etc...
// sans pour autant à chaque fois devoir redéfinir _CRT_SECURE_NO_WARNINGS
// dans la définition du préprocessseur (Projet>Propriétés>Conf>C/C++>Préprocesseur/Définitions)
#pragma warning(disable: 4996) /* Disable deprecation */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string.h>

using namespace std;

class Perf
{
public:

	int CalcProd(int a, int b)
	{
		static int Produit[5][5] =
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 3, 4 },
			{ 0, 2, -1, 4, -3 },
			{ 0, 3, -4, -1, 2 },
			{ 0, 4, 3, -2, -1 }
		};
		int absa, absb, signe;
		if ((a*b) >= 0) signe = 1; else signe = -1;
		if (a >= 0)absa = a; else absa = -a;
		if (b >= 0)absb = b; else absb = -b;
		return signe*Produit[absa][absb];
	}

	void PerformLoop()
	{
		int i, j, k, som, tmp;
		char in[20000];
		char LOut[10000];
		int Res;

		// Spécifique
		int Left[10001], Right[10001],Ch[10000],ValCh, ChPuis[4];
		int L,p,modX,n1,n2,n3,x1,x2,p1,p2,p3;
		long long X;
		bool possible;

		// Début d'analyse
		// Init
		Res = 0;

		// Extraction
		// 
		*FicIn >> L;
		*FicIn >> X;
		*FicIn >> in;

		for (i = 0; i < L; i++)
		{
			if (in[i] == 'i') Ch[i] = 2;
			if (in[i] == 'j') Ch[i] = 3;
			if (in[i] == 'k') Ch[i] = 4;
		}

		// Exécution
		// On fabrique les données d'entrée :
		p = 1;
		Left[0] = 1;
		Right[0] = 1;
		for (i = 1; i <= L; i++)
		{
			Left[i] = CalcProd(Left[i - 1], Ch[i - 1]);
			Right[i] = CalcProd(Ch[L - i],Right[i - 1]);
		}
		ValCh = Left[L];
		ChPuis[0] = 1;
		for (i = 1; i < 4; i++) ChPuis[i] = CalcProd(ChPuis[i - 1], ValCh);

		modX = X % 4;

		// On tente d'obtenir i, j et k (2, 3 et 4) :
		possible = false;
		if (X >= 2)
		{
			for (n1 = 0; n1 < 4; n1++)
			{
				for (x1 = 0; x1 <= L; x1++)
				{
					if (CalcProd(ChPuis[n1], Left[x1]) != 2) continue;
					for (n2 = 0; n2 < 4; n2++)
					{
						for (x2 = 0; x2 <= L; x2++)
						{
							if (CalcProd(CalcProd(Right[L - x1], ChPuis[n2]), Left[x2]) != 3)
								continue;
							for (n3 = 0; n3 < 4; n3++)
							{
								if (CalcProd(Right[L - x2], ChPuis[n3]) != 4)
									continue;
								if ((n1 + n2 + n3+2) % 4 != modX) continue;
								if ((n1 + n2 + n3)+2 > X )continue;
								possible = true;
								printf("Cas 1\n");
								break;
							}
							if (possible) break;
						}
						if (possible) break;
					}
					if (possible) break;
				}
				if (possible) break;
			}
		}

		// Cas particulier X=1 :
		if (X==1)
		{
			// On essaie au sein de la même chaîne
			for (x1 = 0; x1 < L - 2; x1++)
			{
				if (Left[x1+1] != 2) continue;
				p2 = 1;
				for (x2 = x1 + 1; x2 < L - 1; x2++)
				{
					p2 = CalcProd(p2, Ch[x2]);
					if (p2 != 3) continue;
					if (Right[L - x2 - 1] == 4)
					{
						possible = true;
						break;
					}
				}
				if (possible) break;
			}
		}

		// Dernière tentative : j est dans la même chaîne que i ou k
		if ((!possible) && (X>=2))
		{
			// On teste j dans la chaîne de i ou de k :
			for (n1 = 0; n1 < 4; n1++)
			{
				for (x1 = 0; x1 <= L-1; x1++)
				{
					if (CalcProd(ChPuis[n1], Left[x1]) != 2) continue;
					for (n2 = 0; n2 < 1; n2++)
					{
						p2 = 1;
						for (x2 = x1; x2 < L ; x2++)
						{
							p2 = CalcProd(p2, Ch[x2]);
							if (p2 != 3) continue;
							for (n3 = 0; n3 < 4; n3++)
							{
								if (CalcProd(Right[L - x2-1], ChPuis[n3]) != 4)
									continue;
								if ((n1 + n2 + n3+1) % 4 != modX) continue;
								if ((n1 + n2 + n3)+1 > X)continue;
								possible = true;
								printf("Cas 2\n");
								break;
							}
							if (possible) break;
						}
						if (possible) break;
					}
					if (possible) break;
				}
				if (possible) break;
			}
		}


		// Formatage de la sortie

		// Sortie
		if (possible) sprintf(LOut, "Case #%d: YES\n", Nt);
		else sprintf(LOut, "Case #%d: NO\n", Nt);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("C-large.in", ifstream::in);
		FicOut = new fstream("Fichier.out", ifstream::out);

		// Nombre de Tests
		*FicIn >> T;

		for (Nt = 1; Nt <= T; Nt++) PerformLoop();

		// Fermeture des fichiers
		FicIn->close();
		FicOut->close();
	}

	int T, Nt;
	fstream *FicIn;
	fstream *FicOut;


};

int main(int argc, char** argv)
{
	Perf P;

	printf("GCJ20150C0\n");
	P.Perform();

	return 0;
}