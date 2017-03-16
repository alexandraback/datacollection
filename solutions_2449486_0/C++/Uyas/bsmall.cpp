#include <cstdio>
#include <cstring>

int n, m, a[111][111], b[111][111];

bool solved() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            b[i][j] = 2;
    for (int i = 1; i <= n; ++i) {
        bool yes = true;
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != 1) yes = false;
        if (yes)
            for (int j = 1; j <= m; ++j)
                b[i][j] = 1;
    }
    for (int j = 1; j <= m; ++j) {
        bool yes = true;
        for (int i = 1; i <= n; ++i)
            if (a[i][j] != 1) yes = false;
        if (yes)
            for (int i = 1; i <= n; ++i)
                b[i][j] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != b[i][j]) return false;
    return true;
}


void run(int cas){
    printf("Case #%d: ", cas);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    if (solved()) puts("YES");
        else puts("NO");
}

int main() {
    freopen("b3.in", "r", stdin);
    freopen("b33.out", "w", stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        run(i);
    return 0;
}
