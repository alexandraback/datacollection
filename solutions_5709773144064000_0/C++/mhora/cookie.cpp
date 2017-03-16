// cookie.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;


//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	FILE * pFile;
	pFile = fopen("input.in", "r");
	FILE * oFile;
	oFile = fopen("output.txt", "w+");
	int t;
	fscanf(pFile, "%d", &t);
	float c, f, x;
	double rslt;
	double farm;
	for (int i = 0; i < t; i++){
		fscanf(pFile, "%f %f %f", &c, &f, &x);
		farm = max(floor((x - 2.0 * c / f) / c),0.0);
		rslt = 0;
		for (int k = 0; k < farm; k++){
			rslt += (double) c / (k*f + 2.0);
		}
		rslt += (double) x / (farm*f + 2.0);
		fprintf(oFile, "case #%d: %.7f\n", i + 1, rslt);
	}
	fclose(pFile);
	fclose(oFile);
	return 0;
}

