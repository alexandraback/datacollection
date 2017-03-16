#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 19
char a[N], b[N], ansi[N], ansj[N];
int ansd;
int n;

void dfs(int x, int y)
{
    if (x >= n && y >= n)
    {
        int i = atoi(a);
        int j = atoi(b);
        int d = abs(i - j);
        if (d < ansd)
        {
            ansd = d;
            strcpy(ansi, a);
            strcpy(ansj, b);
        }
        else if (d == ansd && i < atoi(ansi))
        {
            strcpy(ansi, a);
            strcpy(ansj, b);
        }
        else if (d == ansd && i == atoi(ansi) && j < atoi(ansj))
        {
            strcpy(ansj, b);
        }
        return;
    }
    if (x >= n)
    {
        if (b[y] == '?')
        {
            for (int i = 0; i <= 9; ++i)
            {
                b[y] = i + '0';
                dfs(x, y + 1);
            }
            b[y] = '?';
        }
        else
            dfs(x, y + 1);
    }
    else
    {
        if (a[x] == '?')
        {
            for (int i = 0; i <= 9; ++i)
            {
                a[x] = i + '0';
                dfs(x + 1, y);
            }
            a[x] = '?';
        }
        else
            dfs(x + 1, y);
    }
}

void solve()
{
    scanf("%s%s", a, b);
    n = strlen(a);
    ansd = 1 << 30;
    dfs(0, 0);
    printf("%s %s\n", ansi, ansj);
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}