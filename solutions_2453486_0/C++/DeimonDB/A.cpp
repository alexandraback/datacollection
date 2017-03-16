#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

char data[5][5];
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int nDir = 8;
int R = 4, C = 4;

bool match(int r, int c) {
	REP(i, nDir) {
		int j;
		for (j = 0; j < 4; j++) {
			int rnow = r + j*dr[i];
			int cnow = c + j*dc[i];
			if (rnow < 0 || rnow >= 4 || cnow < 0 || cnow >= 4 || (data[rnow][cnow] != data[r][c] && data[rnow][cnow] != 'T')) break;
		}
		if (j == 4) return true;
	}
	return false;
}
inline void solve(int tc) {
	bool full = true;
	REP(i, R) {
		REP(j, C) {
			scanf("%c", &data[i][j]);
			if (data[i][j] == '.') full = false;
		}
		scanf("%*c");
	}
	scanf("%*c");
	bool won = false;
	char winner;
	REP(i, R) REP(j, C) {
		if (data[i][j] != '.' && data[i][j] != 'T' && match(i, j)) {
			won = true;
			winner = data[i][j];
		}
	}
	printf("Case #%d: ", tc);
	if (won) {
		printf("%c won\n", winner);
	}
	else if (full) puts("Draw");
	else puts("Game has not completed");
}

int main() {
	int T;
	scanf("%d%*c", &T);
	FOR(i, 1, T) solve(i);
	return 0;
}
