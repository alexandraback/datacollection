// miny2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
//int main()
{
	FILE * pFile;
	pFile = fopen("input.in", "r");
	FILE * oFile;
	oFile = fopen("output.txt", "w+");
	int t;
	char pole[60][60];
	fscanf(pFile, "%d", &t);
	int r, c, m;
	int polozeno = 0;
	for (int i = 0; i < t; i++){
		fprintf(oFile, "Case #%d:\n", i + 1);
		fscanf(pFile, "%d %d %d", &r, &c, &m);
		for (int j = 0; j < r; j++){
			for (int k = 0; k < c; k++){
				pole[j][k] = '*';
			}
		}
		polozeno = r*c;
		polozeno--;
		pole[0][0] = 'c';
		if (r == 1){ 
			int ukaz = 1;
			while (polozeno > m && ukaz < c){ pole[0][ukaz] = '.'; ukaz++; polozeno--; }
		}
		else if (c == 1){
			int ukaz = 1;
			while (polozeno > m && ukaz < r){ pole[ukaz][0] = '.'; ukaz++; polozeno--; }
		}
		else if (r == 2){
			if (polozeno - m >= 3 && m % 2 == 0){
				int ukaz = 1;
				pole[1][0] = '.'; polozeno--;
				while (polozeno > m && ukaz < c){ pole[0][ukaz] = '.'; pole[1][ukaz] = '.'; ukaz += 1; polozeno -= 2; }
			}
		}
		else if (c == 2){
			if (polozeno - m >= 3 && m % 2 == 0){
				int ukaz = 1;
				pole[0][1] = '.'; polozeno--;
				while (polozeno > m && ukaz < r){ pole[ukaz][0] = '.'; pole[ukaz][1] = '.'; ukaz += 1; polozeno -= 2; }
			}
		}
		else{
			if (polozeno - m >= 3){
				pole[0][1] = '.'; pole[1][1] = '.'; pole[1][0] = '.'; polozeno -= 3;
				if (polozeno - m >= 2){
					pole[0][2] = '.'; pole[1][2] = '.'; polozeno -= 2;
					if (polozeno - m >= 2){
						pole[2][0] = '.'; pole[2][1] = '.'; polozeno -= 2;
						int xukaz = 3; int yukaz = 3;
						while (polozeno - m >= 2 && xukaz < c){ pole[0][xukaz] = '.'; pole[1][xukaz] = '.'; xukaz++; polozeno -= 2; }
						while (polozeno - m >= 2 && yukaz < r){ pole[yukaz][0] = '.'; pole[yukaz][1] = '.'; yukaz++; polozeno -= 2; }
						yukaz = 2; xukaz = 2;
						while (polozeno - m >= 1 && yukaz < r){ 
							while (polozeno - m >= 1 && xukaz < c){ pole[yukaz][xukaz] = '.'; xukaz++; polozeno--; }
							xukaz = 2; yukaz++;
						}
					}
				}
			}
		}

		if (polozeno != m){ fprintf(oFile, "Impossible\n"); }
		else{
			for (int j = 0; j < r; j++){
				for (int k = 0; k < c; k++){
					fprintf(oFile, "%c", pole[j][k]);
				}
				fprintf(oFile, "\n");
			}
			//fprintf(oFile, "%d %d\n",m, m - polozeno);
		}
	}
	fclose(pFile);
	fclose(oFile);
	return 0;
}

