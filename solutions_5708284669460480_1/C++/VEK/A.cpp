#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

unsigned int testNum, keyNum, targetL, totalLetters;
double keyProb[26];
string target;

int main(int argc, char **argv) {
	ifstream ifile("B-large.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> testNum;
	string keys;
	for (unsigned i = 0; i < testNum; i++) {
		ifile >> keyNum >> targetL >> totalLetters;
		getline(ifile, keys);
		getline(ifile, keys);
		//cout << "K: " << keys << endl;
		for (unsigned j = 0; j < 26; j++) keyProb[j] = 0;
		for (unsigned j = 0; j < keyNum; j++) {
			keyProb[keys[j]-'A'] += 1.0/keyNum;
		}
		getline(ifile, target);
		//cout << "T: " << target << endl;
		double expCost = 0.0;
		double oneExp = 1.0;
		unsigned maxPayment = 0;
		unsigned targetRepStart = targetL;
		unsigned place;
		for (unsigned j = 0; j < targetL; j++) {
			if (keyProb[target[j]-'A'] < 1.0/(keyNum+1)) {
				goto end;
			}
			oneExp *= keyProb[target[j]-'A'];
		}
		for (unsigned j = 1; j < targetL; j++) {
			for (unsigned k = j; k < targetL; k++) {
				if (target[(k-j) % k] != target[k])
					break;
				if (k+1 == targetL) {
					targetRepStart = j;
					goto loopEnd;
				}
			}
		}
		loopEnd:
		//cout << targetRepStart << endl;
		place = targetL-targetRepStart, maxPayment = 0;
		while (place+targetRepStart <= totalLetters) {
			place += targetRepStart;
			maxPayment++;
			//cout << "| " << place << " " << maxPayment << endl;
		}
		//cout << maxPayment << endl;
		for (place = 0; place+targetL <= totalLetters; place++) {
			expCost += oneExp;
		}
		end:
		printf("Case #%d: %f\n", i+1, maxPayment-expCost);
		fprintf(ofile, "Case #%d: %f\n", i+1, maxPayment-expCost);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
