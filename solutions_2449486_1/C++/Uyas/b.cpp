#include <cstdio>
#include <cstring>

int n, m, a[111][111], b[111][111];

void box() {
    return ;
    for (int i = 0; i <= n + 1; ++i)
        a[i][0] = a[i][m + 1] = -1;
    for (int j = 0; j <= m + 1; ++j)
        a[0][j] = a[n + 1][j] = -1;
}

bool solved() {
    while (n > 1 && m > 1) {
        int si = 1, sj = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i][j] < a[si][sj])
                    si = i, sj = j;
        bool cutByCol = true;
        bool cutByRow = true;
    /*
        printf("n=%d,m=%d\n", n, m);
         for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                printf("%d ", a[i][j]);
            puts("");
        }
        printf("si=%d,sj=%d\n", si, sj);
    */
        for (int i = 1; i <= n; ++i)
            if (a[i][sj] != a[si][sj])
                cutByCol = false;
        for (int j = 1; j <= m; ++j)
            if (a[si][j] != a[si][sj])
                cutByRow = false;
        if (!cutByCol && !cutByRow) return false;
        if (cutByCol) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j < sj; ++j)
                    b[i][j] = a[i][j];
            for (int i = 1; i <= n; ++i)
                for (int j = sj; j < m; ++j)
                    b[i][j] = a[i][j + 1];
            --m;
        } else {
            for (int i = 1; i < si; ++i)
                for (int j = 1; j <= m; ++j)
                    b[i][j] = a[i][j];
            for (int i = si; i < n; ++i)
                for (int j = 1; j <= m; ++j)
                    b[i][j] = a[i + 1][j];
            --n;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = b[i][j];

    }
    return true;
}


void run(int cas){
    printf("Case #%d: ", cas);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    box();
    if (solved()) puts("YES");
        else puts("NO");
}

int main() {
    freopen("b4.in", "r", stdin);
    freopen("b4.out", "w", stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        run(i);
    return 0;
}
