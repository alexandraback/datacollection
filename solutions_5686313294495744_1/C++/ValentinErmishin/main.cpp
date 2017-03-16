#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;

using namespace std;

#ifdef LOCAL
#include "debug.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define Print(...) (void)42;
#define eprintf(...) (void)42;
#endif

const int MAXN = 2000;

int TS;
int n;
pair<string, string> mas[1003];
map<string, int> re1, re2;
pair<int, int> M[1003];
int CNT;
int par[MAXN];
int was[MAXN];
int IT;
int mt[MAXN];
int E[MAXN];
vector<int> g[MAXN];

bool kuhn (int v) {
	if (was[v] == IT)  return false;
	was[v] = IT;
	for (int i = 0; i <  (int) g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int add1 (string x) {
	auto it = re1.find (x);
	if (it == re1.end ()) {
		int res = (int) re1.size ();
		re1[x] = res;
		return res;
	}
	return it -> second;
}

int add2 (string x) {
	auto it = re2.find (x);
	if (it == re2.end ()) {
		int res = (int) re2.size ();
		re2[x] = res;
		return res;
	}
	return it -> second;
}

void load () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mas[i] = make_pair (s1, s2);
		M[i].first = add1 (s1);
		M[i].second = add2 (s2);
	}
}

void clear () {
	re1.clear ();
	re2.clear ();
	for (int i = 0; i < MAXN; i++) {
		g[i].clear ();
	}
	memset (mt, 0xff, sizeof (mt));
	memset (E, 0, sizeof (E));
}

int solve () {
	for (int i = 0; i < n; i++) {
		g[M[i].first].push_back (M[i].second);
	}

	for (int v=0; v<n; ++v) {
		IT++;
		(void) kuhn (v);
	}

	int res = n;

	for (int i = 0; i < (int) re2.size (); i++) {
		if (mt[i] != -1) {
			E[mt[i]] = 1;
		}
		res--;
	}

	for (int i = 0; i < (int) re1.size (); i++) {
		res -= 1 - E[i];
	}

	return res;
}

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#else
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);
#endif 

#ifdef TIMER
	timer Tm;
	Tm.start ();
#endif

	cin >> TS;

	for (int i = 1; i <= TS; i++) {
		clear ();
		load ();
		printf ("Case #%d: %d\n", i, solve ());
		//clear ();
		clog << i << endl;
	}
	

#ifdef TIMER
	Tm.stop ();
	Tm.print_time (stderr);
#endif

	return 0;
}