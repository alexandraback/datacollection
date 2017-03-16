#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 105
#define M 105
int a[N];
bool f[M];
int n, m, v;

int check()
{
    for (int i = 1; i <= v; ++i)
        if (!f[i])
            return i;
    return v + 1;
}

void solve()
{
    // C D V
    scanf("%d%d%d", &m, &n, &v);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = v; j >= a[i]; --j)
            f[j] |= f[j - a[i]];
    int ans = 0;
    int ma = check();
    while (ma <= v)
    {
        ++ans;
        for (int j = v; j >= ma; --j)
            f[j] |= f[j - ma];
        ma = check();
    }
    printf("%d\n", ans);
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