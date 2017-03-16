#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int run;
int n, m, M, C;
char s[57][57];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            putchar(s[i][j]);
        }
        puts("");
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &M);
    printf("Case #%d:\n", run);
    C = n*m-M;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = '*';
        }
    }
    if (M == 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = '.';
            }
        }
        s[1][1] = 'c';
        print();
        return;
    }
    if (C == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    putchar('c');
                } else {
                    putchar('*');
                }
            }
            puts("");
        }
        return;
    }
    if (n == 1) {
        putchar('c');
        for (int i = 1; i < C; i++) {
            putchar('.');
        }
        for (int i = C+1; i <= m; i++) {
            putchar('*');
        }
        puts("");
        return;
    }
    if (m == 1) {
        puts("c");
        for (int i = 1; i < C; i++) {
            puts(".");
        }
        for (int i = C+1; i <= n; i++) {
            puts("*");
        }
        return;
    }
    if (n == 2) {
        if (C%2 || C < 4) {
            puts("Impossible");
            return;
        }
        C /= 2;
        putchar('c');
        for (int i = 1; i < C; i++) {
            putchar('.');
        }
        for (int i = C+1; i <= m; i++) {
            putchar('*');
        }
        puts("");
        for (int i = 1; i <= C; i++) {
            putchar('.');
        }
        for (int i = C+1; i <= m; i++) {
            putchar('*');
        }
        puts("");
        return;
    }
    if (m == 2) {
        if (C%2 || C < 4) {
            puts("Impossible");
            return;
        }
        C /= 2;
        puts("c.");
        for (int i = 1; i < C; i++) {
            puts("..");
        }
        for (int i = C+1; i <= n; i++) {
            puts("**");
        }
        return;
    }
    s[1][1] = 'c';
    s[1][2] = s[2][1] = s[2][2] = '.';
    C -= 4;
    if (C < 0) {
        puts("Impossible");
        return;
    }
    if (C%2) {
        if (C < 5) {
            puts("Impossible");
            return;
        }
        for (int i = 3; i <= m; i++) {
            if (C == 3) break;
            C -= 2;
            s[1][i] = s[2][i] = '.';
        }
        if (C == 3) {
            s[3][1] = s[3][2] = s[3][3] = '.';
            print();
            return;
        }
        if (m%2) {
            if (C <= m) {
                for (int i = 1; i <= C; i++) {
                    s[3][i] = '.';
                }
            } else {
                C -= m;
                for (int i = 1; i <= m; i++) {
                    s[3][i] = '.';
                }
                for (int i = 4; i <= n; i += 2) {
                    if (C == 0) break;
                    C -= 2;
                    s[i][1] = s[i][2] = '.';
                    if (C == 0) break;
                    C -= 2;
                    s[i+1][1] = s[i+1][2] = '.';
                    for (int j = 3; j <= m; j++) {
                        if (C == 0) break;
                        C -= 2;
                        s[i][j] = s[i+1][j] = '.';
                    }
                }
                for (int j = 1; j <= m; j += 2) {
                    if (C == 0) break;
                    C -= 2;
                    s[n][j] = s[n][j+1] = '.';
                }
            }
        } else {
            int pos = 3;
            while (pos < n && C-m >= 3) {
                for (int i = 1; i <= m; i++) {
                    s[pos][i] = '.';
                }
                pos++;
                C -= m;
            }
            if (C <= m) {
                for (int i = 1; i <= C; i++) {
                    s[3][i] = '.';
                }
            } else {
                for (int i = 1; i <= m-2; i++) {
                    s[pos][i] = '.';
                }
                s[pos+1][1] = s[pos+1][2] = s[pos+1][3] = '.';
                if (s[pos][3] == '*') {
                    swap(s[pos][3], s[pos+1][3]);
                }
            }
        }
        print();
    } else {
        for (int i = 3; i <= m; i++) {
            if (C == 0) break;
            C -= 2;
            s[1][i] = s[2][i] = '.';
        }
        for (int i = 3; i <= n; i += 2) {
            if (C == 0) break;
            C -= 2;
            s[i][1] = s[i][2] = '.';
            if (C == 0) break;
            C -= 2;
            s[i+1][1] = s[i+1][2] = '.';
            for (int j = 3; j <= m; j++) {
                if (C == 0) break;
                C -= 2;
                s[i][j] = s[i+1][j] = '.';
            }
        }
        for (int j = 1; j <= m; j += 2) {
            if (C == 0) break;
            C -= 2;
            s[n][j] = s[n][j+1] = '.';
        }
        print();
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) {
        solve();
    }
    return 0;
}
