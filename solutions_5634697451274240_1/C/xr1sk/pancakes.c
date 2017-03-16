#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    if (a <= b) return a;
    else        return b;
}

int main() {
    int T, t;
    scanf("%d", &T);
    t = T;
    while (t--) {
        char s[105];
        scanf("%s", s);
        int len = strlen(s);
        int dp[105][2] = {};
        if (s[0] == '-')
            dp[0][1] = 1;
        else
            dp[0][0] = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == '-') {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);
                dp[i][1] = dp[i-1][0] + 1;
            } else {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
            }
        }

        printf("Case #%d: %d\n", T - t, dp[len - 1][1]);
            
    }
}
        
