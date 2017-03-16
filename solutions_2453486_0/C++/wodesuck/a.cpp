#include <stdio.h>

char buf[4][5];

inline
bool f(int i, int j, char c)
{ return buf[i][j] == c || buf[i][j] == 'T'; }

bool win(char c)
{
	for (int i = 0; i < 4; ++i) {
		if (f(i, 0, c) && f(i, 1, c) && f(i, 2, c) && f(i, 3, c))
			return true;
	}
	for (int i = 0; i < 4; ++i) {
		if (f(0, i, c) && f(1, i, c) && f(2, i, c) && f(3, i, c))
			return true;
	}
	if (f(0, 0, c) && f(1, 1, c) && f(2, 2, c) && f(3, 3, c)) return true;
	if (f(0, 3, c) && f(1, 2, c) && f(2, 1, c) && f(3, 0, c)) return true;
	return false;
}

bool comp()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (buf[i][j] == '.') return false;
		}
	}
	return true;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		for (int i = 0; i < 4; ++i) scanf("%s", buf[i]);
		printf("Case #%d: ", k);
		if (win('O')) { puts("O won"); continue; }
		if (win('X')) { puts("X won"); continue; }
		puts(comp() ? "Draw" : "Game has not completed");
	}
}
