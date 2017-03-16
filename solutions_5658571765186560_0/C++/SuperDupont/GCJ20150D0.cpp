// GCJ20150D0.cpp : définit le point d'entrée pour l'application console.
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



	void PerformLoop()
	{
		int i, j, k, som, tmp;
		char in[10000];
		char LOut[10000];
		int Res;
		bool possible;

		// Spécifique
		int X,R,C;

		// Début d'analyse
		// Init
		Res = 0;
		possible = false;

		// Extraction
		// 
		*FicIn >> X;
		*FicIn >> R;
		*FicIn >> C;

		//Exec
		// Pour le small, pas de pb, au cas par cas :
		if (X == 1)
		{
			possible = true;
		}

		if (X == 2)
		{
			if (((R*C) % 2 == 0) && ((R>1) || (C>1))) possible = true;
		}

		if (X == 3)
		{
			if (((R*C) % 3 == 0) && ((R>1) && (C>1)) && ((R>=3) || (C>=3))) possible = true;
		}

		if (X == 4)
		{
			if (((R*C) % 4 == 0) && ((R > 2) && (C > 2)) && ((R >= 4) || (C >= 4)))
			{

				possible = true;
			}
		}



		// Formatage de la sortie

		// Sortie
		if (possible) sprintf(LOut, "Case #%d: GABRIEL\n", Nt);
		else sprintf(LOut, "Case #%d: RICHARD\n", Nt);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("D-small-attempt0.in", ifstream::in);
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

	printf("GCJ20150D0\n");
	P.Perform();

	return 0;
}