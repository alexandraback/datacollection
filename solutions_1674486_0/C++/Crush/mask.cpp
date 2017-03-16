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

VI was;
VVI a;

bool dfs(int v) {
	if (was[v])
		return false;

	was[v] = 1;
	REP(i, a[v].sz) {
		if (!dfs(a[v][i]))
			return false;
	}

	return true;
}

void testcase(int tst)
{
	int n;
	ifs >> n;

	a.assign(n, VI());

	REP(i, n) {
		int m;
		ifs >> m;
		REP(j, m) {
			int x;
			ifs >> x;
			x--;
			a[i].pb(x);
		}
	}

	ofs << "Case #" << tst+1 << ": ";

	REP(i, n) {
		was.assign(n, 0);
		if (!dfs(i)) {
			ofs << "Yes" << endl;
			return;
		}
	}

	ofs << "No" << endl;


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
