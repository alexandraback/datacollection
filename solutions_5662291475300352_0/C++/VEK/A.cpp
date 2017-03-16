#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef long long unsigned lluint;

unsigned min(unsigned a, unsigned b) {return (a<b)?a:b;}
unsigned max(unsigned a, unsigned b) {return (a>b)?a:b;}

using namespace std;

struct Hiker {
	unsigned sPos;
	lluint cycleTime;
};

unsigned int testNum, hikerNum, n, d, h;
lluint m;
Hiker hikers[500000];

unsigned getHikerCollNum(unsigned h1, unsigned h2, unsigned i) {
	unsigned collNum = 0;
	if (hikers[h1].sPos > hikers[h2].sPos || (hikers[h1].sPos == hikers[h2].sPos && hikers[h1].cycleTime < hikers[h2].cycleTime))
		collNum++;
	double h1CycleTime = (double)hikers[h1].cycleTime*(360-hikers[h1].sPos)/360.0;
	//cout << h1 << " " << h1CycleTime << endl;
	double h2Place = hikers[h2].sPos + h1CycleTime/(double)hikers[h2].cycleTime;
	//if (i == 1) cout << "|" << h1CycleTime << " " << h2Place << endl;
	while (h2Place > 360.0) {
		h2Place -= 360.0;
		collNum++;
	}
	//if (i == 1) cout << collNum << endl;
	return collNum;
}

int main(int argc, char **argv) {
	ifstream ifile("C-small-1-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> testNum;
	for (unsigned i = 0; i < testNum; i++) {
		ifile >> n;
		hikerNum = 0;
		for (unsigned j = 0; j < n; j++) {
			ifile >> d >> h >> m;
			for (unsigned k = 0; k < h; k++) {
				hikers[hikerNum].sPos = d;
				hikers[hikerNum].cycleTime = m;
				m++;
				hikerNum++;
			}
		}
		/*for (unsigned j = 0; j < hikerNum; j++) {
			cout << hikers[j].sPos << " " << hikers[j].cycleTime << endl;
		}*/
		unsigned minEnc = 2;
		if (hikerNum <= 1) minEnc = 0;
		else {
			minEnc = min(minEnc, getHikerCollNum(0, 1, i));
			minEnc = min(minEnc, getHikerCollNum(1, 0, i));	
		}
		fprintf(ofile, "Case #%d: %d\n", i+1, minEnc);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
