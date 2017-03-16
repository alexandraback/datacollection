#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; } 
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const map<X, Y>& a) { return out << vector<pair<X, Y>>(all(a)); }
template<typename T> inline ostream& operator<< (ostream& out, pair<T*, int> a) { return out << vector<T>(a.x, a.x + a.y); }

inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

#ifdef SU1
#define LOG
#endif

const int N = 2020, L = 22;

inline int getId(map<string, int>& id, const string& s) {
	if (!id.count(s)) {
		int v = sz(id);
		id[s] = v;
	}
	return id[s];
}

int n;
pti e[N];
vector<int> g[N];
map<string, int> id1, id2;

bool read() {
	if (!(cin >> n)) return false;

	id1.clear();
	id2.clear();

	static char buf[L];
	forn(i, n) {
		assert(scanf("%s", buf) == 1);
		int x = getId(id1, buf);
		assert(scanf("%s", buf) == 1);
		int y = getId(id2, buf);
		e[i] = mp(x, y);
	}

	forn(i, sz(id1)) g[i].clear();
	forn(i, n) g[e[i].x].pb(e[i].y);

	return true;
}

int u, used[N];
int p[N];

bool kuhn(int v) {
	if (used[v] == u) return false;
	used[v] = u;

	for (auto to : g[v]) {
		//cerr << "v=" << v << " to=" << to << " p[to]=" << p[to] << endl;
		if (p[to] == -1 || kuhn(p[to])) {
			//cerr << "IN" << endl;
			p[to] = v;
			return true;
		}
	}
	return false;
}

void solve(int test) {
	printf("Case #%d: ", test + 1);

	memset(p, -1, sizeof(p));
	int ans = 0;
	forn(i, sz(id1)) {
		u++;
		ans += kuhn(i);
	}
	//cerr << "sz(id1)=" << sz(id1) << " sz(id2)=" << sz(id2) << " ans=" << ans << endl;
	/*cerr << "e: " << mp(e, n) << endl;
	forn(i, sz(id1)) cerr << "g[" << i << "]: " << g[i] << endl;*/

	ans = sz(id1) + sz(id2) - ans;
	printf("%d\n", n - ans);
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

	int tc;
	cin >> tc;
	forn(tt, tc) {
		assert(read());
		ld stime = gett();
		solve(tt);
		cerr << "TEST #" << tt + 1 << endl;
		cerr << "Time: " << gett() - stime << endl;
		//break;
	}
	
    return 0;
}
