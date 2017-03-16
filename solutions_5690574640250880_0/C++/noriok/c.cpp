#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

const int N = 5;
const int CELL_MINE = 0;
const int CELL_EMPTY = 1;

int countMines(int r, int c, int rows, int cols, int tab[][N]) {
    int mine = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) == 0) continue;

            int row = r + i;
            int col = c + j;

            if (0 <= row && row < rows && 0 <= col && col < cols) {
                if (tab[row][col] == CELL_MINE) {
                    mine++;
                }
            }
        }
    }
    return mine;
}

void display(int r, int c, int rows, int cols, int tab[][N]) {

    For(i, rows) {
        For(j, cols) {
            if (i == r && j == c) {
                putchar('c');
            }
            else {
                switch (tab[i][j]) {
                case CELL_MINE:  putchar('*'); break;
                case CELL_EMPTY: putchar('.'); break;
                default:
                    assert(false);
                }
            }
        }
        puts("");
    }
}

bool openCell(int r, int c, int rows, int cols, int tab[][N]) {
    assert(tab[r][c] == CELL_EMPTY);

    int used[N][N] = {};
    queue< pair<int, int> > q;
    q.push(make_pair(r, c));
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (!(0 <= row && row < rows && 0 <= col && col < cols)) continue;
        if (used[row][col]++) continue;

        int n = countMines(row, col, rows, cols, tab);
        if (n == 0) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) == 0) continue;

                    q.push(make_pair(row + i, col + j));
                }
            }
        }
    }

    int mines = 0;
    int unopendCells = 0;
    For(i, rows) For(j, cols) {
        if (tab[i][j] == CELL_MINE) {
            mines++;
        }
        if (!used[i][j]) {
            unopendCells++;
        }
    }

    if (unopendCells != mines) return false;

    // オープンしたセルに対して、隣接するmineの数が全て一致しているなら、solved
    bool solved = true;
    For(i, rows) For(j, cols) {
        if (!used[i][j]) continue;

        // オープンされていない隣接するセルの個数
        int unopenedCell = 0;
        for (int p = -1; p <= 1; p++) {
            for (int q = -1; q <= 1; q++) {
                if (abs(p) + abs(q) == 0) continue;

                int row = i + p;
                int col = j + q;
                if (0 <= row && row < rows && 0 <= col && col < cols) {
                    if (!used[row][col]) {
                        unopenedCell++;
                    }
                }
            }
        }

        if (unopenedCell != countMines(i, j, rows, cols, tab)) {
            solved = false; // 解いていない
            goto END_P;
        }
    }

END_P:

    if (solved) {
        display(r, c, rows, cols, tab);
    }
    return solved;
}

bool isOneClickSolvable(int rows, int cols, int tab[][N]) {
    For(i, rows) For(j, cols) {
        if (tab[i][j] == CELL_MINE) continue;

        // click
        bool solved = openCell(i, j, rows, cols, tab);
        if (solved) return true;
    }
    return false;
}

void calc(int rows, int cols, int mines) {
    if (mines == 0) {
        For(i, rows) {
            For(j, cols) {
                if (i == 0 && j == 0) {
                    putchar('c');
                }
                else {
                    putchar('.');
                }
            }
            puts("");
        }
        return;
    }

    for (int i = 1; i < (1<<(rows*cols)); i++) {
        int n = __builtin_popcount(i);
        if (n != mines) continue;

        int tab[N][N];
        int p = 0;
        For(j, rows) For(k, cols) {
            bool mine = i & (1 << p++);
            tab[j][k] = mine ? CELL_MINE : CELL_EMPTY;
        }

        if (isOneClickSolvable(rows, cols, tab)) {
            return;
        }
    }

    // not found solution
    puts("Impossible");
}


int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int rows, cols, mines;
        scanf("%d %d %d", &rows, &cols, &mines);

        printf("Case #%d:\n", cc+1);
        calc(rows, cols, mines);
    }
}

