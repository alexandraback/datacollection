#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c)

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

char board[10][10];
char temp[10];
int test() {
	fu(i, 4) if (temp[i] == '.') return 0;
	char w;
	fu(i, 4) if (temp[i] != 'T') w = temp[i];
	fu(i, 4) if (temp[i] != 'T' && temp[i] != w) return 0;
	return (w == 'X')?1:2;
}

int main() {
	int N;
	scanf("%d", &N);
	fu(t, N) {
		printf("Case #%d: ", t+1);
		fu(i,4) scanf(" %s", &board[i]);

		int win = 0;
		// horizontal
		fu(i, 4) {
			fu(j, 4) temp[j] = board[i][j];
			win = test();
			if (win != 0) break;
		}
		// vertical
		if (win == 0) fu(j, 4) {
			fu(i,4) temp[i] = board[i][j];
			win = test();
			if (win!=0) break;
		}
		// diagonal
		if (win == 0) {
			fu(i, 4) temp[i] = board[i][i];
			win = test();
		}

		if (win == 0) {
			fu(i, 4) temp[i] = board[i][3-i];
			win = test();
		}
		
		if (win == 1) printf("X won\n");
		else if (win == 2) printf("O won\n");
		else {
			bool hasd = false;
			fu(i, 4) fu(j, 4) if (board[i][j] == '.') hasd = true;
			if (hasd) printf("Game has not completed\n");
			else printf("Draw\n");
		}
	}
}

