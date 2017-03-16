// GCJ20150A0.cpp : définit le point d'entrée pour l'application console.
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

		// Spécifique
		int nshy,nb;
		vector <int> Shy;

		// Début d'analyse
		// Init
		Res = 0;

		// Extraction
		// Combinaisons
		*FicIn >> nshy;
		*FicIn >> in;
		for (i = 0; i <= nshy; i++)
		{
			Shy.push_back((int)(in[i]-'0'));
		}

		// Exécution
		// Vérification :  chaque bit 1 doit être en nombre pair
		if (Shy[0] == 0) Res++;
		nb = Res + Shy[0];
		for (i = 1; i <= nshy; i++)
		{
			if (nb < i)
			{
				Res += i - nb;
				nb += i - nb;
			}
			nb += Shy[i];
		}

		// Formatage de la sortie

		// Sortie
		sprintf(LOut, "Case #%d: %d\n", Nt,Res);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("A-large.in", ifstream::in);
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

	printf("GCJ20150A0\n");
	P.Perform();

	return 0;
}