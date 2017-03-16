#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int mas[20000000];

int cur[50];
int cnt = 0, t;

bool palin(long long x)
{
    cnt = 0;
    while (x)
    {
        cur[cnt++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < cnt; i++)
    {
        if (cur[i] != cur[cnt - 1 - i]) return 0;
    }
    return 1;
}

bool check(long long x)
{
    return (palin(x) && palin(x * x));
}

int sqrtl(long long x)
{
    long long l = 0;
    long long r = 1000000000LL;
    while (r - l > 1)
    {
        long long m = (l + r) / 2;
        if (m * m >= x) r = m; else l = m;
    }
    return r;
}

int sqrtr(long long x)
{
    long long l = 0;
    long long r = 1000000000LL;
    while (r - l > 1)
    {
        long long m = (l + r) / 2;
        if (m * m <= x) l = m; else r = m;
    }
    return l;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);

    for (int i = 1; i <= 10000000; i++)
    {
        mas[i] = mas[i - 1] + check(i);
    }
    for (int tc = 1; tc <= t; tc++)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        int r = sqrtr(m);
        int l = sqrtl(n);

        int ans = mas[r] - mas[l - 1];
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
