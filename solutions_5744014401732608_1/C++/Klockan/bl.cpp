#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <inttypes.h>
#include <memory>
#ifndef M_PI
#define M_PI 3.141592653589793238462643L
#endif

#define ff(i,s,e) for(int i=(s);i<(int)(e);i++)
#define fr(i,s,e) for(int i=(e);i-->(int)(s);)
#define FF(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define Fr(i,s,e) for(int i=(e);i>=(int)(s);i--)

#define gcd(a,b) __gcd(a,b)
#define all(a) a.begin(),a.end()
#define ln putchar('\n')
#define sp putchar(' ')
using namespace std;

typedef int64_t ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

template<class T>inline void pr(const T&v);
template<class T, class...Args> inline void pr(const T&a, const Args(&... args));

inline int scan(int&i) { return scanf("%d", &i); }
inline int scan(ll&i) { return scanf("%" PRId64, &i); }
inline int scan(double&i) { return scanf("%lf", &i); }
inline int scan(ld&i) { return scanf("%Lf", &i); }
inline int scan(char&i) { int c; while ((c = getchar()) != EOF&&c <= ' '); i = c; return c != EOF; }
inline int scan(string&i) { i.clear(); int c; while ((c = getchar()) != EOF&&c <= ' '); while (c>' ')i += c, c = getchar(); return i.size(); }
inline int scanln(string&i) { i.clear(); int c; while ((c = getchar()) != EOF&&c<' '); while (c >= ' ')i += c, c = getchar(); return i.size(); }
template<class T> inline int scan(T&a) { return a.sc(); }
template<class T, class U> inline int scan(pair<T, U>&a) { scan(a.first); return scan(a.second); }

inline void pr(const int& i) { printf("%d", i); }
inline void pr(const unsigned int& i) { printf("%u", i); }
inline void pr(const bool i) { printf("%d", i); }
inline void pr(const ll&i) { printf("%" PRId64, i); }
inline void pr(const unsigned long&i) { printf("%" PRId64, (ll)i); }
inline void pr(const double&i) { printf("%.12f", i); }
inline void pr(const ld&i) { printf("%.12f", (double)i); }
inline void pr(const float&i) { printf("%.4f", i); }
inline void pr(const char&i) { putchar(i); }
inline void pr(const char*i) { printf("%s", i); }
inline void pr(const string&i) { for (char c : i)pr(c); }

template<class T>inline int scan(vector<T>&v) { for (T&i : v)scan(i); return 0; }
template<class T, class U>inline void pr(const pair<T, U>&p) { pr(p.first, p.second); }
template<class T>inline void pr(const vector<T>&v) { if (v.empty())return; pr(v[0]); ff(i, 1, v.size())pr(' '), pr(v[i]); }
template<class T>inline void prlns(const vector<T>&v) { ff(i, 0, v.size())pr(v[i]), pr('\n'); }
template<class T, class...Args> inline int scan(T&a, Args(&... args)) { return scan(a), scan(args...); }
template<class T, class...Args> inline void pr(const T&a, const Args(&... args)) { pr(a), pr(' '), pr(args...); }
template<class T> inline void prln(const T&a) { pr(a), ln; }
template<class T, class...Args> inline void prln(const T&a, const Args(&... args)) { pr(a), sp, prln(args...); }
template<class...Args> inline void rpr(const Args(&... args)) {
#ifndef ONLINE_JUDGE
	pr(args...), ln; fflush(stdout);
#endif
}
inline int gi() { int x; scan(x); return x; }
inline int gis() { int x; scan(x); return x - 1; }

template<class T>inline void pr(const T&v) { v.print(); }

template<class T, class U> inline void smax(T&a, const U&b) { if (a<b)a = b; }
template<class T, class U> inline void smin(T&a, const U&b) { if (b<a)a = b; }

template<class T> T& operator +=(vector<T>&v, const T&a) { v.push_back(a); return v.back(); }

const int inf = (1 << 30) + (1 << 29);
const ll LargeMod = 4611686018427388039;
const ll MOD = 1E9 + 7;
const ll linf = 1E17;
typedef unsigned int uint;
const ll lprime = 37ll;

int fpow(ll base, ll n, ll mod) {
	n %= (mod - 1);
	if (n < 0)
		n += mod - 1;
	ll cur = 1;
	while (n) {
		if (n & 1)cur = cur * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return cur;
}

struct problem {
	int n;
	ll m;
	int ans[100][100] = {};
	int solve() {
		m--;
		ans[0][n - 1] = 1;
		ff(i, 1, n-1) {
			if (m & 1)
				ans[0][n - i - 1] = 1;
			m >>= 1;
		}
		if (m) {
			prln("IMPOSSIBLE");
		}
		else {
			prln("POSSIBLE");
			ff(i, 0, n) {
				ff(j, 0, n)pr(ans[i][j]);
				ln;
			}
		}

		return 0;
	}

	int init() {
		ff(i, 1, n-1) {
			ff(j, i + 1, n) {
				ans[i][j] = 1;
			}
		}
		return 0;
	}

	int get_input() {
		scan(n, m);
		return 0;
	}
};

int main(int argc, char**argv) {
	int n;
	scan(n);
	FF(i,1,n) {
		printf("Case #%d: ", i);
		unique_ptr<problem> xx(new problem());
		xx->get_input();
		xx->init();
		xx->solve();
	}
	return 0;
}
