#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define CLR(x, n) memset(x, n, sizeof(x))
using namespace std;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

int x, y;

void init() {
	scanf("%d%d", &x, &y);
}

void solve() {
	if (x > 0) FOR(i, 1, x) printf("WE");
	else FOR(i, x, -1) printf("EW");
	if (y > 0) FOR(i, 1, y) printf("SN");
	else FOR(i, y, -1) printf("NS");
	puts("");
}

int main() {
	setIO("2");
	int TT;
	cin >> TT;
	REP1(i, TT) {
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}
