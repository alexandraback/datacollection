#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using std::vector;
char board[50][50];

void print_board(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void solve(int id) {
	// local variables
    int r, c, m;
	// read data
    std::cin>>r>>c>>m;
	// process
    int nspace = r * c - m;
    if((r==1||c==1)){
        if (nspace == 0) {
            printf("Case #%d:\nImpossible\n", id);
            return;
        } else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (nspace > 0) {
                        board[i][j] = '.';
                        nspace--;
                    } else {
                        board[i][j] = '*';
                    }
                }
            }
            board[0][0] == 'c';
            print_board(r, c);
            return;
        }
    }
    if (nspace < 4) {
        printf("Case #%d:\nImpossible\n", id);
        return;
    }
    int d1 = 2, d2 = 2;
    int max_d = std::max(r, c);
    int min_d = std::min(r, c);
    for (; d1<r; d1++) {
        for (; d2<c; d2++) {
            int remain =  nspace - d1 * d2;
            if (remain < 0) break;
            for (int i = 2; i < r-d1; i++) {

        }
    }

	// output
	printf("Case #%d:\n", id);
}

int main(int argc, char *argv[]) {
	int t = 0;
	std::cin>>t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}