#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,a,b) for (int i = (a); i < (b); i++)
#define DOWN(i,a,b) for (int i = (a); i > (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FREOPEN freopen("B-small-attempt0.in", "r", stdin); freopen("a.out", "w", stdout)

int n, p, s, t[110];
int a[30][30], b[30][30], f[110][110];

int call(int i, int sp) {
	if (f[i][sp] != -1) return f[i][sp];
	if (i == n + 1) {
		if (sp == s) f[i][sp] = 0;
		else f[i][sp] = -2*n;
		return f[i][sp];
	}
	
	f[i][sp] = -2*n;
	FOR (score, 0, 10) {
		if (a[t[i]][score]) f[i][sp] = max(f[i][sp], (score >= p) + call(i + 1, sp + 1));
    }
		
	FOR (score, 0, 10)
		if (b[t[i]][score]) f[i][sp] = max(f[i][sp], (score >= p) + call(i + 1, sp));
	
	return f[i][sp];
}
int main() {
	FREOPEN;
	
	SET (a, 0);
	SET (b, 0);
	
	FOR (i, 0, 10)
	FOR (j, i, min(10, i + 2))
	FOR (k, j, min(10, i + 2))
		if (k == i + 2) a[i + j + k][k] = 1;
		else b[i + j + k][k] = 1;
	
	int ntest;
	cin >> ntest;
	FOR (test, 1, ntest) {
		cin >> n >> s >> p;
		FOR (i, 1, n) cin >> t[i];
		SET (f, -1);
		//cerr << f[1][0] << endl;
		cout << "Case #" << test << ": " << call (1, 0) << endl;
	}
	return 0;
}
