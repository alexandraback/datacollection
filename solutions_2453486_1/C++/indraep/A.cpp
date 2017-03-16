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

int tc;
char in[5][5];

void solve() {
	// check row X or O
	REP(i, 4) {
		int count = 0;
		REP(j, 4) {
			if (in[i][j] == 'X' || in[i][j] == 'T')
				count++;
		}

		if (count == 4) {
			printf("X won\n");
			return;
		}

		count = 0;
		REP(j, 4) {
			if (in[i][j] == 'O' || in[i][j] == 'T')
				count++;
		}

		if (count == 4) {
			printf("O won\n");
			return;
		}
	}

	REP(i, 4) {
		int count = 0;
		REP(j, 4) {
			if (in[j][i] == 'X' || in[j][i] == 'T')
				count++;
		}
		if (count == 4) {
			printf("X won\n");
			return;
		}

		count = 0;
		REP(j, 4) {
			if (in[j][i] == 'O' || in[j][i] == 'T')
				count++;
		}
		if (count == 4) {
			printf("O won\n");
			return;
		}
	}

	int countX = 0, countY = 0;
	REP(i, 4) {
		if (in[i][i] == 'X' || in[i][i] == 'T')
			countX++;
		if (in[i][i] == 'O' || in[i][i] == 'T')
			countY++;
	}
	if (countX == 4) {
		printf("X won\n");
		return;
	}
	if (countY == 4) {
		printf("O won\n");
		return;
	}

	countX = 0, countY = 0;
	REP(i, 4) {
		if (in[3-i][i] == 'X' || in[3-i][i] == 'T')
			countX++;
		if (in[3-i][i] == 'O' || in[3-i][i] == 'T')
			countY++;
	}
	if (countX == 4) {
		printf("X won\n");
		return;
	}
	if (countY == 4) {
		printf("O won\n");
		return;
	}
	

	REP(i, 4) REP(j, 4) {
		if (in[i][j] == '.') {
			printf("Game has not completed\n");
			return;
		}
	}

	printf("Draw\n");
}

int main () {
	scanf("%d", &tc);

	FOR(test, 1, tc) {
		REP(i, 4) {
			scanf("%s", in[i]);
		}

		printf("Case #%d: ", test);
		solve();
	}

}








