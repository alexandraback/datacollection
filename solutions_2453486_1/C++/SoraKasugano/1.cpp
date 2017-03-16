#include <cstdio>
char a[4][5];
#define G(a) ((a) == 'T' || (a) == (c))
bool ok(char c) {
    for (int i = 0 ; i < 4 ; ++i)
        if (G(a[i][0]) && G(a[i][1]) && G(a[i][2]) && G(a[i][3]))
            return true;
    for (int i = 0 ; i < 4 ; ++i)
        if (G(a[0][i]) && G(a[1][i]) && G(a[2][i]) && G(a[3][i]))
            return true;
    if (G(a[0][0]) && G(a[1][1]) && G(a[2][2]) && G(a[3][3])) return true;
    if (G(a[0][3]) && G(a[1][2]) && G(a[2][1]) && G(a[3][0])) return true;
    return false;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int c = 1 ; c <= t ; ++c) {
        bool f = true;
        for (int i = 0 ; i < 4 ; ++i) {
            scanf("%s", a[i]);
            for (int j = 0 ; j < 4 ; ++j) if (a[i][j] == '.') f = false;
        }
        printf("Case #%d: ", c);
        if (ok('X')) puts("X won");
        else if (ok('O')) puts("O won");
        else if (f) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}

