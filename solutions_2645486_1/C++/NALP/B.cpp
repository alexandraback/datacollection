/*
    Author: Nikolay Kuznetsov
    Dedicated to my Love, Kristina Dmitrashko
*/
#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 10100;

int64 E, R, a[MAXN], e[MAXN], need[MAXN];
int64 d[MAXN][100];
bool used[MAXN];
int n;

int64 get(int v, int64 cur) {
	if (v == n) return 0;
	int64 &ans = d[v][cur];
	if (ans != -1) return ans;
	
	ans = 0;
	forn(i, cur + 1)
		ans = max(ans, get(v + 1, min(E, 0LL + cur - i + R)) + a[v]*i);

	return ans;
}

int64 stupid() {
	memset(d, 255, sizeof d);
	return get(0, E);
}

void solve() {
	bool GENERATE_TEST = false;
	if (!GENERATE_TEST) {
		E = nextInt();
		R = nextInt();
		n = nextInt();
		forn(i, n)
			a[i] = nextInt();
	} else {
		throw;
		R = rand() % 10 + 1;
		E = rand() % 100 + 1;
		n = rand() % 100 + 1;
		forn(i, n)
			a[i] = rand() % 100 + 1;
	}

	vector<pair<int64, int> > p;
	forn(i, n) {
		p.pb(mp(a[i], i));
		e[i] = E;
	}

	int64 ans = 0;
	sort(rall(p));
	memset(used, 0, sizeof used);
	forn(v, n) {
		int pos = p[v].second;

		int64 minv = 0;
		for(int j = pos + 1; j < n; j++)
			if (used[j]) {
				minv = max(minv, need[j] - R*(j - pos));
				break;
			}

		need[pos] = e[pos];
		ans += a[pos] * (e[pos] - minv);
		used[pos] = true;
		e[pos] = minv;

		pos++;
		int64 cur = R + minv;
		while (pos < n && cur < E) {
			e[pos] = min(e[pos], cur);
			cur += R;
			pos++;
		}
	}

	cout << ans << endl;
	cerr << "\tclever answer is '" << ans << "'" << endl;
	if (n <= 100 && R <= 100) {
		int64 stupidAnswer = stupid();
		cerr << "\tstupid answer is '" << stupidAnswer << "'" << endl;
		if (ans != stupidAnswer) {
			cerr << "\tanswers aren't equal!" << endl;
			throw;
		}
	}
}

int main() {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	srand(time(0));
	int tests = nextInt();
	forn(test, tests) {
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve();
	}

	return 0;
}
