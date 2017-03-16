// Google Code Jam Qualification Round 2013 Problem B
// Lawnmower
// by A Code Rabbit

#include <cstdio>

const int MAXN = 102;

int N, M;
int a[MAXN][MAXN];

bool check(int x, int y) {
    bool bo1 = true, bo2 = true;
    for (int i = 0; i < N; i++)
        if (a[i][y] > a[x][y])
            bo1 = false;
    for (int i = 0; i < M; i++)
        if (a[x][i] > a[x][y])
            bo2 = false;
    return bo1 || bo2;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &a[i][j]);

        bool bo = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!check(i, j)) bo = true;
    
        printf("Case #%d: %s\n", cas, bo ? "NO" : "YES");
    }

    return 0;
}
