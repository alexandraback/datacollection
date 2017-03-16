#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

struct Cell {
    int i;
    int j;
    int index;
    Cell(int i, int j, int R, int C) {
        this->i = i;
        this->j = j;
        this->index = max(R - i, C - j);
    }
    bool operator <(const Cell &other) const {
        if (index != other.index) return index < other.index;
        if (i != other.i) return i > other.i;
        return j > other.j;
    }
};

int main() {
    int T;
    scanf("%d", &T);

    for (int t=1; t <= T; ++t) {
        printf("Case #%d:\n", t);

        int R, C, M;
        scanf("%d %d %d", &R, &C, &M);
        int freeCells = R * C - M;

        vector <Cell> cells;
        for (int i=0; i < R; ++i) {
            for (int j=0; j < C; ++j) {
                cells.push_back(Cell(i, j, R, C));
            }
        }
        sort(cells.begin(), cells.end());

        char field[R][C];
        memset(field, '*', sizeof(field));
        field[R-1][C-1] = 'c';

        for (int i=1; i < freeCells; ++i) {
            field[cells[i].i][cells[i].j] = '.';
        }

        bool canWinInOne = (R == 1) || (C == 1) || (freeCells == 1);
        if (freeCells >= 4) {
            if (cells[freeCells - 1].index != cells[freeCells - 2].index ||
                (cells[freeCells - 1].i != cells[freeCells - 2].i && cells[freeCells - 1].j != cells[freeCells - 2].j)) {
                if (R > 2 && C > 2 && freeCells > 9) {
                    field[cells[freeCells].i][cells[freeCells].j] = '.';
                    field[cells[freeCells-2].i][cells[freeCells-2].j] = '*';
                    canWinInOne = true;
//                    printf("ADJUSTED: %d %d,%d - %d %d,%d\n",cells[freeCells - 1].index,
//                           cells[freeCells - 1].i, cells[freeCells - 1].j, cells[freeCells - 2].index,
//                           cells[freeCells - 2].i, cells[freeCells - 2].j);
                }
            } else {
                canWinInOne = true;
            }
        }

        if (!canWinInOne) {
            puts("Impossible");
            continue;
        }

//        printf("%d %d %d\n", R, C, M);
        for (int i=0; i < R; ++i) {
            for (int j=0; j < C; ++j) {
                printf("%c", field[i][j]);
            }
            puts("");
        }
//        puts(canWinInOne ? "YES\n" : "NO\n");
    }
	
	return 0;
}
