#include <cstdio>
#include <cctype>

const int N = 4;

char board[N][N];

bool Check(char ch) {
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N; j++)
			if (board[i][j] != ch && board[i][j] != 'T') {
				flag = false;
				break;
			}
		if (flag) return true;

		flag = true;
		for (int j = 0; j < N; j++)
			if (board[j][i] != ch && board[j][i] != 'T') {
				flag = false;
				break;
			}
		if (flag) return true;
	}
	bool flag = true;
	for (int i = 0; i < N; i++)
		if (board[i][i] != ch && board[i][i] != 'T') {
			flag = false;
			break;
		}
	if (flag) return true;

	flag = true;
	for (int i = 0; i < N; i++)
		if (board[i][N - 1 - i] != ch && board[i][N - 1 - i] != 'T') {
			flag = false;
			break;
		}
	return flag;
}

void Solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf(" %c", &board[i][j]);
			board[i][j] = toupper(board[i][j]);
		}
	if (Check('X')) printf("X won\n");
	else
		if (Check('O')) printf("O won\n");
		else {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (board[i][j] == '.') {
						printf("Game has not completed\n");
						return;
					}
			printf("Draw\n");
		}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
