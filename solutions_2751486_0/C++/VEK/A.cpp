#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)<(b)?(a):(b))

using namespace std;

unsigned int tesztDB;

string nev;
unsigned int db;
unsigned int *massalHDB;

bool massalH(unsigned int hely) {
	if (!(nev[hely] == 'a' || nev[hely] == 'e' || nev[hely] == 'i' || nev[hely] == 'o' || nev[hely] == 'u')) {
		massalHDB[hely] = 1;
		if (hely != 0) massalHDB[hely] += massalHDB[hely-1];
	} else massalHDB[hely] = 0;
	return (massalHDB[hely] >= db);
}

int main(int argc, char **argv) {
	unsigned int i, j, utolsoJo;
	long long unsigned int valasz, valaszResz;
	FILE *ifile = fopen("A-small-attempt0.in", "r");
	FILE *ofile = fopen("out.txt", "w");
	fscanf(ifile, "%i", &tesztDB);
	char tar;
	for (i = 0; i < tesztDB; i++) {
		nev = "";
		tar = 'A';
		while (tar != ' ') {
			tar = fgetc(ifile);
			if (tar >= 'a') nev += tar;
		}
		fscanf(ifile, "%i", &db);
		massalHDB = new unsigned int[nev.length()];
		utolsoJo = 0;
		valasz = 0;
		for (j = 0; j < db; j++) massalH(j);
		for (j = db-1; j < nev.length(); j++) {
			if (massalH(j)) {
				valaszResz = j+2-db-utolsoJo;
				valaszResz *= (nev.length()-j);
				valasz += valaszResz;
				utolsoJo = j+2-db;
			}
		}
		fprintf(ofile, "Case #%i: %lli\n", i+1, valasz);
		delete[] massalHDB;
	}
	fclose(ifile);
	fclose(ofile);
	return 0;
}
