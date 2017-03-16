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

struct Cell {
	int r, c;
};

int data[105][105];
vector<Cell> lho[105];
bool disabledRow[105], disabledColumn[105];
inline void bersih2() {
	memset(disabledRow, 0, sizeof disabledRow);
	memset(disabledColumn, 0, sizeof disabledColumn);
	FOR(i, 0, 104) lho[i].clear();
}

inline bool cek(int x) {
	REP(i, SZ(lho[x]))
		if (disabledRow[lho[x][i].r] && disabledColumn[lho[x][i].c]) return false;
	return true;
}
inline void solve(int tc) {
	bersih2();
	int R, C;
	scanf("%d %d", &R, &C);
	int maxx = 0;
	REP(i, R) REP(j, C) {
		scanf("%d", &data[i][j]);
		lho[data[i][j]].PB((Cell){i, j});
		maxx = max(maxx, data[i][j]);
	}
	bool can = true;
	for (int i = maxx; i >= 1; i--) {
		if (!cek(i)) {
			can = false;
			break;
		}
		REP(j, SZ(lho[i])) {
			disabledRow[lho[i][j].r] = true;
			disabledColumn[lho[i][j].c] = true;
		}
	}
	if (can) printf("Case #%d: YES\n", tc);
	else printf("Case #%d: NO\n", tc);
}

int main() {
	int T;
	scanf("%d", &T);
	FOR(i, 1, T) solve(i);
	return 0;
}
