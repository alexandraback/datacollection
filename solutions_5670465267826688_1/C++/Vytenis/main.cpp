#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

const int MAXN = 161234;
char s[MAXN];
char suf[MAXN];

char tbl[8][8];

inline char chr2id(char c) {
	return c == 'i' ? 1 : (c == 'j' ? 2 : 3);
}

int main() {
	int t, L, n;
	long long X;

	tbl[0][0] = 0; tbl[0][1] = 1; tbl[0][2] = 2; tbl[0][3] = 3;
	tbl[1][0] = 1; tbl[1][1] = 4; tbl[1][2] = 3; tbl[1][3] = 6;
	tbl[2][0] = 2; tbl[2][1] = 7; tbl[2][2] = 4; tbl[2][3] = 1;
	tbl[3][0] = 3; tbl[3][1] = 2; tbl[3][2] = 5; tbl[3][3] = 4;

	FOR(i, 4, 8) REP(j, 4) tbl[i][j] = tbl[i - 4][j] ^ 4;
	FOR(j, 4, 8) REP(i, 4) tbl[i][j] = tbl[i][j - 4] ^ 4;
	FOR(i, 4, 8) FOR(j, 4, 8) tbl[i][j] = tbl[i - 4][j - 4];

	cin >> t;

	REP(tc, t) {
		cin >> L >> X >> s;
		//L = 10000; X = 16;
		//REP(i, L) s[i] = 'i' + rand() % 3;
		if (X > 16) X = 12 + X % 4;
		n = 0;
		REP(i, X) REP(j, L) s[n++] = s[j];

		REP(i, n) s[i] = chr2id(s[i]);

		suf[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; --i) suf[i] = tbl[s[i]][suf[i + 1]];

		bool found = false;
		int lim1 = min(4 * L, n - 2);
		char val1, val2;
		for (int i1 = 0; i1 < lim1; ++i1) {
			val1 = i1 ? tbl[val1][s[i1]] : s[0];
			if (val1 == 1) {
				int lim2 = min(i1 + 1 + 4 * L, n - 1);
				for (int i2 = i1 + 1; i2 < lim2; ++i2) {
					val2 = i2 == i1 + 1 ? s[i2] : tbl[val2][s[i2]];
					if (val2 == 2 && suf[i2 + 1] == 3) {
						found = true;
						break;
					}
				}
			}
			if (found) break;
		}

		cerr << tc << endl;
		cout << "Case #" << tc + 1 << ": " << (found ? "YES" : "NO") << endl;
	}
	

	return 0;
}