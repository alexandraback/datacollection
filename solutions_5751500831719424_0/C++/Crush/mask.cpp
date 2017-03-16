#pragma warning(disable:4786)

#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <sstream>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
typedef pair<int,int> PII;
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz size()

ifstream ifs;
ofstream ofs;

typedef long long ll;

void testcase(int tst)
{
	int n;
	ifs >> n;

	vector<vector<pair<char, int> > > a;
	REP(i, n) {
		vector<pair<char, int> > b;
		string s;
		ifs >> s;
		REP(j, s.length()) {
			if (j > 0 && s[j] == s[j-1]) {
				b.back().sc++;
			} else {
				b.pb(mp(s[j], 1));
			}
		}
		a.pb(b);
	}

	REP(j, n)
		REP(i, j) {
			if (a[i].sz != a[j].sz) { ofs << "Case #" << tst+1 << ": " << "Fegla Won" << endl; return; }
			REP(k, a[i].sz)
				if (a[i][k].fs != a[j][k].fs) { ofs << "Case #" << tst+1 << ": " << "Fegla Won" << endl; return; }
		}

	int res = 0;
	REP(k, a[0].sz) {
		int mn = 10000000000;
		for (int l = 1; l <= 100; l++) {
			int sm = 0;
			REP(i, n) sm += abs(a[i][k].sc-l);
			if (sm < mn) mn = sm;
		}
		res += mn;
	}

	ofs << "Case #" << tst+1 << ": " << res << endl;
}

int main()
{
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	int t;
	ifs >> t;
	REP(tn, t)
	{
		testcase(tn);
	}

	return 0;
} 
