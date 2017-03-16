#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

using namespace std;
int n, m, k, t, cs, bmx, md, v[15];
char tst[15], cv[15];
double sol, pt;

double putere(int x, int y)
{
    double r = 1;
    for(int i = 1; i <= y; i++)
        r *= x;
    return r;
}

void bck(int pas, int a[15])
{
    if(pas == k + 1)
    {
        int i, j, ap = 0;
        char s[15];
        for(i = 1; i < pas; i++)
            s[i] = tst[ a[i] ];
        for(i = 1; i <= k - m + 1; i++)
        {
            int o = 1;
            for(j = 0; j < m; j++)
                if(s[i + j] != cv[j + 1])
                {
                    o = 0;
                    break;
                }
            if(o)
                ap++;
        }
        if(ap > bmx)
            bmx = ap;
        md += ap;
        return;
    }

    int i, v[15] = {0};
    for(i = 1; i < pas; i++)
        v[i] = a[i];

    for(i = 1; i <= n; i++)
    {
        v[pas] = i;
        bck(pas + 1, v);
    }
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        cs++;
        printf("Case #%d: ", cs);

        md = 0;
        bmx = 0;
        scanf("%d%d%d\n", &n, &m, &k);
        gets(tst + 1);
        gets(cv + 1);
        bck(1, v);

        sol = md;
        pt = putere(n, k);
        sol = sol / pt;
        sol = (double)bmx - sol;
        printf("%.7f\n", sol);
    }
    return 0;
}
