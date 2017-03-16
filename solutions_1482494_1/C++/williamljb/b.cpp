#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int   maxn = 1000 + 10;
int         n, m, a[maxn], b[maxn], c[maxn], tt, sum;

bool find()
{
    bool ret = false;
    for (int i = 1; i <= n; ++i)
        if (c[i] < 2)
            ret = true;
    if (!ret)
    {
        printf("%d\n", tt);
        return false;
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (sum >= b[i] && c[i] < 2)
        {
            ++tt;
            sum += (2 - c[i]);
            c[i] = 2;
            flag = true;
        }
    if (flag)
        return true;
    int j = -1;
    for (int i = 1; i <= n; ++i)
        if (sum >= a[i] && c[i] == 0)
            if (j == -1 || b[j] < b[i])
                j = i;
    if (j > -1)
    {
        ++tt;
        sum += 1;
        c[j] = 1;
        return true;
    }
    printf("Too Bad\n");
    return false;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", a + i, b + i);
    tt = sum = 0;
    memset(c, 0, sizeof(c));
    while (find());
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int times;
    scanf("%d", &times);
    for (int i = 1; i <= times; ++i)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
