#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

double min(double a, double b) {return (a<b)?a:b;}
double max(double a, double b) {return (a>b)?a:b;}

using namespace std;

unsigned int tesztDB;
double cost, cInc, winC;
double t, cPs, cNum;
double minTime;

int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("B-small-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> cost;
		ifile >> cInc;
		ifile >> winC;
		cPs = 2.0;
		cNum = 0.0;
		t = 0.0;
		minTime = winC/cPs;
		while (true) {
			t += cost/cPs;
			cPs += cInc;
			if (minTime < t+winC/cPs) break;
			else minTime = t+winC/cPs;
		}
		fprintf(ofile, "Case #%d: %.7f\n", i+1, minTime);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
