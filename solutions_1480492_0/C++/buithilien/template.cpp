#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = (int) 1E9;
const ll LINF = (ll) 1E18;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define REPD(i, a) for (int i = (a) - 1; i >= 0; i--)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); ++it)
#define FITD(it, v) for (typeof((v).rbegin())it = (v).rbegin(); it != (v).rend(); ++it)

#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SIZE(a) ((int)(a).size())

#define SORT(x) sort(ALL(x))
#define GSORT(x) sort(ALL(x), greater<typeof(*((x).begin()))>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

int INP, AM;
#define BUFSIZE (1<<10)
char BUF[BUFSIZE + 1], *inp = BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        fread(BUF,1,BUFSIZE,stdin); \
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}

template<typename T> T gcd(T a, T b) {
	return (b == 0) ? abs(a) : gcd(b, a % b);
}
template<typename T> inline T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}
template<typename T> inline T sqr(T x) {
	return x * x;
}

const char DEBUG_PARAM[] = "__LOCAL_TESTING";

const char IN[] = "input.txt";
const char OUT[] = "output.txt";

int ntest = 0, test;

inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main(int argc, char* argv[]) {
	if (argc > 1 && strcmp(argv[1], DEBUG_PARAM) == 0) {
		freopen(IN, "r", stdin);
				freopen(OUT, "w", stdout);
	}
	init();
	if (ntest == 0) {
		puts("ntest = ?");
		return 0;
	}
	for (test = 1; test <= ntest; test++) {
		run();
	}
	return 0;
}

/* IMPLEMENTATION */

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const ld EPS = 1E-9;
const ll MODULO = 1000000007LL;

inline void init() {
	ntest = 0; // Input ntest
	cin >> ntest;
}

const int maxn = 50 + 5;
int n;

vector<pair<double, double> > l, r;

double findNext() {
	double t = 1e9;
	FOR(i,0,SIZE(l) - 2) {
		if (l[i].S > l[i + 1].S) {
			if (abs(l[i].S - l[i + 1].S) <= 1e-6)
				return -2;
			t = min(t, (l[i + 1].F - l[i].F - 5) / (l[i].S - l[i + 1].S));
		}
	}
	FOR(i,0,SIZE(r) - 2) {
		if (r[i].S > r[i + 1].S) {
			if (abs(r[i].S - r[i + 1].S) <= 1e-6)
				return -2;
			t = min(t, (r[i + 1].F - r[i].F - 5) / (r[i].S - r[i + 1].S));
		}
	}
	if (t == 1e9)
		return -1;
	return t;
}
bool check(int posL, int posR, vector<pair<double, double> > &l, vector<pair<
		double, double> > &r) {
	return l[posL].F + 5 - EPS < r[posR].F ;
}
bool conflict(int pos, vector<pair<double, double> > &l, vector<pair<double,
		double> > &r) {
	int lef = -1, rig = SIZE(r);
	while (lef + 1 < rig) {
		int mid = (lef + rig) >> 1;
		if (r[mid].F + 5 - EPS < l[pos].F)
			rig = mid;
		else
			lef = mid;
	}

	if (rig == SIZE(r)) {
		if (SIZE(r) > 0 && !check(pos, 0, l, r))
			return false;
		r.insert(r.begin(), l[pos]);
		l.erase(l.begin() + pos);

	} else if (pos < SIZE(r) - 1) {
		if (!check(pos, rig + 1, l, r))
			return false;
		r.insert(r.begin() + rig + 1, l[pos]);
		l.erase(l.begin() + pos);
	} else {

		r.insert(r.end(), l[pos]);
		l.erase(l.begin() + pos);
	}
	return true;
}
void rePosition(double t) {
	REP(i,SIZE(l)) {
		l[i].F += t * l[i].S;
	}
	REP(i,SIZE(r)) {
		r[i].F += t * r[i].S;
	}
}
bool rebuild(double t) {
	rePosition(t);

	do {
		bool ok = false;
		FOR(i,0,SIZE(l) - 2) {
			if (abs(l[i].F + 5 - l[i + 1].F) <= EPS) {
				if (!conflict(i, l, r))
					return false;
				ok = true;
				break;
			}
		}
		if (ok)
			continue;
		FOR(i,0,SIZE(r) - 2) {
			if (abs(r[i].F + 5 - r[i + 1].F) <= EPS) {
				if (!conflict(i, r, l))
					return false;
				ok = true;
				break;
			}
		}
		if (ok)
			continue;
		break;
	} while (true);
	return true;
}
void solve() {
	cout << "Case #" << test << ": ";
	double t;
	double res = 0;
	do {
		t = findNext();
		if (t == -1) {
			cout << "Possible" << endl;
			return;
		}
		res += t;
		if (t == -2)
			break;
		if (!rebuild(t))
			break;
	} while (true);
	printf("%.5lf\n", res);
}
inline void run() {
	cin >> n;
	char c;
	double s, p;
	l.clear();
	r.clear();

	FOR(i,1,n) {
		cin >> c >> s >> p;
		if (c == 'L') {
			l.PB(MP(p, s));
		} else {
			r.PB(MP(p, s));
		}
	}

	SORT(l);
	SORT(r);

	solve();
}
