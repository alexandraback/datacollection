#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 105
int cnt[29];
char a[N], b[N];
int p[N];
int n, m, times;

int getRepeat()
{
    int j = -1;
    p[0] = -1;
    for (int i = 1; i < m; ++i)
    {
        while (j >= 0 && b[j + 1] != b[i]) j = p[j];
        if (b[j + 1] == b[i]) ++j;
        p[i] = j;
    }
    return m - 1 - p[m - 1];
}

void solve()
{
    // K L S
    scanf("%d%d%d", &n, &m, &times);
    scanf("%s", a);
    scanf("%s", b);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i)
        ++cnt[a[i] - 'A'];
    if (times < m)
    {
        printf("%.7f\n", 0);
        return;
    }
    double ans = times - m + 1;
    for (int i = 0; i < m; ++i)
        if (cnt[b[i] - 'A'] == 0)
        {
            printf("%.7f\n", 0);
            return;
        }
        else
            ans *= cnt[b[i] - 'A'] * 1.0 / n;
    int ma = (times - m) / getRepeat() + 1;
    printf("%.7f\n", ma - ans);
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