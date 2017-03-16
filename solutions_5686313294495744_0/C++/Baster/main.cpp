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
const int N = 20;
pair<string, string> s[N];
                          
inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> s[i].ft >> s[i].sc;         
	return true;
}         

void solve() {
	cerr << "OK" << endl;
	int ans = 0;
	forn (i, 1 << n) {
		set<string> l, r;

		int cnt = 0;
		
		forn (j, n)
			if ((i >> j) & 1) {
				l.insert(s[j].ft);
				r.insert(s[j].sc);
				cnt++;
			}

		bool ok = true;

	   	forn (j, n) {
	   		if ((i >> j) & 1)
	   			continue;
	   		ok &= l.count(s[j].ft);
	   		ok &= r.count(s[j].sc);
	   	}
	   	if (ok)
	   		ans = max(ans, n - cnt);
	}
	cout << ans << endl;	
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