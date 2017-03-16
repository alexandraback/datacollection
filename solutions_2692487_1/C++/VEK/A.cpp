#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)<(b)?(a):(b))

using namespace std;

unsigned int tesztDB, rDB;
long long unsigned int *rMeretek, aMeret, *minLSzam;

long long unsigned int kiszamitMinErtek(unsigned int hely, long long unsigned int meret) {
	if (hely >= rDB) return 0;
	long long unsigned int valasz;
	if (meret > rMeretek[hely]) {
		valasz = kiszamitMinErtek(hely+1, meret+rMeretek[hely]);
		//printf("_%i: %lli (%lli > %lli)\n", hely+1, valasz, meret, rMeretek[hely]);
		return valasz;
	}
	valasz = rDB-hely;
	long long unsigned int ujMeret = meret, valasz2 = 0;
	if (meret == 1) {
		//printf("|%i: %lli\n", hely+1, valasz);
		return valasz;
	}
	while (ujMeret <= rMeretek[hely]) {
		ujMeret += ujMeret-1;
		valasz2++;
	}
	//printf("%i: ::%lli, %lli\n", hely+1, valasz2, ujMeret);
	valasz2 += kiszamitMinErtek(hely+1, ujMeret+rMeretek[hely]);
	//printf("%iB: ::%lli, %lli\n", hely+1, valasz2, ujMeret);
	//printf("%i: %lli\n", hely+1, min(valasz, valasz2));
	return min(valasz, valasz2);
}

int main(int argc, char **argv) {
	unsigned int i, j, k, temp;
	ifstream ifile("A-large.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> aMeret >> rDB;
		rMeretek = new long long unsigned int[rDB];
		minLSzam = new long long unsigned int[rDB];
		for (j = 0; j < rDB; j++) {
			ifile >> rMeretek[j];
		}
		for (j = 0; j < rDB-1; j++) {
			for (k = j; k < rDB; k++) {
				if (rMeretek[j] > rMeretek[k]) {
					temp = rMeretek[j];
					rMeretek[j] = rMeretek[k];
					rMeretek[k] = temp;
				}
			}
		}
		//printf("%lli\n", aMeret);
		//for (j = 0; j < rDB; j++) printf("%lli ", rMeretek[j]);printf("\n");
		printf("Case #%i: %lli\n", i+1, kiszamitMinErtek(0, aMeret));
		fprintf(ofile, "Case #%i: %lli\n", i+1, kiszamitMinErtek(0, aMeret));
		delete[] minLSzam;
		delete[] rMeretek;
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
