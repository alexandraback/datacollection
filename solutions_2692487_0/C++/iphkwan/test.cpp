#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int a[110];
int t, n, st;
int cal(int cnt, int sp)
{
    if (cnt == n + 1)
        return 0;
    int ans = n - cnt + 1;
    int tmp = 0;
    while(sp <= a[cnt])
    {
        sp = sp * 2 - 1;
        tmp++;
    }
    int res = tmp + cal(cnt + 1, sp + a[cnt]);
    return min(res, ans);
}
int main() {
    freopen("t4.in", "r", stdin);
    freopen("ans4.txt", "w", stdout);
    scanf("%d", &t);
    for (int z = 1; z <= t; z++)
    {
        scanf("%d%d", &st, &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort (a + 1, a + 1 + n);
        int i, ans;
        for (i = 1; i <= n; i++)
        {
            if (st > a[i])
            {
                st += a[i];
                continue;
            }
            break;
        }
        if (st > 1)
            ans = cal(i, st);
        else
            ans = n - i + 1;
        printf("Case #%d: %d\n", z, ans);
    }
    return 0;
}


