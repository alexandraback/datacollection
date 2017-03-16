#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 1000005
int v[N];
int n;

int rev(int x)
{
    int a[8], m = 0;
    while (x)
    {
        a[m++] = x % 10;
        x /= 10;
    }
    int y = 0;
    for (int i = 0; i < m; ++i)
    {
        y = y * 10 + a[i];
    }
    return y;
}

void solve()
{
    scanf("%d", &n);
    if (1 == n)
    {
        printf("%d\n", 1);
        return;
    }
    queue<int> q;
    q.push(1);
    memset(v, 0, sizeof(v));
    v[1] = 1;
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        int t = h + 1;
        if (t == n)
        {
            printf("%d\n", v[h] + 1);
            return;
        }
        if (!v[t])
        {
            q.push(t);
            v[t] = v[h] + 1;
        }
        t = rev(h);
        if (t == n)
        {
            printf("%d\n", v[h] + 1);
            return;
        }
        if (!v[t])
        {
            q.push(t);
            v[t] = v[h] + 1;
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}