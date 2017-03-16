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

VI a, b, k;
int n;

ll was[100][2][2][2];

ll go(int i, int la, int lb, int lk) {
	if (i == -1) return 1;
	ll& res = was[i][la][lb][lk];
	if (res > -1) return res;

	res = 0;

	int ma = la ? 2 : (a[i] + 1);
	int mb = lb ? 2 : (b[i] + 1);

	REP(ia, ma)
		REP(ib, mb) {
			int na = la, nb = lb, nk = lk;
			if (ia < a[i]) na = 1;
			if (ib < b[i]) nb = 1;
			if ((ia & ib) < k[i]) nk = 1;
			if (((ia & ib) > k[i]) && nk == 0) continue;
			res += go(i-1, na, nb, nk); 
		}

	return res;
}

void testcase(int tst)
{
	int ai, bi, ki;
	ifs >> ai >> bi >> ki;
	ai--;
	bi--;
	ki--;

	a.clear();
	while (ai > 0) {
		a.pb(ai % 2);
		ai /= 2;
	}

	b.clear();
	while (bi > 0) {
		b.pb(bi % 2);
		bi /= 2;
	}

	k.clear();
	while (ki > 0) {
		k.pb(ki % 2);
		ki /= 2;
	}

	n = max(k.sz, max(a.sz, b.sz));

	while (a.sz < n) a.pb(0);
	while (b.sz < n) b.pb(0);
	while (k.sz < n) k.pb(0);

	memset(was, -1, sizeof(was));
	ofs << "Case #" << tst+1 << ": " << go(n-1, 0, 0, 0) << endl;
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
