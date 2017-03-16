#include <cstdio>

int C, D, V;
int d[100];
bool dp[101], pd[101];
int c[4];

bool dfs(int x, int i) {
    if (i == x) {
        for (int j = 0; j <= V; j++)
            pd[j] = dp[j];
        for (int j = 0; j < i; j++)
            for (int k = V; k >= c[j]; k--)
                if (pd[k - c[j]])
                    pd[k] = true;
        for (int j = 1; j <= V; j++)
            if (!pd[j])
                return false;
        return true;
    }
    for (int j = i ? c[i - 1] + 1 : 1; j <= V; j++) {
        c[i] = j;
        if (dfs(x, i + 1))
            return true;
    }
    return false;
}

int solve() {
    scanf("%d%d%d", &C, &D, &V);
    for (int i = 0; i < D; i++)
        scanf("%d", d + i);
    for (int i = 0; i <= V; i++)
        dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < D; i++)
        for (int j = V; j >= d[i]; j--)
            if (dp[j - d[i]])
                dp[j] = true;
    for (int i = 0; i < 5; i++)
        if (dfs(i, 0)) {
            return i;
            }
    return 5;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %d\n", i, solve());
}
