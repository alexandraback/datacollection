#include <stdio.h>
#include <string.h>

int T;
int n;

int dp[1001000];

long long change(long long x)
{
    long long tmp;
    char str[30];
    char rts[30];
    int len;
    sprintf(str, "%lld", x);
    len = strlen(str);
    rts[len] = '\0';
    for (int i=0; i < len ; i++) {
        rts[i] = str[len-i-1];
    }

    sscanf(rts, "%lld", &tmp);
    return tmp;
}

void init()
{
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    for (int i = 1; i < 1001000 ; i++) {
        int next = i+1;
        if (next > 1001000) {
            continue;
        }
        if (dp[next] == -1 || dp[next] > dp[i]+1) {
            dp[next] = dp[i] + 1;
        }
        next = change(i);
        if (next > 1001000) {
            continue;
        }
        if (dp[next] == -1 || dp[next] > dp[i]+1) {
            dp[next] = dp[i] + 1;
        }
    }
}

long long ans(long long x) 
{
    if (x < 1001000) {
        return dp[x];
    }
    return x;
}

int main()
{
    init();
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", z, ans(n));
    }
	return 0;
}

