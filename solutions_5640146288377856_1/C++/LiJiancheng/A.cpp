#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 15
int f[N][N] = {
    {0},
    {0, 1, 0},
    {0, 2, 2, 0},
    {0, 3, 3, 3, 0},
    {0, 4, 3, 4, 4, 0},
    {0, 5, 4, 4, 5, 5, 0},
    {0, 6, 4, 4, 5, 6, 6, 0},
    {0, 7, 5, 5, 5, 6, 7, 7, 0},
    {0, 8, 5, 5, 5, 6, 7, 8, 8, 0},
    {0, 9, 6, 5, 6, 6, 7, 8, 9, 9, 0},
    {0, 10, 6, 6, 6, 6, 7, 8, 9, 10, 10, 0},
};
int n, m, w;

void solve()
{
    scanf("%d%d%d", &n, &m, &w);
    ll ans = (m - 1) / w + w;
    printf("%lld\n", ans * n);
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