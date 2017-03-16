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

string s, t;
                          
inline bool read() {         
	cin >> s >> t;
	return true;
}         

string ts(int x, int len) {
	string res = "";
	forn (i, len) {
		res += '0' + x % 10;
		x /= 10;
	}
	reverse(all(res));
	return res;
}

bool ok(int x, string s) {
	forn (i, sz(s)) {
		int y = x % 10;
		x /= 10;
		if (s[sz(s) - 1 - i] != '?' && s[sz(s) - 1 - i] != '0' + y)
			return false;
	}
	return true;
}


pair<string, string> naive() {
	int up = 1;
	forn (i, sz(s))
		up *= 10;
	int best = INF;
	pair<string, string> ans;
	forn (i, up) {
		forn (j, up)
			if (ok(i, s) && ok(j, t))
				if (abs(i - j) < best) {
					best = abs(i - j);
					ans = mp(ts(i, sz(s)), ts(j, sz(t)));
				}	
	}	
	return ans;
}

void solve() {
	pair<string, string> ans = naive();
	cout << ans.ft << ' ' << ans.sc << endl;		
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