//
// https://code.google.com/codejam/contest/2974486/dashboard#s=p2
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_SIZE 60
#define MINE '*'
#define CLICK 'c'
#define EMPTY '.'


char board[MAX_SIZE][MAX_SIZE];

bool open[MAX_SIZE][MAX_SIZE];
bool visible[MAX_SIZE][MAX_SIZE];

int n[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

int neighbors(int i, int j, int r, int c) {
    int result = 0;
    FOR(k, 8) {
        int x = i + n[k][0];
        int y = j + n[k][1];
        if (x >= 0 && x < r && y >= 0 && y < c && board[x][y] == MINE) result++;
    }
    return result;
}

void setVisible(int i, int j, int r, int c) {
    FOR(k, 8) {
        int x = i + n[k][0];
        int y = j + n[k][1];
        if (x >= 0 && x < r && y >= 0 && y < c) visible[x][y] = true;
    }
}

void check(int r, int c) {
    bool change = true;

    FOR(i, r) FOR(j, c) open[i][j] = visible[i][j] = false;
    visible[0][0] = true;
    while (change) {
        change = false;
        FOR(i, r) FOR(j, c) if (visible[i][j] && !open[i][j] && neighbors(i, j, r, c) == 0) {
            open[i][j] = true;
            setVisible(i, j, r, c);
            change = true;
        }
    }
    FOR(i, r) FOR(j, c) if ((board[i][j] == EMPTY || board[i][j] == CLICK) && !visible[i][j]) printf("ERROR\n");
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        int r, c, m;
        scanf("%d%d%d", &r, &c, &m);

        printf("Case #%d:\n", cc);

        bool possible = true;
        bool swap = false;
        if (r > c) {
            int temp = r;
            r = c;
            c = temp;
            swap = true;
        }
        FOR(i, r) FOR(j, c) board[i][j] = MINE;

        int free = c * r - m;

        if (r == 1) {
            // this is always possible
            FOR(i, free) board[0][i] = EMPTY;
        } else if (r == 2) {
            // this is possible only if free is even and at least 4 or free is 1
            if (free == 1) {
                // nothing to do here
            } else if ((free & 1) == 0 && free >= 4) {
                free >>= 1;
                FOR(i, free) board[0][i] = board[1][i] = EMPTY;
            } else {
                possible = false;
            }
        } else {
            if (free == 1) {
                // nothing to do here
            } else if (free >= 4 && free != 5 && free != 7) {
                if (free >= 2 * c + 2) {
                    FOR(i, c) board[0][i] = board[1][i] = EMPTY;
                    free -= 2 * c;
                    int row = 2;
                    while (free > 0) {
                        if (free >= 2 * c) {
                            FOR(i, c) board[row][i] = EMPTY;
                            free -= c;
                            row++;
                        } else if (free > c) {
                            if (free - c > 1) {
                                FOR(i, c) board[row][i] = EMPTY;
                                free -= c;
                                row++;
                            } else {
                                FOR(i, c - 1) board[row][i] = EMPTY;
                                free -= c - 1;
                                row++;
                            }
                        } else {
                            FOR(i, free) board[row][i] = EMPTY;
                            free = 0;
                        }
                    }
                } else {
                    if (free <= 2 * c) {
                        if ((free & 1) == 0) {
                            free >>= 1;
                            FOR(i, free) board[0][i] = board[1][i] = EMPTY;
                        } else {
                            free >>= 1;
                            free -= 1;
                            FOR(i, free) board[0][i] = board[1][i] = EMPTY;
                            FOR(i, 3) board[2][i] = EMPTY;
                        }
                    } if (free == 2 * c + 1) {
                        FOR(i, c - 1) board[0][i] = board[1][i] = EMPTY;
                        FOR(i, 3) board[2][i] = EMPTY;
                    }
                }
            } else {
                // impossible
                possible = false;
            }
        }

        board[0][0] = CLICK;
        if (possible) {
            int mines = 0;
            if (swap) {
                FOR(i, c) {
                    FOR(j, r) { printf("%c", board[j][i]); mines += board[j][i] == MINE; }
                    printf("\n");
                }
            } else {
                FOR(i, r) {
                    FOR(j, c) { printf("%c", board[i][j]); mines += board[i][j] == MINE; }
                    printf("\n");
                }
            }
            if (mines != m) printf("ERROR\n");
            check(r, c);
        } else printf("Impossible\n");
    }
}

