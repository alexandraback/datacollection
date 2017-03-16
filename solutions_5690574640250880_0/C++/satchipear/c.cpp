#include <stdio.h>
char g[55][55];

bool canWork(int r, int c, int m) {
    if (m == 0) {
        return true;
    }
    if (m == r * c) {
        return false;
    }
    if (r < c) {
        if (m >= r) {
            for (int i = 0; i < r; i++) {
                g[i][c - 1] = '*';
            }
            return canWork(r, c - 1, m - r);
        } else if (m == r - 1) {
            if (r == 2) {
                return false;
            }
            for (int i = 0; i < r - 2; i++) {
                g[r - i - 1][c - 1] = '*';
            }
            g[r - 1][c - 2] = '*';
            return true;
        } else {
            for (int i = 0; i < m; i++) {
                g[r - i - 1][c - 1] = '*';
            }
            return true;
        }
    } else {
        if (r == 2) {
            return false;
        }
        if (m >= r * 2 - 1) {
            for (int i = 0; i < c; i++) {
                g[r - 1][i] = '*';
            }
            for (int i = 0; i < r; i++) {
                g[i][c - 1] = '*';
            }
            return canWork(r - 1, c - 1, m - (r * 2 - 1));
        } else if (m >= r) {
            for (int i = 0; i < c; i++) {
                g[r - 1][i] = '*';
            }
            return canWork(r - 1, c, m - r);
        } else if (m == r - 1) {
            if (r == 3) {
                return false;
            }
            for (int i = 0; i < r - 2; i++) {
                g[r - i - 1][c - 1] = '*';
            }
            g[r - 1][c - 2] = '*';
            return true;
        } else {
            for (int i = 0; i < m; i++) {
                g[r - i - 1][c - 1] = '*';
            }
            return true;
        }
    }
}

bool check(int r, int c) {
    int cnt[55][55];
    const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cnt[i][j] = 0;
            if (g[i][j] != '*') {
                for (int k = 0; k < 8; k++) {
                    int di = i + dir[k][0];
                    int dj = j + dir[k][1];
                    if (di >= 0 && di < r && dj >= 0 && dj < c && g[di][dj] == '*') {
                        cnt[i][j]++;
                    }
                }
            } else {
                cnt[i][j] = -1;
            }
        }
    }

    if (cnt[0][0] > 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i != 0 || j != 0) && cnt[i][j] > 0) {
                    return false;
                }
            }
        }
        return true;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cnt[i][j] > 0) {
                bool ok = false;
                for (int k = 0; k < 8; k++) {
                    int di = i + dir[k][0];
                    int dj = j + dir[k][1];
                    if (di >= 0 && di < r && dj >= 0 && dj < c && cnt[di][dj] == 0) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                g[i][j] = '.';
            }
        }
        g[0][0] = 'c';

        int r, c, m;
        scanf("%d%d%d", &r, &c, &m);

        printf("Case #%d:\n", cn);

        if (m == r * c - 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i == 0 && j == 0) {
                        printf("c");
                    } else {
                        printf("*");
                    }
                }
                printf("\n");
            }
            continue;
        }

        //printf("%d %d %d:\n", r, c, m);
        bool hasRotated = false;
        if (r > c) {
            hasRotated = true;
            int t = r;
            r = c;
            c = t;
        }

        if (canWork(r, c, m)) {
            
            /*
            if (!check(r, c)) {
                printf("Oh shit!\n");
            }
            */
            
            if (!hasRotated) {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        printf("%c", g[i][j]);
                    }
                    printf("\n");
                }
            } else {
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < r; j++) {
                        printf("%c", g[j][i]);
                    }
                    printf("\n");
                }
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
