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

char res[21][21][21];

int main() {
	int t, x, r, c;

	cin >> t;

	memset(res, 1, sizeof(res));

	REP(r, 21) REP(c, 21) res[1][r][c] = 0;
	REP(r, 21) REP(c, 21) res[2][r][c] = r*c % 2;
	res[3][2][3] = res[3][3][2] = res[3][3][3] = res[3][3][4] = res[3][4][3] = 0;
	res[4][3][4] = res[4][4][3] = res[4][4][4] = 0;

	REP(tc, t) {
		cin >> x >> r >> c;

		cout << "Case #" << tc + 1 << ": " << (res[x][r][c]?"RICHARD":"GABRIEL") << endl;
	}
	

	return 0;
}