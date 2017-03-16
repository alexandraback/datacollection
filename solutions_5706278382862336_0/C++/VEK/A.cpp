#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

typedef long long int llint;

llint min(llint a, llint b) {return (a<b)?a:b;}
llint max(llint a, llint b) {return (a>b)?a:b;}

llint log2(llint num) {
	llint log = 0;
	while (num > 0) {
		num >>= 1;
		log++;
	}
	return log;
}

bool isPOf2(llint num) {
	while (num > 1) {
		if (num%2 == 1) return false;
		num >>= 1;
	}
	return true;
}

using namespace std;

unsigned int tesztDB;
llint p, q; //p/q
llint minGen;

int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("A-small-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	string str;
	getline(ifile, str);
	for (i = 0; i < tesztDB; i++) {
		getline(ifile, str);
		p = 0;
		unsigned place;
		for (place = 0; str[place] != '/'; place++) {
			p *= 10;
			p += str[place]-'0';
		}
		q = 0;
		for (place++; place < str.length(); place++) {
			q *= 10;
			q += str[place]-'0';
		}
		bool fail = false;
		if (p == 0) {
			fail = true;
			goto end;
		}
		//TODO: get simplest form
		if (!isPOf2(q)) {
			fail = true;
			goto end;
		}
		minGen = 0;
		while (true) {
			if (p-q/2 >= 0) {
				minGen++;
				break;
			}
			q /= 2;
			minGen++;
		}
		end:
		if (fail) fprintf(ofile, "Case #%d: impossible\n", i+1);
		else fprintf(ofile, "Case #%d: %lld\n", i+1, minGen);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
