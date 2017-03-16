#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

char board[50][50];

void initial(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] = '.';
        }
    }
    board[0][0] = 'c';
}
void print_board(int id, int r, int c) {
    printf("Case #%d:\n", id);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool solve(int id, int r, int c, int m) {
	// process
    int nspace = r * c - m;
    if (nspace == 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '*';
            }
        }
        board[0][0] = 'c';
        return true;
    }
    int dmin = r; int dmax = c;
    bool short_row = true;
    if (r > c) {
        short_row = false;
        dmin = c;
        dmax = r;
    }
    int delta = 0;
    if (m / dmin > 0) delta  = 1;
    int remain = m - delta * dmin;
    
    if (short_row) {
        // fill column
        for (int i = c-delta; i < c; i++) {
            for (int j = 0; j < r; j++) {
                board[j][i] = '*';
            }
        }
        c = c - delta;
    } else {
        // fill row
        for (int i = r-delta; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '*';
            }
        }
        r = r - delta;
    }
    if (delta > 0 && remain > 0) {
        return solve(id, r, c, remain);
    } else {
        if (remain == 0) {
            if (r >= 2 && c >= 2) return true;
            else return false;
        } else {
            // fill the mines from bottom right corner
            int ir = r-1, ic =  c-1;
            while (ir > 1) {
                while (ic > 1) {
                    board[ir][ic] = '*';
                    remain--;
                    if (remain == 0) return true;
                    ic--;
                }
                ir--;
                ic = c-1;
            }
            if (remain > 0) return false;
        }
    }
}

int main(int argc, char *argv[]) {
	int t = 0;
	std::cin>>t;
	for (int i = 1; i <= t; i++) {
        int r, c, m;
	    // read data
        std::cin>>r>>c>>m;
        initial(r, c);
        if (r == 1) {
            for (int j = 1; j <= m; j++) {
                board[0][c - j] = '*';
            }
            if (m < c) print_board(i, r, c);
            else printf("Case #%d:\nImpossible\n", i);
        }
        else if (c == 1) {
            for (int j = 1; j <= m; j++) {
                board[r - j][0] = '*';
            }
            if (m < r) print_board(i, r, c);
            else printf("Case #%d:\nImpossible\n", i);
        }
		else if (solve(i, r, c, m)) print_board(i, r, c);
        else {
            printf("Case #%d:\nImpossible\n", i);
        }
	}
}