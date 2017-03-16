#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int   maxn = 2000000 + 10;
int         next[maxn], vis[maxn];
int         n, m, t;
int         ans;
int         s[20];

void doit(int x)
{
    int sum = 1;
    while (x / sum)
        sum *= 10;
    sum /= 10;
    s[s[0] = 1] = x;
    while (1)
    {
        int y = (x / 10) + sum * (x % 10);
        if (y == s[1])
            break;
        x = y;
        if (x >= sum && x <= 2000000)
            s[++s[0]] = x;
    }
    sort(s + 1, s + s[0] + 1);
    for (int i = 1; i < s[0]; ++i)
        next[s[i]] = s[i + 1];
    next[s[s[0]]] = -1;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    for (int i = 1; i <= 2000000; ++i)
        if (!next[i])
            doit(i);
    scanf("%d", &t);
    for (int times = 1; times <= t; ++times)
    {
        scanf("%d%d", &n, &m);
        ans = 0;
        for (int i = n; i <= m; ++i)
            if (vis[i] < times)
            {
                int cnt = 0, j = i;
                while (j != -1 && j <= m)
                {
                    ++cnt;
                    vis[j] = times;
                    j = next[j];
                }
                ans += cnt * (cnt - 1) / 2;
            }
        printf("Case #%d: %d\n", times, ans);
    }
    return 0;
}
