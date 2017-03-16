#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1050, MAXM = 10050;
int n, m, tc, v[MAXN], f[MAXN], mct, k, flag;
struct edge
{
    int y, next;
} e[MAXM]; 

void e_add(int x, int y)
{
    mct++;
    e[mct].next = v[x];
    e[mct].y = y;
    v[x] = mct;
}

void dfs(int x)
{
    if (flag) return;
    f[x] = 1;
    for (int i = v[x]; i; i = e[i].next)
    {
        if (f[e[i].y] == 1) flag = 1;
        dfs(e[i].y);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    for (int tci = 1; tci <= tc; tci++)
    {
        cin >> n;
        flag = mct = 0;
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            while (m--)
            {
                cin >> k;
                e_add(i, k);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            memset(f, 0, sizeof(f));
            dfs(i);
        }
        cout << "Case #" << tci << ": ";
        if (flag) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}
