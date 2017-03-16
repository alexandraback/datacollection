#include <cstdio>

char s[10][10];

bool win(char ch) {
    for (int i = 0; i < 4; ++i) {
        bool flag = true;
        for (int j = 0; j < 4 && flag; ++j)
            if (s[i][j] != 'T' && s[i][j] != ch)
                flag = false;
        if (flag)
            return true;
    }
    for (int j = 0; j < 4; ++j) {
        bool flag = true;
        for (int i = 0; i < 4 && flag; ++i)
            if (s[i][j] != 'T' && s[i][j] != ch)
                flag = false;
        if (flag)
            return true;
    }
    bool flag = true;
    int x = 0, y = 0;
    for (int i = 0; i < 4 && flag; ++i, ++x, ++y)
        if (s[x][y] != 'T' && s[x][y] != ch)
            flag = false;
    if (flag)
        return true;

    flag = true;
    x = 3, y = 0;
    for (int i = 0; i < 4 && flag; ++i, --x, ++y)
        if (s[x][y] != 'T' && s[x][y] != ch)
            flag = false;
    if (flag)
        return true;

    return false;
}

bool over() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (s[i][j] == '.')
                return false;
    return true;
}

void solve() {
    if (win('X'))
        puts("X won");
    else if (win('O'))
        puts("O won");
    else if (over())
        puts("Draw");
    else
        puts("Game has not completed");
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 4; ++i)
            scanf("%s", s[i]);
        printf("Case #%d: ", ++cas);
        solve();
    }
    return 0;
}
