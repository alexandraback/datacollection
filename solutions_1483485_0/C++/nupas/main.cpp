#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
#include <stack>
#include <list>
#include <cstring>
#include <fstream>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define REP(i,e) for (int i = 0; i < int(e); ++i)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(a,b) ((a) < (b) ? (a):(b))
#define SQR(a) ((a)*(a))

const char probname = 'A';
const bool largeset = false;
const char* suffix = "-attempt0";

string encoded = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string decoded = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
	char buffer[1234];
	sprintf(buffer, "%c-%s%s.in", probname, largeset ? "large" : "small", suffix);
	ifstream fin(buffer);
	sprintf(buffer, "%c-%s%s.out", probname, largeset ? "large" : "small", suffix);
	ofstream fout(buffer);

	char mapping[26] = {0};
	mapping['q' - 'a'] = 'z';
	mapping['z' - 'a'] = 'q';
	REP(i, encoded.size()) {
		if (encoded[i] == ' ') continue;
		mapping[encoded[i] - 'a'] = decoded[i];
	}
	//sanity check
//	int cnt = 0;
//	REP(i, 26) if (mapping[i] > 0) cnt++;
//	cerr << cnt << endl; //should be 26;


	int testCases;
	fin.getline(buffer, 200);
	sscanf(buffer, "%d", &testCases);

	REP(testCase, testCases) {
		fin.getline(buffer, 200);

		fout << "Case #" << testCase + 1 << ": ";
		REP(i, strlen(buffer)) {
			if (buffer[i] == ' ') fout << ' ';
			else fout << mapping[buffer[i] - 'a'];
		}
		fout << endl;
	}

	fin.close();
	fout.close();
}
