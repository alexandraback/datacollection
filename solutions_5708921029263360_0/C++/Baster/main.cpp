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

int a[3];
int k;
                      
inline bool read() {
	forn (i, 3)
		cin >> a[i];
	cin >> k;
	return true;
}         

int cnt[4][4][4];

struct st {
	int x[3];
	bool term;
};

vector<st> best;
vector<st> cur;

st inc(st v) {
	int r = 2;
	while(r >= 0 && ++v.x[r] == a[r])
		v.x[r--] = 0;
	if (r < 0)
		v.term = true;
	return v;
}

void go(st v, int d) {
	cnt[v.x[0]][v.x[1]][3] += d;
	cnt[v.x[0]][3][v.x[2]] += d;
	cnt[3][v.x[1]][v.x[2]] += d;
}

void rec(st v) {
	if (sz(best) == a[0] * a[1] * a[2])
		return;
	forn (i, 4)
		forn (j, 4)
			forn (t, 4)
				if (cnt[i][j][t] > k)
					return;
	if (v.term) {
		if (sz(cur) > sz(best))
			best = cur;
		return;
	}
	cur.pb(v);
	st nv = inc(v);
	go(v, +1);
	rec(nv);
	go(v, -1);
	cur.pop_back();
	rec(nv);	
}

void solve() {
	best.clear();
	cur.clear();
	st v;
	v.x[0] = v.x[1] = v.x[2] = 0;
	v.term = false;
	rec(v);
	cout << sz(best) << endl;
	forn (i, sz(best))
		cout << best[i].x[0] + 1 << ' ' << best[i].x[1] + 1 << ' ' << best[i].x[2] + 1 << endl;				
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
		cerr << i + 1 << endl;
	}
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}