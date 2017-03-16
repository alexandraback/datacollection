#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:256000000")

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <iostream>

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define forn(i, n) for(register int i = 0; i < int(n); ++i)
#define forv(i, v) forn(i, (v).size())

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) ((x) >= 0 && (x) < (n) && (y) >= 0 && (y) < (m))

template <class T> inline T abs(T a) { return (a) > 0 ? (a) : -(a); }      
template <class T> inline T sqr(T a) { return (a) * (a); }

typedef long double ld;
typedef pair <ld, ld> pt;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef long long LL;

const ld PI = 3.1415926535897932, EPS = 1E-9;
const int INF = 1000 * 1000 * 1000, NMAX = 1005;
int n;
VI g[NMAX];
bool used[NMAX];
bool cycle;

void dfs(int v) {
	used[v] = true;
	forv(i, g[v]) {
		int to = g[v][i];
		if (!used[to]) dfs(to);
		else cycle = true;
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); //			
	int tests;
	cin >> tests;
	forn(test, tests) {
		cout << "Case #" << test + 1 << ": ";	//		
		memset(used, false, sizeof(used));
		forn(i, NMAX) g[i].clear();
		cycle = false;
		cin >> n;
		VI r;
		forn(i, n) {
			int m;
			cin >> m;
			forn(j, m) {
				int k;
				cin >> k;
				--k;
				g[k].pb(i);
			}
			if (m == 0) r.pb(i);
		}
		forv(i, r) {
			memset(used, false, sizeof(used));
			dfs(r[i]);
		}
		if (cycle) cout << "Yes";
		else cout << "No";
		cout << "\n";
	}
	return 0;
}
