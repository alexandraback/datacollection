#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

int n, m, x;
int moo[55][55];

bool fill(int n, int m, int x) {
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            moo[i][j] = 0;

    if (x == 0) return true;

    if (m == 1) {
        for (int i = 0; i < x; ++ i) {
            moo[n - i - 1][0] = 1;

        }
        return true;
    }
    if (n * m == x + 1) {
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                moo[i][j] = 1;
        return true;
    }

    if (n * m - x < 4) return false;

    if (n * m == x + 4) {
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                if (i >= 2 || j >= 2)
                    moo[i][j] = 1;
        return true;
    }

    if (m == 2) {
        if (x % 2 == 1) return false;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                if (i >= (n * m - x) / 2)
                    moo[i][j] = 1;
        return true;
    }

    if (n * m - x == 5 || n * m - x == 7) return false;

    x = n * m - x;
    if (n * 2 + 3 >= x) {
        fprintf(stderr, "mode 1\n");
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                if (i < (x - 2) / 2 && j < 2 || i <= 1 + x % 2 && j == 2)
                    moo[i][j] = 0;
                else moo[i][j] = 1;
        return true;
    }

    fprintf(stderr, "mode 2\n");
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            moo[i][j] = 1;

    int X = 0, Y = 0;
    for (int i = 0; i < x; ++ i) {
        if (x - i == 2 && X == n - 1) {
            X = 0;
            ++ Y;
        }
        moo[X][Y] = 0;
        ++ X;
        if (X == n) {
            ++ Y;
            X = 0;
        }
    }

    return true;
}

bool p[55][55];
int dfs(int x, int y) {
    if (p[x][y]) return 0;
    p[x][y] = 1;
    bool allEmpty = true;
    for (int i = -1; i <= 1; ++ i) {
        for (int j = -1; j <= 1; ++ j) {
            if (i == 0 && j == 0) continue;
            if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m) continue;
            if (moo[x + i][y + j]) { allEmpty = false; }
        }
    }
    int ret = 1;
    if (allEmpty) {
        for (int i = -1; i <= 1; ++ i) {
            for (int j = -1; j <= 1; ++ j) {
                if (i == 0 && j == 0) continue;
                if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= m) continue;
                ret += dfs(x + i, y + j);
            }
        }
    }
    return ret;
}

int main() {
    int t = 1, tt;
    for (scanf("%d", &tt); t <= tt; ++ t) {
        bool possible;
        scanf("%d %d %d", &n, &m, &x);

        if (n < m) {
            possible = fill(m, n, x);
            for (int i = 0; i < n || i < m; ++ i) {
                for (int j = 0; j < i; ++ j) {
                    swap(moo[i][j], moo[j][i]);
                }
            }
        }
        else {
            possible = fill(n, m, x);
        }

        printf("Case #%d:\n", t);
        if (!possible) printf("Impossible\n");
        else {
            for(int i = 0; i < n; ++ i)
                for (int j = 0; j < m; ++ j)
                    p[i][j] = 0;
            assert(dfs(0, 0) == n * m - x);
            for (int i = 0; i < n; ++ i)
            {
                for (int j = 0; j < m; ++ j) 
                {
                    if (!i && !j) printf("c");
                    else printf("%c", moo[i][j] ? '*' : '.');
                    if (!(!i && !j || moo[i][j] == 0)) -- x;
                }
                printf("\n");
            }
            assert(x == 0);
        }
    }

    return 0;
}
