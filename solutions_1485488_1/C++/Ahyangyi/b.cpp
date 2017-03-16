#include <stdio.h>
#include <string.h>
#include <queue>

const int N = 100;

using namespace std;

int n, m, h;
int ceil[N][N], floor[N][N];

int best[N][N];

priority_queue<pair<int,pair<int,int> > > Q;

void add (int t, int x, int y)
{
    if (best[x][y] == -1 || t < best[x][y])
    {
        best[x][y] = t;
        Q.push(make_pair(t,make_pair(x,y)));
    }
}

int move (int c0, int f0, int c1, int f1, int t)
{
    if (c1 - f1 < 50) return -1;
    if (c1 - f0 < 50) return -1;
    if (c0 - f1 < 50) return -1;
    int ans = t;
    int hh = h - t;

    if (c1 - hh < 50)
        ans += 50 - (c1 - hh);

    // We can move freely before the tide starts falling
    if (ans == 0)
       return ans;

    // Do we have enough water?
    if (h - ans - f0 >= 20)
        return ans + 10;
    else
        return ans + 100;
}

int main ()
{
    int t, ct = 0;
    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d%d%d", &h, &n, &m);

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                scanf ("%d", &ceil[i][j]);
            }

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                scanf ("%d", &floor[i][j]);
            }

        Q = priority_queue<pair<int,pair<int,int> > >();
        memset(best,-1,sizeof(best));

        add (0, 0, 0);
        while (!Q.empty ())
        {
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            int t = best[x][y];

            Q.pop();

            if (Q.top().first > t) continue;

            int tt;

            if (x - 1 >= 0)
            {
                tt = move(ceil[x][y], floor[x][y], ceil[x-1][y], floor[x-1][y], t);
                if (tt != -1)
                    add(tt,x-1,y);
            }
            if (y - 1 >= 0)
            {
                tt = move(ceil[x][y], floor[x][y], ceil[x][y-1], floor[x][y-1], t);
                if (tt != -1)
                    add(tt,x,y-1);
            }
            if (x + 1 < n)
            {
                tt = move(ceil[x][y], floor[x][y], ceil[x+1][y], floor[x+1][y], t);
                if (tt != -1)
                    add(tt,x+1,y);
            }
            if (y + 1 < m)
            {
                tt = move(ceil[x][y], floor[x][y], ceil[x][y+1], floor[x][y+1], t);
                if (tt != -1)
                    add(tt,x,y+1);
            }
        }

        printf ("Case #%d: %d.%d\n", ++ ct, best[n - 1][m - 1]/10, best[n - 1][m - 1]%10);
    }

    return 0;
}
