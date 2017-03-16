#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int t;
int n,m;
bool ans = false;

int g[1001][11];
bool vis[1001];

void f(int cur)
{
    if(ans)
    {
        return;
    }
    if(vis[cur])
    {
        ans = true;
        return;
    }
    vis[cur] = true;
    for(int i = 1; i <= g[cur][0];i++)
    {
        f(g[cur][i]);
    }
    return;
}

int main()
{
    cin >> t;

    for(int q = 1; q <= t; q++)
    {
        memset(g, 0, sizeof(int) * 1001 * 11);
        ans = false;

        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            g[i][0] = m;
            for(int j = 1; j <= m; j++)
            {
                int t;
                cin >> t;
                g[i][j] = t;
            }
        }

        for(int i = n; i > 0; i--)
        {
            memset(vis, false, sizeof(bool) * 1001);
            f(i);
            if(ans)
                break;
        }

        if(ans)
            cout << "Case #" << q << ": Yes" << endl;
        else
            cout << "Case #" << q << ": No" << endl;
    }

    return 0;
}
