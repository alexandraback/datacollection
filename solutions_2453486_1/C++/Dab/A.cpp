#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

const char* X_WON = "X won";
const char* O_WON = "O won";
const char* DRAW = "Draw";
const char* NOT_COMPLETED = "Game has not completed";

const int SIZE = 4;

char a[SIZE+1][SIZE+1];


bool f(int x, int y, int dx, int dy, char who) {
	int res = 0;
	for(int i = 0; i < 4; i++) {
		if(a[x][y] == who || a[x][y] == 'T') res++;
		x += dx;
		y += dy;
	}
	return res == 4;
}

const char* solve() {
	for(int i = 0; i < SIZE; i++) {
		scanf("%s", a[i]);
	}

	for(int i = 0; i < SIZE; i++) {
		if(f(i, 0, 0, 1, 'X')) return X_WON;
		if(f(i, 0, 0, 1, 'O')) return O_WON;
		if(f(0, i, 1, 0, 'X')) return X_WON;
		if(f(0, i, 1, 0, 'O')) return O_WON;
	}
	
	if(f(0, 0, 1, 1, 'X')) return X_WON;
	if(f(0, 0, 1, 1, 'O')) return O_WON;

	
	if(f(0, SIZE-1, 1, -1, 'X')) return X_WON;
	if(f(0, SIZE-1, 1, -1, 'O')) return O_WON;


	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			if(a[i][j] == '.') return NOT_COMPLETED;
		}
	}
	return DRAW;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %s\n", i, solve());
	}
}