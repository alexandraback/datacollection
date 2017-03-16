#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)<(b)?(a):(b))

using namespace std;

unsigned int tesztDB;
int vegX, vegY;

int main(int argc, char **argv) {
	unsigned int i, j, lepesDB;
	string valasz;
	ifstream ifile("B-small-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> vegX >> vegY;
		valasz = "";
		if (vegX == 0) {
			lepesDB = abs(vegY)-1;
			for (j = 0; j < lepesDB; j++) {
				if (vegY > 0) valasz += "NS";
				else valasz += "SN";
			}
			if (vegY > 0) valasz += "N";
			else valasz += "S";
		} else {
			lepesDB = abs(vegX)-1;
			for (j = 0; j < lepesDB; j++) {
				if (vegX > 0) valasz += "EW";
				else valasz += "WE";
			}
			if (vegX > 0) valasz += "E";
			else valasz += "W";
			lepesDB = abs(vegY);
			for (j = 0; j < lepesDB; j++) {
				if (vegY > 0) valasz += "SN";
				else valasz += "NS";
			}
		}
		printf("Case #%i: %s\n", i+1, valasz.c_str());
		fprintf(ofile, "Case #%i: %s\n", i+1, valasz.c_str());
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
