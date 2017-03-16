#include <cstdio>

int a, b, k;

long long int dfs(int na=0, int nb=0, int n=30)
{
    int now = 1<<n;
    if((na&nb)+now+(now-1) < k)
        if(na+now+(now-1) < a && nb+now+(now-1) < b)
        return (long long)1<<((n+1)*2);
    long long ans = 0;
    if((na+now) < a && (nb+now) < b)
        if(((na+now)&(nb+now)) < k)
            ans += dfs(na+now, nb+now, n-1);
    if(na < a && (nb+now) < b)
        if((na&(nb+now)) < k)
            ans += dfs(na, nb+now, n-1);
    if((na+now) < a && nb < b)
        if(((na+now)&nb) < k)
            ans += dfs(na+now, nb, n-1);
    if(na < a && nb < b)
        if((na&nb) < k)
            ans += dfs(na, nb, n-1);
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d %d %d", &a, &b, &k);
        printf("Case #%d: %lld\n", cas, dfs());
    }
    return 0;
}

