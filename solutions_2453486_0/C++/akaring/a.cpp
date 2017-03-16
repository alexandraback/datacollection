#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

char mp[4][4], line[5];

bool isOver() {
	REP (i, 4) {
		REP (j, 4) {
			if (mp[i][j] == '.') {
				return false;
			}
		}
	}
	return true;
}

bool isWin(char ch) {
	int cnt;

	REP (i, 4) {
		cnt = 0;
		REP (j, 4) {
			cnt += mp[i][j] == 'T' || mp[i][j] == ch;
		}
		if (cnt == 4) {
			return true;
		}
	}

	REP (j, 4) {
		cnt = 0;
		REP (i, 4) {
			cnt += mp[i][j] == 'T' || mp[i][j] == ch;
		}
		if (cnt == 4) {
			return true;
		}
	}

	cnt = 0;
	REP (i, 4) {
		cnt += mp[i][i] == 'T' || mp[i][i] == ch;
	}
	if (cnt == 4) {
		return true;
	}

	cnt = 0;
	REP (i, 4) {
		cnt += mp[3 - i][i] == 'T' || mp[3 - i][i] == ch;
	}
	if (cnt == 4) {
		return true;
	}

	return false;
}

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		REP (i, 4) {
			scanf("%s", line);
			REP (j, 4) {
				mp[i][j] = line[j];
			}
		}

		printf("Case #%d: ", index);
		if (isWin('X')) {
			printf("X won\n");
		} else if (isWin('O')) {
			printf("O won\n");
		} else if (!isOver()) {
			printf("Game has not completed\n");
		} else {
			printf("Draw\n");
		}
	}
	return 0;
}
