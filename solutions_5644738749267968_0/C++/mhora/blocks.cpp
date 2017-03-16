// blocks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * pFile;
	pFile = fopen("input.in", "r");
	FILE * oFile;
	oFile = fopen("output.txt", "w+");
	int t;
	int n;
	int maxnormal;
	int maxpodvod;
	int kenukaz;
	vector<double> naomi;
	vector<double> ken;
	fscanf(pFile, "%d", &t);
	for (int i = 0; i < t; i++){
		fscanf(pFile, "%d", &n);
		naomi.resize(n, 0);
		ken.resize(n, 0);
		for (int j = 0; j < n; j++){
			fscanf(pFile, "%f", &naomi[j]);
		}
		for (int j = 0; j < n; j++){
			fscanf(pFile, "%f", &ken[j]);
		}
		maxnormal = 0;
		maxpodvod = 0;
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		kenukaz = n - 1;
		for (int j = n - 1; j >= 0; j--){
			if (naomi[j] > ken[kenukaz]){ maxnormal++; }
			else{ kenukaz--; }
		}
		kenukaz = 0;
		for (int j = 0; j < n; j++){
			if (naomi[j] > ken[kenukaz]){ maxpodvod++; kenukaz++; }
			
		}
		fprintf(oFile, "Case #%d: %d %d\n", i + 1, maxpodvod, maxnormal);
	}

	fclose(pFile);
	fclose(oFile);
	return 0;
}

