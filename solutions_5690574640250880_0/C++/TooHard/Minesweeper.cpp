//
// Minesweeper.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 11 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define MAXN 55

char board[MAXN][MAXN];
int R, C, M;

void print_board(char a[MAXN][MAXN]) {
    for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	    printf("%c", board[i][j]);
	}
	printf("\n");
    }
}

void reset() {
    for (int i = 0; i < MAXN; i++)
	for (int j = 0; j < MAXN; j++) 
	    board[i][j] = '.';
}

int space;

void solve1(int numR) {
    int xx = space;
    int numC = space / numR;
    if (space % numR) numC++;
    for (int j = 0; j < numC; j++) {
	for (int i = 0; i < numR; i++) {
	    if (xx) {
		xx--;
		board[i][j] = '.';
	    }
	}
    }
    board[0][0] = 'c';
    print_board(board);
}

void solve2(int numC) {
    int xx = space;
    int numR = space / numC;
    if (space % numC) numR++;
    for (int i = 0; i < numR; i++) {
	for (int j = 0; j < numC; j++) {
	    if (xx) {
		xx--;
		board[i][j] = '.';
	    }
	}
    }
    board[0][0] = 'c';
    print_board(board);
}

void solve11(int numR) {
    int xx = space;
    int numC = space / numR;
    if (space % numR) numC++;
    for (int j = 0; j < numC; j++) {
	for (int i = 0; i < numR; i++) {
	    if (xx) {
		if (xx == 1) {
		    board[numR - 1][numC - 2] = '*';
		    board[i + 1][j] = '.';
		}
		xx--;
		board[i][j] = '.';
	    }
	}
    }
    board[0][0] = 'c';
    print_board(board);
}

void solve22(int numC) {
    int xx = space;
    int numR = space / numC;
    if (space % numC) numR++;
    for (int i = 0; i < numR; i++) {
	for (int j = 0; j < numC; j++) {
	    if (xx) {
		if (xx == 1) {
		    board[numR - 2][numC - 1] = '*';
		    board[i][j + 1] = '.';
		}
		xx--;
		board[i][j] = '.';
	    }
	}
    }
    board[0][0] = 'c';
    print_board(board);
}

void solve() {
    scanf("%d %d %d", &R, &C, &M);
    for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	    board[i][j] = '*';
	}
    }

    if (R * C - 1 == M) {
	board[0][0] = 'c';
	print_board(board);
	return ;
    }

    space = R * C - M;
    for (int i = 1; i <= R && i <= space; i++) {
	int numR = i;
	int numC = space / numR;
	int left = space % numR;
	if (left) numC++;
	if (numC > C) continue;
	if (numC == 1) {
	    if (C == 1) {
		solve1(i);
		return ;
	    }
	} else if (numR > 1) { // numC > 1
	    if (left == 0) {
		solve1(i);
		return ;
	    } else if (numC > 2 && left >= 2) {
		solve1(i);
		return ;
	    } else if (numR > 2 && numC > 3 && left == 1) {
		solve11(i);
		return ;
	    }
	}
    }

    space = R * C - M;
    for (int i = 1; i <= C && i <= space; i++) {
	int numC = i;
	int numR = space / numC;
	int left = space % numC;
	if (left) numR++;
	if (numR > R) continue;
	if (numR == 1) {
	    if (R == 1) {
		solve2(i);
		return ;
	    }
	} else if (numC > 1) { // numR > 1
	    if (left == 0) {
		solve2(i);
		return ;
	    } else if (numR > 2 && left >= 2) {
		solve2(i);
		return ;
	    } else if (numC > 2 && numR > 3 && left == 1) {
		solve22(i);
		return ;
	    }
	}
    }
    
    printf("Impossible\n");
}


int main() {
    int test;
    scanf("%d", &test);
    for (int tt = 0; tt < test; tt++) {
	printf("Case #%d:\n", tt + 1);
	solve();
    }   
    return 0;
}
