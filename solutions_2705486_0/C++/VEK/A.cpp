#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define SZODB 521196

using namespace std;

int min(int a, int b) {
	return (a<b?a:b);
}
int max(int a, int b) {
	return (a>b?a:b);
}

unsigned int tesztDB;
unsigned int mValt[4000], mValtHossz;
bool volt[4000];
string szavak[SZODB], szo;

int valtozas(string nezettSzo, unsigned int kezd) {
	unsigned int valasz = 0;
	if (nezettSzo.length() > szo.length()-kezd) {
		return -1;
	}
	//cout << nezettSzo << endl;
	for (unsigned int i = 0; i < nezettSzo.length(); i++) {
		if (nezettSzo[i] == szo[i+kezd]) continue;
		if (nezettSzo[i] >= szo[i+kezd]+5 ||  szo[i+kezd] >= nezettSzo[i]+5) {
			valasz++;
		} else return -1;
	}
	//cout << valasz << " " << nezettSzo << endl;
	return valasz;
}

unsigned int kovJoSzoValt(unsigned int *hely, unsigned int kezd) {
	for (unsigned int i = *hely; i < SZODB; i++) {
		if (valtozas(szavak[i], kezd) != -1) {
			*hely = i+1;
			return valtozas(szavak[i], kezd);
		}
	}
	*hely = SZODB+1;
	return 0;
}

unsigned int minValtozas(unsigned int kezd) {
	if (kezd >= mValtHossz) return 0;
	if (!volt[kezd]) {
		volt[kezd] = true;
		unsigned int hely = 0, ertek = 0;
		while (hely < SZODB) {
			ertek = kovJoSzoValt(&hely, kezd);
			if (hely == SZODB+1) break;
			//cout << ertek << " " << hely << endl;
			mValt[kezd] = min(mValt[kezd], ertek+minValtozas(kezd+szavak[hely-1].length()));
		}
	}
	return mValt[kezd];
}

int main(int argc, char **argv) {
	unsigned int i, j;
	ifstream ifile("words.txt");
	for (i = 0; i < SZODB; i++) {
		getline(ifile, szavak[i]);
	}
	ifile.close();
	//ifile.open("in.txt");
	ifile.open("C-small-attempt1.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	getline(ifile, szo);
	for (i = 0; i < tesztDB; i++) {
		getline(ifile, szo);
		mValtHossz = szo.length();
		for (j = 0; j < mValtHossz; j++) {
			volt[j] = false;
			mValt[j] = 120000;
		}
		printf("processing case #%i...\n", i+1);
		//printf("Case #%i: %i\n", i+1, minValtozas(0));
		fprintf(ofile, "Case #%i: %i\n", i+1, minValtozas(0));
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
