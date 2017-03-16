#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

const int maxn = 60;

int f[maxn][maxn * maxn][maxn];
bool answer;
char mat[maxn][maxn];
int row, col;

bool construct(int r, int c, bool reversed, int m) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mat[i][j] = '*';
        }
    }
    if (r == 1 && m > 0) {
        for (int i = 0; i < m; ++i) {
            mat[0][i] = '.';
        }
        mat[0][0] = 'c';
        return true;
    } else if (m == 1) {
        mat[0][0] = 'c';
        return true;
    } else {
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= c; ++k) {
                    f[i][j][k] = -1;
                }
            }
        }
        for (int i = 2; i * 2 <= m && i <= c; ++i) {
            f[2][m - i * 2][i] = 0;
        }
        for (int i = 2; i < r; ++i) {
            for (int j = m; j > 0; --j) {
                for (int k = 2; k <= c; ++k) {
                    if (f[i][j][k] >= 0) {
                        if (j >= k) {
                            f[i + 1][j - k][k] = k;
                        }
                        if (j >= k - 1 && k - 1 >= 2) {
                            f[i + 1][j - k + 1][k - 1] = k;
                        }
                    }
                }
            }
        }
        for (int i = 2; i <= r; ++i) {
            for (int j = 2; j <= c; ++j) {
                if (f[i][0][j] >= 0) {
                    int row = i, cnt = 0, last = j;
                    while (f[row][cnt][last] > 0) {
                        for (int k = 0; k < last; ++k) {
                            mat[row - 1][k] = '.';
                        }
                        int nlast = f[row][cnt][last];
                        cnt += last;
                        row -= 1;
                        last = nlast;
                    }
                    assert(row == 2);
                    for (int k = 0; k < last; ++k) {
                        mat[0][k] = mat[1][k] = '.';
                    }
                    mat[0][0] = 'c';
                    return true;
                }
            }
        }
    }
    return false;
}

void show(bool reversed) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (reversed) {
                putchar(mat[j][i]);
            } else {
                putchar(mat[i][j]);
            }
        }
        puts("");
    }
}

void solve() {
    int r, c, m;
    scanf("%d%d%d", &r, &c, &m);
    row = r;
    col = c;
    m = r * c - m;
    bool reversed = false;
    if (r > c) {
        reversed = true;
        swap(r, c);
    }
    if (construct(r, c, reversed, m)) {
        show(reversed);
        return;
    }
    if (construct(c, r, !reversed, m)) {
        show(!reversed);
        return;
    }
    puts("Impossible");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        printf("Case #%d:\n", caseId);
        solve();
    }
}
