#include <cstdio>

int x, o;
int board[4][4];

int win(int player) {
	for (int i = 0; i < 4; i++) {
		if (player == board[i][0] || 3 == board[i][0]) {
			if (player == board[i][1] || 3 == board[i][1]) {
				if (player == board[i][2] || 3 == board[i][2]) {
					if (player == board[i][3] || 3 == board[i][3]) {
						return 1;
					}
				}
			}
		}
		if (player == board[0][i] || 3 == board[0][i]) {
			if (player == board[1][i] || 3 == board[1][i]) {
				if (player == board[2][i] || 3 == board[2][i]) {
					if (player == board[3][i] || 3 == board[3][i]) {
						return 1;
					}
				}
			}
		}
	}
	if (player == board[0][0] || 3 == board[0][0]) {
		if (player == board[1][1] || 3 == board[1][1]) {
			if (player == board[2][2] || 3 == board[2][2]) {
				if (player == board[3][3] || 3 == board[3][3]) {
					return 1;
				}
			}
		}
	}
	if (player == board[0][3] || 3 == board[0][3]) {
		if (player == board[1][2] || 3 == board[1][2]) {
			if (player == board[2][1] || 3 == board[2][1]) {
				if (player == board[3][0] || 3 == board[3][0]) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int N;
	int finished;
	char temp;
	scanf("%d", &N);
	scanf("%c", &temp);
	for (int i = 1; i <= N; i++) {
		finished = 1;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%c", &temp);
				switch (temp) {
					case 'X':
						board[j][k] = 1;
						break;
					case 'O':
						board[j][k] = 2;
						break;
					case 'T':
						board[j][k] = 3;
						break;
					case '.':
						board[j][k] = 0;
						finished = 0;
						break;
					default:
						board[j][k] = 4;
						break;
				}
			}
			scanf("%c", &temp);
		}
		scanf("%c", &temp);
		printf("Case #%d: ", i);
		
		o = win(2);
		x = win(1);
		
		if (x && !o)
			printf("X won\n");
		else if (!x && o)
			printf("O won\n");
		else if (!finished)
			printf("Game has not completed\n");
		else if (!x && !o)
			printf("Draw\n");
	}
	return 0;
}
