#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int use[2000], usee[2000], b[2000][2000], a[2000];
int ch;

void dfs(int v)
{
    usee[v] = 1;
    for (int i = 1; i <= a[v]; i++)
        if (usee[b[v][i]] == 1) ch = 1; else dfs(b[v][i]);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        ch = 0;
        memset(use, 0, sizeof(use));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 1; j <= a[i]; j++)
            {
                cin >> b[i][j];
                use[b[i][j]] = 1;
            }
        }
        int ug = 0;
        for (int i = 1; i <= n; i++)
            if (use[i] == 0)
            {
                ug = i;
            }
        if (ug != 0)
        {
            for (int i = 1; i <= n; i++)
            {
                dfs(i);
                memset(usee, 0, sizeof(usee));
            }
        }
            else ch = 1;
        if (ch == 0) printf("Case #%d: No\n", tt); else printf("Case #%d: Yes\n", tt);
    }
    return 0;
}
