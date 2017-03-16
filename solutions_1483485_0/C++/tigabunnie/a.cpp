#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;

/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
*/

int main(int argc, char **argv) {
	ifstream infile;
	ofstream outfile;
	
	assert(argc == 3);
	infile.open(argv[1]);
	if (!infile.is_open()) { cout << "can't open file " << argv[1] << "\n"; exit(1); }
	int numCases;
	infile >> numCases;
	
	outfile.open(argv[2]);
	if (!outfile.is_open()) { cout << "can't open file " << argv[2] << "\n"; exit(1); }
	
	char map[256] = {0};
	
	//translate
	char Googlerese[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char English[]    = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	int len = strlen(Googlerese);
	int i;
	for (i=0; i<len; i++) {
		map[Googlerese[i] & 0xff] = English[i];
	}
	//only q and z are missing, so they must map to each other
	map['q'] = 'z';
	map['z'] = 'q';
//	for (i='a'; i<='z'; i++) if (map[i]==0) cout << "missing translation for " << (char)i << "\n";
	
	char lineBuf[128];
	infile.getline(lineBuf, sizeof(lineBuf));	//flush the "\n" not read in after numCases
	for (int itr=1; itr<=numCases; itr++) {
		infile.getline(lineBuf, sizeof(lineBuf));
		len = strlen(lineBuf);
		for (i=0; i<len; i++) lineBuf[i] = map[lineBuf[i] & 0xff];
		outfile << "Case #" << itr << ": " << lineBuf << "\n";
	}
	infile.close();
	outfile.close();
		
	return 0;
}