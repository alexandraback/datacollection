#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 


int main() 
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("a.out");

	char m[256], u[256];

	memset(m, 0, sizeof(m));
	memset(u, 0, sizeof(u));

	vector <string> s, a;

	s.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	s.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	s.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

	a.push_back("our language is impossible to understand");
	a.push_back("there are twenty six factorial possibilities");
	a.push_back("so it is okay if you want to just give up");

	REP(i,3) {
		REP(j,s[i].length()) {
			m[s[i][j]] = a[i][j];
			u[a[i][j]] = 1;
		}
	}

	int cnt = 0;
	char unknown = 0, unused = 0;
	REP(i,26) {
		if (m['a'+i] == 0) {
			unknown = 'a'+i;
			cout << "*" << endl;
		}
		if (u['a'+i] == 0)
			unused = 'a'+i;
	}

	cout << unknown << " " << unused << endl;

	m[unknown] = unused;
	m['q'] = 'z';
	m['z'] = 'q';

	int tc;

	fin >> tc;

	string line;

	getline(fin, line);
	REP(tcase,tc) {
		getline(fin, line);
		string res = "";

		REP(i,line.length())
			res += m[line[i]];
		fout << "Case #" << tcase+1 << ": " << res << endl;
	}

	fout.close();

	return 0;
}