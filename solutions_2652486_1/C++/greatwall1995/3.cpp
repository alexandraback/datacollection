#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
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

int r, n, m, k;
int num[50];
bool app[80000];
int used[20];

void init() {
	scanf("%d%d%d%d", &r, &n, &m, &k);
}

void solve() {
	CLR(app, 0);
	app[1] = 1;
	while (r--) {
		REP1(i, k) scanf("%d", num + i);
		FOR(i, 2, 8) used[i] = 0;
		REP1(i, k) {
			int t;
			for (int j = 8; j >= 2; --j) {
				if (num[i] % j) continue;
				t = 0;
				while (num[i] % j == 0) ++t, num[i] /= j;
				if (t > used[j]) used[j] = t;
			}
		}
		int sum = 0;
		FOR(i, 2, 8) sum += used[i];
		used[2] += n - sum;
		int t = 0;
		FOR(i, 2, 8) {
			REP(j, used[i]) {
				printf("%d", i);
				++t;
				if (t == n) break;
			}
			if (t == n) break;
		}
		puts("");
	}
}

int main() {
	setIO("3");
	puts("Case #1:");
	int TT;
	cin >> TT;
	init();
	solve();
	return 0;
}
