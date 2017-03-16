#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 31, INF = 1000*1000*1000;
const ld  eps = 1e-9;

li z[N + 1][2][2][2];

void conv(int a, int b[N]) {
	memset(b, 0, sizeof b);
	forn(i, N) {
		if (a & (1 << i))
			b[N - i - 1] = 1;
		else
			b[N - i - 1] = 0;
	}
}

bool solve(int test) {
	printf("Case #%d: ", test + 1);
	int aa, bb, kk;
	scanf("%d%d%d", &aa, &bb, &kk);
	int a[N], b[N], k[N];
	conv(aa, a);
	conv(bb, b);
	conv(kk, k);
	memset(z, 0, sizeof z);
	z[0][1][1][1] = 1;
	forn(i, N - 1)forn(pi, 2)forn(pj, 2)forn(pk, 2) {
		li dv = z[i][pi][pj][pk];
		if (dv == 0)
			continue;
		forn(ni, 2)
			forn(nj, 2) {
				int nk = (ni & nj);
				if (pi && (a[i + 1] < ni))
					continue;
				if (pj && (b[i + 1] < nj))
					continue;
				if (pk && (k[i + 1] < nk))
					continue;
				int npi = (pi && (a[i + 1] == ni));
				int npj = (pj && (b[i + 1] == nj));
				int npk = (pk && (k[i + 1] == nk));
				z[i + 1][npi][npj][npk] += dv;
			}
	}
	li ans = z[N - 1][0][0][0];
	cout << ans << endl;
	return false;
}

int main () {	
#ifdef IKAR
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	forn(i, n)
		solve(i);
	return 0;
}