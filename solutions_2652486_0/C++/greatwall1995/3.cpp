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

void init() {
	scanf("%d%d%d%d", &r, &n, &m, &k);
}

void solve() {
	CLR(app, 0);
	app[1] = 1;
	while (r--) {
		REP1(i, k) scanf("%d", num + i);
		bool flag = false;
		FOR(i, 2, m) {
			FOR(j, 2, m) {
				FOR(k0, 2, m) {
					app[i] = app[j] = app[k0] = app[i * j] = app[i * k0] = app[j * k0] = app[i * j * k0] = 1;
					flag = true;
					REP1(l, k) {
						if (!app[num[l]]) {
							flag = false;
							break;
						}
					}
					
					app[i] = app[j] = app[k0] = app[i * j] = app[i * k0] = app[j * k0] = app[i * j * k0] = 0;
					if (flag) printf("%d%d%d\n", i, j, k0);
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
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
