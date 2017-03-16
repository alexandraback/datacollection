#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, X, Y;
int min;
char way[501];

int rec(int moves, int x, int y) {
	if(moves > 30)
		return 0;

	if(x == X && y == Y && moves <= 500) {
		way[moves] = '\0';
		return 1;
	}

	if(x < X && X - x > moves) {
		way[moves] = 'E';
		if(rec(moves+1, x + moves+1, y)) {
			return 1;
		}
	}
	else if(x > X && x - X > moves) {
		way[moves] = 'W';
		if(rec(moves+1, x - (moves+1), y)) {
			return 1;
		}
	} else {
		if(x < X) {
			way[moves] = 'E';
			if(rec(moves+1, x + moves+1, y)) {
				return 1;
			}
			way[moves] = 'W';
			if(rec(moves+1, x - (moves+1), y)) {
				return 1;
			}
		} else {
			way[moves] = 'W';
			if(rec(moves+1, x - (moves+1), y)) {
				return 1;
			}
			way[moves] = 'E';
			if(rec(moves+1, x + moves+1, y)) {
				return 1;
			}
		}
	}
	if(y < Y && Y - y > moves) {
		way[moves] = 'N';
		if(rec(moves+1, x, y + moves+1)) {
			return 1;
		}
	}
	else if(y > Y && y - Y > moves) {
		way[moves] = 'S';
		if(rec(moves+1, x, y - (moves+1))) {
			return 1;
		}
	}
	else {
		if(y < Y) {
			way[moves] = 'N';
			if(rec(moves+1, x, y + moves+1)) {
				return 1;
			}
			way[moves] = 'S';
			if(rec(moves+1, x, y - (moves+1))) {
				return 1;
			}
		} else {
			way[moves] = 'S';
			if(rec(moves+1, x, y - (moves+1))) {
				return 1;
			}
			way[moves] = 'N';
			if(rec(moves+1, x, y + moves+1)) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	int i;

	scanf("%d", &T);

	for(i = 0; i < T; i++) {

		scanf("%d %d", &X, &Y);

		int a = rec(0, 0, 0);
		/*printf("a %d\n", a);*/

		printf("Case #%d: %s\n", i+1, way);
	}


	return 0;
}
