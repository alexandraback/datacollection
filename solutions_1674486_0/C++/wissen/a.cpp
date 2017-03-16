#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int t;
int n,m;
bool ans = false;

bool g[1001][1001];
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
    for(int i = 1; i <= n;i++)
    {
        if(g[cur][i])
            f(i);
    }
}

int main()
{
    cin >> t;

    for(int q = 1; q <= t; q++)
    {
        memset(g, false, sizeof(bool) * 1001 * 1001);
        memset(vis, false, sizeof(bool) * 1001);
        ans = false;

        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for(int j = 1; j <= m; j++)
            {
                int t;
                cin >> t;
                g[i][t] = true;
            }
        }

        for(int i = 1; i <= n; i++)
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
