#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long LL;

#define REP(i, a) for (int i = 0; i < (int)(a); i++)
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define REPD(i, a) for (int i = (int)(a - 1); i >= 0; i--)
#define FORD(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define CLEAR(x, val) memset(x, val, sizeof(x))

int r, c;
int tc;
int in[105][105];
int current[105][105];

bool cut;
void cutRow(int r, int id, int h) {
	if (id == c) {
		cut = 1;
		return;
	}

	if (in[r][id] <= h) {
		cutRow(r, id + 1, h);
	}
	else {
		return;
	}

	if (cut) {
		current[r][id] = h;
	}
}

void cutCol(int c, int id, int h) {
	if (id == r) {
		cut = 1;
		return;
	}

	if (in[id][c] <= h) {
		cutCol(c, id + 1, h);
	}
	else {
		return;
	}

	if (cut) {
		current[id][c] = h;
	}
}

bool solve() {
	FORD(h, 0, 100) {
		REP(i, r) {
			cut = 0;
			cutRow(i, 0, h);
		}

		REP(i, c) {
			cut = 0;
			cutCol(i, 0, h);
		}
	}

	REP(i, r) REP(j, c) if (current[i][j] != in[i][j]) return 0;

	return 1;
}

int main () {
	scanf("%d", &tc);
	FOR(test, 1, tc) {
		scanf("%d %d", &r, &c);

		REP(i, r) REP(j, c) {
			in[i][j] = 100;
			scanf("%d", &in[i][j]);
		}
		printf("Case #%d: %s\n", test, solve() ? "YES" : "NO");
	}
}
 




