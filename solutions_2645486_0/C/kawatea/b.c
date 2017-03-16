#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int e, r, n, ans = 0, j, k, l;
        int a[10];
        int dp[11][6] = {0};
        
        scanf("%d %d %d", &e, &r, &n);
        
        for (j = 0; j < n; j++) scanf("%d", &a[j]);
        
        for (j = 0; j < n; j++) {
            for (k = 0; k <= e; k++) {
                for (l = 0; l <= k; l++) {
                    dp[j + 1][min(e, k - l + r)] = max(dp[j + 1][min(e, k - l + r)], dp[j][k] + l * a[j]);
                }
            }
        }
        
        for (j = 0; j <= e; j++) ans = max(ans, dp[n][j]);
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
