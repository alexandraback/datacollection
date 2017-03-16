
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

char board[4][5];

bool isXWinner(char a, char b, char c, char d) {
	if (a != 'X' && a != 'T') return false;
	if (b != 'X' && b != 'T') return false;
	if (c != 'X' && c != 'T') return false;
	if (d != 'X' && d != 'T') return false;
	return true;
}

bool isOWinner(char a, char b, char c, char d) {
	if (a != 'O' && a != 'T') return false;
	if (b != 'O' && b != 'T') return false;
	if (c != 'O' && c != 'T') return false;
	if (d != 'O' && d != 'T') return false;
	return true;
}

void work() {
	for (int i = 0; i < 4; i ++)
		scanf("%s", board[i]);
	for (int i = 0; i < 4; i ++) {
		if (isXWinner(board[i][0], board[i][1], board[i][2], board[i][3])) {
			printf("X won\n");
			return;
		}
		if (isXWinner(board[0][i], board[1][i], board[2][i], board[3][i])) {
			printf("X won\n");
			return;
		}
		if (isOWinner(board[i][0], board[i][1], board[i][2], board[i][3])) {
			printf("O won\n");
			return;
		}
		if (isOWinner(board[0][i], board[1][i], board[2][i], board[3][i])) {
			printf("O won\n");
			return;
		}
	}
	if (isXWinner(board[0][0], board[1][1], board[2][2], board[3][3])) {
		printf("X won\n");
		return;
	}
	if (isXWinner(board[0][3], board[1][2], board[2][1], board[3][0])) {
		printf("X won\n");
		return;
	}
	if (isOWinner(board[0][0], board[1][1], board[2][2], board[3][3])) {
		printf("O won\n");
		return;
	}
	if (isOWinner(board[0][3], board[1][2], board[2][1], board[3][0])) {
		printf("O won\n");
		return;
	}
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			if (board[i][j] == '.') {
				printf("Game has not completed\n");
				return;
			}
	printf("Draw\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		printf("Case #%d: ", test + 1);
		work();
	}

	return 0;
}