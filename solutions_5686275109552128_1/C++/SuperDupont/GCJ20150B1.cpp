// GCJ20150B1.cpp : définit le point d'entrée pour l'application console.
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

	int Duree(vector <int> *p)
	{
		int i, ret;
		ret = 0;
		for (i = 0; i < (*p).size(); i++) if ((*p)[i]>ret) ret = (*p)[i];
		return ret;
	}

	void PerformLoop()
	{
		int i, j, k, som, tmp;
		char in[10000];
		char LOut[10000];
		int Res;

		// Spécifique
		int ndepart, nbspec, imax, max, n1, n2, dt,dt0;
		vector <int> Pcakes;

		// Début d'analyse
		// Init
		Res = 0;

		// Extraction
		// Combinaisons
		*FicIn >> ndepart;
		for (i = 0; i < ndepart; i++)
		{
			*FicIn >> tmp;
			Pcakes.push_back(tmp);
		}



		// Exécution
		// 
		nbspec = 0;
		dt0 = Duree(&Pcakes);
		Res = dt0;
		// On tente toutes les dt jusqu'à 1
		for (dt = 1; dt < dt0;dt++)
		{
			nbspec = 0;
			for (i = 0; i < Pcakes.size(); i++)
			{
				if (Pcakes[i] <= dt) continue;
				nbspec += Pcakes[i] / dt-1;
				if ((Pcakes[i] % dt) != 0)nbspec++;
			}
			if ((dt + nbspec) < Res) Res = dt + nbspec;
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
		FicIn = new fstream("B-large.in", ifstream::in);
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

	printf("GCJ20150B1\n");
	P.Perform();

	return 0;
}