// Michal Lazowik
//
// Google Code Jam 2013
// Qualification Round
// Problem A. Tic-Tac-Toe-Tomek

#include <cstdio>

#define REP(x, n) for (int x = 0; x < n; ++x)

const int MAX = 4;

int X, O;
bool dots;
char board[MAX+1][MAX+1];

void add(char z) {
	switch (z) {
		case '.': dots = true; break;
		case 'X': X++; break;
		case 'O': O++; break;
		case 'T': X++; O++; break;
	}
}

int parse() {
	dots = 0;

	// rows
	REP(x, MAX) {
		X = 0;
		O = 0;

		REP(y, MAX)
			add(board[x][y]);

		if (O == 4)
			return 0;
		if (X == 4)
			return 1;
	}
	
	// cols
	REP(y, MAX) {
		X = 0;
		O = 0;

		REP(x, MAX)
			add(board[x][y]);
		
		if (O == 4)
			return 0;
		if (X == 4)
			return 1;
	}

	// diagonal l->r
	X = 0;
	O = 0;
	REP(x, MAX)
		add(board[x][x]);
		
	if (O == 4)
		return 0;
	if (X == 4)
		return 1;

	// diagonal r->l
	X = 0;
	O = 0;
	REP(x, MAX)
		add(board[x][MAX-1-x]);

	if (O == 4)
		return 0;
	if (X == 4)
		return 1;

	if (dots)
		return -1;

	return 2;
}

int main() {
	int n;

	scanf("%d", &n);
	REP(q, n) {
		REP(i, MAX)
			scanf("%s", board[i]);

		printf("Case #%d: ", q+1);
		switch (parse()) {
			case -1: printf("Game has not completed"); break;
			case 0: printf("O won"); break;
			case 1: printf("X won"); break;
			case 2: printf("Draw"); break;
		}
		printf("\n");
	}

	return 0;
}
