// GCJ20151BA0.cpp : définit le point d'entrée pour l'application console.
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

	long long Rev(long long n)
	{
		char s[50],s2[50];
		long long r;
		int i,j,k;
		sprintf(s, "%lld", n);
		for (i = 0; i < 50; i++) if (s[i] == 0) break;
		k = 0;
		for (j = i - 1; j >= 0; j--) s2[k++] = s[j];
		s2[k] = 0;
		sscanf(s2, "%lld", &r);
		//printf("%lld %lld\n",n, r);
		return r;
	}


	void PerformLoop()
	{
		int i, j, k, som, tmp;
		char in[10000];
		char LOut[10000];
		long long Res;
		bool possible;

		// Spécifique
		long long Nb,puis10;

		// Début d'analyse
		// Init
		Res = 1;
		puis10 = 100000000;

		// Extraction
		// 
		*FicIn >> Nb;

		//Exec
		while (Nb != 1)
		{
			while (puis10*puis10 / 10 > Nb) puis10 /= 10;
			if (Nb % puis10 != 1) Nb--;
			else
			{
				if (Rev(Nb) > Nb - 1) Nb--;
				else Nb = Rev(Nb);
			}
			Res++;
		}




		// Formatage de la sortie

		// Sortie
		sprintf(LOut, "Case #%d: %d\n", Nt, Res);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("A-small-attempt0.in", fstream::in);
		FicOut = new fstream("Fichier.out", fstream::out);
		if (FicIn->fail()){ printf("Impossible d'ouvrir le fichier d'entree\n"); return; }
		if (FicOut->fail()){ printf("Impossible d'ouvrir le fichier de sortie\n"); return; }

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

	printf("GCJ20151BA0\n");
	P.Perform();

	return 0;
}