#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
li m;
                      
inline bool read() {
	cin >> n >> m;
	return true;
}         

li dp[55];

bool e[55][55];

li cnt(int v) {
	if (dp[v] != -1)
		return dp[v];
	if (v == n)
		return 1;
	dp[v] = 0;
	for (int i = 1; i <= n; ++i)
		if (e[v][i])
			dp[v] += cnt(i);
	return dp[v];
}

bool check() {
	forn (i, 55)
		dp[i] = -1;
	assert(cnt(1) == m);
	return true;
}

void solve() {

	forn (i, 55)
		forn (j, 55)
			e[i][j] = 0;
	
	dp[n - 1] = dp[n] = 1;
	for (int i = n - 2; i >= 1; --i)
		dp[i] = dp[i + 1] * 2;	
  
	if ((1LL << (n - 2)) < m) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	li mm = m;
	cout << "POSSIBLE" << endl;
	for (int i = 2; i <= n; ++i) {
		if (mm >= dp[i]) {
			mm -= dp[i];
			e[1][i] = 1;
		}
	}	
	forn (i, n - 1) {
		forn (j, n - i - 2)
			e[i + 2][i + 3 + j] = 1;
	}
	forn (i, n) {
		forn (j, n)
			cout << e[i + 1][j + 1];
		cout << endl;
	}
	assert(check());
	cerr << "OK" << endl;
}         

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
   	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;

	srand(time(NULL));
	
	int t;
	cin >> t;

	forn (i, t) {
	    cout << "Case #" << i + 1 << ": ";
		read();
		solve();
	}
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}