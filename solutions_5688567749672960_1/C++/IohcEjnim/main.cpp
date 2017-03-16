#include <stdio.h>

int t, tc;
long long n, cnt[15];
long long ans;

long long pow(int x)
{
    int r = 1;
    while (x--) r *= 10;
    return r;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int i, a;
    long long tmp;
    for (i = 1; i < 14; i++)
    {
        cnt[i] = cnt[i-1];
        cnt[i] += pow(i/2)-1;
        cnt[i]++;
        cnt[i] += pow((i+1)/2)-1;
    }
    cnt[0] = 1;
    scanf("%d", &tc);
    for (t = 1; t <= tc; t++)
    {
        scanf("%lld", &n);
        if (n < 10)
        {
            printf("Case #%d: %lld\n", t, n);
            continue;
        }
        for (tmp = n/10, a = 0; tmp; tmp /= 10) a++;
        ans = cnt[a];
        if (n%pow(a/2+1) == 0 && n != pow(a))
        {
            n--;
            ans++;
        }
        for (i = 0; i <= a/2; i++)
        {
            ans += (n%10)*pow(i);
            n /= 10;
        }
        tmp = ans;
        for (i = 0; i <= (a-1)/2; i++)
        {
            ans += (n%10)*pow((a-1)/2-i);
            n /= 10;
        }
        if (ans-tmp == 1) ans = tmp;
        printf("Case #%d: %lld\n", t, ans);
    }
}