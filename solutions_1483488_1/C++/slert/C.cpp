#include <cstdio>
#include <algorithm>
using namespace std;

int next[10000010];
int cnt[10000010];
int mark[10000010];

int nlen(int x)
{
    int ret = 0;
    while(x>0)
    {
        x/=10;
        ret++;
    }
    return ret;
}
int nmul(int n)
{
    int ret = 1;
    for(int i = 1; i < n; i++)
        ret *= 10;
    return ret;
}

int cycle(int x, int mul)
{
    return x%10*mul+x/10;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    for(int i = 1; i <= 2000000; i++)next[i] = 0;
    for(int i = 1; i <= 2000000; i++)
    {
        if(next[i] != 0)continue;
        int a[10], n=0;
        int len = nlen(i);
        int mul = nmul(len);
        a[n++] = i;
        for(int j = cycle(i,mul); j != i; j = cycle(j,mul))
            if(nlen(j) == len)
                a[n++] = j;

        sort(a,a+n);
        next[a[n-1]] = -1;
        cnt[a[n-1]] = 0;
        for(int j = n-1; j > 0; j--)
        {
            next[a[j-1]] = a[j];
            cnt[a[j-1]] = cnt[a[j]]+1;
        }
    }
    int tc;
    scanf("%d", &tc);
    for(int ti = 1; ti <= tc; ti++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i = a; i <= b; i++)
            mark[i] = 0;
        int ans = 0;
        for(int i = a; i <= b; i++)
        {
            if(!mark[i])
            {
                int fcnt = cnt[i];
                int lcnt = fcnt;
                for(int j = i; j <= b && j > -1; j = next[j])
                {
                    mark[j] = 1;
                    lcnt = cnt[j];
                }
                int n = fcnt-lcnt;
                ans += n*(n+1)/2;
            }
        }
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}
