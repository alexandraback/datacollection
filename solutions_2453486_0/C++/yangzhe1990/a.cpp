#include <cstdio>
#include <string>
#include <algorithm>

inline void read_board(char *board) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			board[i * 4 + j] = getchar();
		scanf("\n");
	}
}

typedef enum {
	X_WIN,
	O_WIN,
	NA,
} game_result;

inline game_result result_by_line(int line[2], char *board) {
	int s = line[0]; int d = line[1];

	int cx = 0, co = 0, ct = 0;
	for (int i = 0; i < 4; ++i, s += d) {
		char c = board[s];
		if (c == '.')
			return NA;
		else if (c == 'T')
			++ct;
		else if (c == 'X')
			++cx;
		else
			++co;
		if (cx > 0 && co > 0)
			return NA;
	}
	if (cx > 0)
		return X_WIN;
	else
		return O_WIN;
}

inline std::string get_result(char *board) {
	bool finished = false;
	if (std::find(board, board + 16, '.') == board + 16)
		finished = true;
	const int n_lines = 10;
	static int lines[n_lines][2] = {{0,1}, {4,1}, {8,1}, {12,1},
					{0,4}, {1,4}, {2,4}, {3,4},
					{0,5}, {3,3}};
	game_result r;
	for (int i = 0; i < n_lines; ++i) {
		r = result_by_line(lines[i], board);
		if (r != NA)
			if (r == X_WIN)
				return "X won";
			else
				return "O won";
	}
	if (finished)
		return "Draw";
	else
		return "Game has not completed";
}

int main() {
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		char board[16];
		read_board(board);
		scanf("\n");
		printf("Case #%d: %s\n", i, get_result(board).c_str());
	}
}
