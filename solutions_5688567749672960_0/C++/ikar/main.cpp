#include <bits/stdc++.h>

using namespace std;

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

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
//const ld PI = acosl(ld(-1));

const int N = 1000 * 1000 + 13;

int n;

inline bool read() {
	assert(scanf("%d", &n) == 1);
    return true;
}

int d[N];

inline void solve(int test) {
	printf("Case #%d: %d\n", test, d[n]);
}

int q[N];
int head, tail;

int flip(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

void prepare() {
	memset(d, -1, sizeof d);
	d[0] = 0;
	head = tail = 0;
	q[tail++] = 0;
	while (tail != head) {
		int v = q[head++];
		int to = flip(v);
		if (to < N && d[to] == -1) {
			d[to] = d[v] + 1;
			q[tail++] = to;
		}
		to = v + 1;
		if (to < N && d[to] == -1) {
			d[to] = d[v] + 1;
			q[tail++] = to;
		}

	}
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));
	prepare();
    int n;
    assert(scanf("%d", &n) == 1);
    forn(i, n) {
	    assert(read());
   		solve(i + 1);
    }
    

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}