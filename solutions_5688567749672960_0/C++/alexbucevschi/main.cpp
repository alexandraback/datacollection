#include <bits/stdc++.h>
#define oo 100000000
using namespace std;
int run(int x)
{
    int ret = 0;
    while(x)
    {
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int t, T, n, sol[1000005], i, rev;
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    sol[1] = 1;
    for(i = 2; i <= 1000000; i++)
        sol[i] = oo;
    for(i = 1; i <= 1000000; i++)
    {
        rev = run(i);
        sol[rev] = min(sol[i] + 1, sol[rev]);
        sol[i + 1] = min(sol[i] + 1, sol[i + 1]);
    }
    scanf("%d", &t);
    for(T = 1; T <= t; T++)
    {
        scanf("%d", &n);
        printf("Case #%d: %d\n", T, sol[n]);
    }
    return 0;
}
