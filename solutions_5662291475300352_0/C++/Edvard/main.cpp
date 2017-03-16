#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100;

int n;
int x[N], v[N];

inline bool read() {
	int k;
	if (!(cin >> k)) return false;
	n = 0;
	forn(i, k) {
		int d, h, m;
		assert(scanf("%d%d%d", &d, &h, &m) == 3);
		forn(j, h)
			x[n] = d, v[n++] = m + j;
	}
	return true;
}

inline void solve() {
	bool bad = false;
	if (n == 2)
		forn(t, 2) {
			if (li(720 - x[0]) * v[0] <= li(360 - x[1]) * v[1])
				bad = true;
			swap(x[0], x[1]);
			swap(v[0], v[1]);
		}
	if (bad) puts(" 1");
	else puts(" 0");
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif
	
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int tc;
	cin >> tc;
	forn(tt, tc) {
		assert(read());
		printf("Case #%d:", tt + 1);
		solve();
	}
	
	return 0;
}
