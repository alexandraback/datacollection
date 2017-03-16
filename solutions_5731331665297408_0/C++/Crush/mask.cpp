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

int n;
vector<pair<string, int>> zip;

string best;
int was[64];
int cnt = 0;
int path[64][64];
bool go(string cur, VI v) {
	if (cnt == n) {
		best = cur;
		return true;
	}
	REP(i, n) {
		int nv = zip[i].sc;
		if (!was[nv]) {
			for (int j = v.sz - 1; j >= 0; j--)
				if (path[v[j]][nv]) {
					was[nv] = 1;
					cnt++;
					VI vv;
					REP(k, j+1) vv.pb(v[k]);
					vv.pb(nv);

					if (go(cur + zip[i].fs, vv)) return true;
					was[nv] = 0;
					cnt--;
				}
		}
	}
	return false;
}

void testcase(int tst)
{
	int m;
	ifs >> n >> m;

	zip.clear();
	REP(i, n) {
		string s;
		ifs >> s;
		zip.pb(mp(s, i));
	}

	sort(ALL(zip));

	memset(path, 0, sizeof(path));
	REP(k, m) {
		int i, j;
		ifs >> i >> j;
		i--; j--;
		path[i][j] = 1;
		path[j][i] = 1;
	}

	best = "";

	memset(was, 0, sizeof(was));
	REP(i, n) {
		was[zip[i].sc] = 1;
		cnt = 1;
		if (go(zip[i].fs, VI(1, zip[i].sc))) break;
		was[zip[i].sc] = 0;
	}

	ofs << "Case #" << tst+1 << ": " << best << endl;
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
