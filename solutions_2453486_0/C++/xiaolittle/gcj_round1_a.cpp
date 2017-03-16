#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char board[4][5];

bool isWon(char ch) {
	for (int i = 0; i < 4; ++i) {
		int count = 0;
		int tCount = 0;
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] == ch) {
				++count;
			} else if (board[i][j] == 'T') {
				++tCount;
			}
		}
		if (count == 4 || (count == 3 && tCount == 1)) {
			return true;
		}
	}

	for (int j = 0; j < 4; ++j) {
		int count = 0;
		int tCount = 0;
		for (int i = 0; i < 4; ++i) {
			if (board[i][j] == ch) {
				++count;
			} else if (board[i][j] == 'T') {
				++tCount;
			}
		}
		if (count == 4 || (count == 3 && tCount == 1)) {
			return true;
		}
	}
	int count = 0;
	int tCount = 0;
	for (int i = 0; i < 4; ++i) {
		if (board[i][i] == ch) {
			++count;
		} else if (board[i][i] == 'T') {
			++tCount;
		}
	}
	if (count == 4 || (count == 3 && tCount == 1)) {
		return true;
	}

	count = tCount = 0;
	for (int i = 0; i < 4; ++i) {
		if (board[i][3 - i] == ch) {
			++count;
		} else if (board[i][3 - i] == 'T') {
			++tCount;
		}
	}
	if (count == 4 || (count == 3 && tCount == 1)) {
		return true;
	}
	return false;
}

int main() {
	int T;
	int cas = 0;
	//char board[4][5];
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.txt", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		int count = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%s", board[i]);
			for (int j = 0; j < 4; ++j) {
				if (board[i][j] == '.') {
					++count;
				}
			}
		}
		bool x = isWon('X');
		bool o = isWon('O');
		if (x) {
			printf("Case #%d: X won", ++cas);
		} else if (o) {
			printf("Case #%d: O won", ++cas);
		} else {
			if (count > 0) {
				printf("Case #%d: Game has not completed", ++cas);
			} else {
				printf("Case #%d: Draw", ++cas);
			}
		}
		printf("\n");
	}
	return 0;
}
			

