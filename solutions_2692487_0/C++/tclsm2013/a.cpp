#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 1007;

int n, A, run;
int a[maxn];

void solve()
{
    scanf("%d%d", &A, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int res = n, tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (A-1 == 0 && A <= a[i]) break;
        while (A <= a[i]) A += A-1, tmp++;
        A += a[i];
        res = min(res, tmp+n-i);
    }
    printf("Case #%d: %d\n", run, res);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) solve();
    return 0;
}
