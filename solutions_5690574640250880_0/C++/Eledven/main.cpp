#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

char a[55][55];
char b[55][55];
void rot(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
    memcpy(a, b, sizeof(a));
}

int rem;
int cnt[111];
bool can(int pos, int full, int x, int n, int need) {
    if (full + pos > n) {
        return false;
    }
    if (need == 0) {
        rem = pos;
        return true;
    }
    if (need == 1) {
        return false;
    }
    if (x == 2) {
        return false;
    }
    int cur = min(x - 1, need);
    cnt[pos] = cur;
    return can(pos + 1, full, x, n, need - cur);
}

bool solve(int n, int m, int bombs) {
    eprintf("n = %d m = %d bombs = %d\n", n, m, bombs);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '*';
        }
    }
    int empty = n * m - bombs;
    if (empty == n * m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = '.';
            }
        }
        a[0][0] = 'c';
        return true;
    }
    if (empty == 1) {
        a[0][0] = 'c';
        return true;
    }
    if (n == 1) {
        a[0][0] = 'c';
        for (int i = 1; i < empty; i++) {
            a[0][i] = '.';
        }
        return true;
    }
    int x = -1;
    int full = -1;
    for (int xx = 2; x == -1 && xx <= m; xx++) {
        for (int f = 2; f <= n; f++) {
            if (xx * f > empty) {
                continue;
            }
            if (can(0, f, xx, n, empty - xx * f)) {
                x = xx;
                full = f;
                break;
            }
        }
    }
    if (x == -1) {
        return false;
    }
    eprintf("x = %d full = %d rem = %d\n", x, full, rem);
    for (int i = 0; empty > 0 && i < full; i++) {
        for (int j = 0; empty > 0 && j < x; j++) {
            a[i][j] = '.';
            empty--;
        }
    }
    for (int i = 0; i < rem; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            a[i + full][j] = '.';
        }
    }
    a[0][0] = 'c';
    return true;
}

bool was[55][55];
void dfs(int i, int j, int n, int m) {
    was[i][j] = true;
    bool ok = true;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) {
                continue;
            }
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                continue;
            }
            ok &= a[ni][nj] != '*';
        }
    }
    if (ok) {
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) {
                    continue;
                }
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    continue;
                }
                if (!was[ni][nj]) {
                    dfs(ni, nj, n, m);
                }
            }
        }
    }
}

bool check(int n, int m, int needBombs, bool out) {
    int bombs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            was[i][j] = false;
            bombs += a[i][j] == '*';
        }
    }
    if (bombs != needBombs) {
        if (out) {
            eprintf("WA! Need bombs: %d found bombs: %d\n", needBombs, bombs);
        }
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'c') {
                dfs(i, j, n, m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '*' && !was[i][j]) {
                if (out) {
                    eprintf("WA cell (%d, %d) is not marked\n", i, j);
                }
                return false;
            }
        }
    }
    if (out) {
        eprintf("OK\n");
    }
    return true;
}

bool solveSlow(int n, int m, int bombs) {
    for (int mask = 0; mask < 1 << (n * m); mask++) {
        if (__builtin_popcount(mask) != bombs) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((mask >> (i * m + j)) & 1) {
                    a[i][j] = '*';
                } else {
                    a[i][j] = '.';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    a[i][j] = 'c';
                    if (check(n, m, bombs, false)) {
                        return true;
                    }
                    a[i][j] = '.';
                }
            }
        }
    }
    return false;
}

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        eprintf("test %d\n", tt);
        int n, m, bombs;
        assert(scanf("%d%d%d", &n, &m, &bombs) == 3);
        printf("Case #%d:\n", tt);
        if (solve(n, m, bombs)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    putchar(a[i][j]);
                }
                putchar('\n');
            }
            if (!check(n, m, bombs, true)) {
                exit(42);
            }
        } else if (solve(m, n, bombs)) {
            rot(m, n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    putchar(a[i][j]);
                }
                putchar('\n');
            }
            if (!check(n, m, bombs, true)) {
                exit(42);
            }
        } else {
            bool ret = solveSlow(n, m, bombs);
            if (ret) {
                eprintf("WA! Solution not found!\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        eprintf("%c", a[i][j]);
                    }
                    eprintf("\n");
                }
                exit(42);
            }
            puts("Impossible");
        }
    }
    return 0;
}
