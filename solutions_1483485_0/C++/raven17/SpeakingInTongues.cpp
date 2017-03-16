#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

string g[] = {
 "ejp mysljylc kd kxveddknmc re jsicpdrysi",
 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

string e[] = {
 "our language is impossible to understand",
 "there are twenty six factorial possibilities",
 "so it is okay if you want to just give up"
};

string table(256, ' ');

int main() {
	ifstream in("SpeakingInTongues.in");
	ofstream out("SpeakingInTongues.out");
	table['\0'] = '\0';
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < g[i].size(); ++j)
			table[g[i][j]] = e[i][j];
	
	table['q'] = 'z';
	table['z'] = 'q';
	
	int nc;
	in >> nc; in.get();
	
	
	
	char bin[117], bout[117];
	for (int i = 1; i <= nc; ++i) {
		in.getline(bin, 110);
		char *p = bin;
		char *q = bout;
		while (*q++ = table[*p++]) {}
		out << "Case #" << i << ": " << bout << '\n';
	}
	return 0;
}
