#include <stdio.h>
#include <string.h>

int T;
long long n;

int dp[1001000];
int base[10];

int numlen(long long x)
{
    char str[30];
    int len;
    sprintf(str, "%lld", x);
    len = strlen(str);

    return len;
}

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
    base[0] = 1;
    base[1] = 10;
    base[2] = 100;
    base[3] = 1000;
    base[4] = 10000;
    base[5] = 100000;
    base[6] = 1000000;
    base[7] = 10000000;
    base[8] = 100000000;
    base[9] = 1000000000;
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
    if (x < 1000) {
        return dp[x];
    }
    int len = numlen(x);
    if (numlen(x-2) != len) {
        return 2 + ans(x-2);
    }
    int b = (len+1)/2;
    if (x % base[b] == 0) {
        return 1 + ans(x-1);
    } else {
        long long tmp = x - x%base[b] + 1;
        if (numlen(tmp-2) != numlen(tmp)) {
            return x % base[b] + ans(change(tmp)) - 1;
        } else {
            return x % base[b] + ans(change(tmp));
        }
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

