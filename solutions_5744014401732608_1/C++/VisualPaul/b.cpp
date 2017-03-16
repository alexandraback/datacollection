#include <bits/stdc++.h>

int res[50][50];

bool solve(int n, int64_t b) {
    if (1ll << (n - 2) < b)
        return false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = 0;
        }
    }
    res[0][n-1] = 1;
    --b;
    for (int i = n - 2; i > 0; --i)
        for (int j = i + 1; j < n; ++j)
            res[i][j] = 1;
    for (int i = n - 2; i > 0; --i) {
        if (b & 1) {
            res[0][i] = 1;
        }
        b >>= 1;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        long long int b;
        scanf("%d%lld", &n, &b);
        printf("Case #%d: ", i + 1);
        bool r = solve(n, b);
        puts(r? "POSSIBLE" : "IMPOSSIBLE");
        if (!r)
            continue;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                printf("%d", res[x][y]);
            }
            putchar('\n');
        }
    }
    
}
