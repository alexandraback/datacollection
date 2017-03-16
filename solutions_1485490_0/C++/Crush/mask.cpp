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

int n, m;
vector<ll> a, A;
vector<ll> b, B;

ll was[128][128];

ll go(int i, int j) {

	if (i >= n) return 0;
	if (j >= m) return 0;

	ll& res = was[i][j];
	if (res > -1)
		return res;

	res = 0;

	res = max(res, go(i+1, j));
	res = max(res, go(i, j+1));

	if (A[i] == B[j]) {
		for (int ni = i+1; ni <= n; ni++)
			for (int nj = j+1; nj <= m; nj++) {
				ll na = 0, nb = 0;
				for (int mi = i; mi < ni; mi++)
					if (A[i] == A[mi])
						na += a[mi];
				for (int mj = j; mj < nj; mj++)
					if (B[j] == B[mj])
						nb += b[mj];
				res = max(res, go(ni, nj) + min(na, nb));
			}
	}

	return res;
}

void testcase(int tst)
{
	ifs >> n >> m;

	a.assign(n, 0);
	A.assign(n, 0);

	b.assign(m, 0);
	B.assign(m, 0);
	
	REP(i, n)
		ifs >> a[i] >> A[i];

	REP(i, m)
		ifs >> b[i] >> B[i];

	memset(was, -1, sizeof(was));
	ofs << "Case #" << tst+1 << ": " << go(0, 0) << endl;
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
