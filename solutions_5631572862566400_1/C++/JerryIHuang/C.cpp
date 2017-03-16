#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int v, next;
};

int BFF[2000], vis[2000], blk[2000], clk, ans1, ans2, blknum, n;

int edgenum, first[2000];
Edge e[2000];

void addedge(int u, int v)
{
    edgenum++;
    e[edgenum].v = v;
    e[edgenum].next = first[u];
    first[u] = edgenum;
}

void work(int u)
{
    vis[u] = clk;
    blk[u] = blknum;
    clk++;
    if (vis[BFF[u]] == 0)
        work(BFF[u]);
    else
        if (blk[BFF[u]] == blk[u])
        {
            if (vis[u] - vis[BFF[u]] + 1 > ans1)
                ans1 = vis[u] - vis[BFF[u]] + 1;
        }
        else
            return;
}

int fun(int u)
{
    int len = 0, t = first[u];
    while (t != 0)
    {
        int v = e[t].v;
        if (v != BFF[u])
        {
            int tmp = fun(v);
            if (tmp + 1 > len)
                len = tmp + 1;
        }
        t = e[t].next;
    }
    return len;
}

int main()
{
    int T;

    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    cin >> T;
    for (int K = 1; K <= T; K++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            first[i] = 0;
        edgenum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> BFF[i];
            addedge(BFF[i], i);
            vis[i] = 0;
        }

        ans1 = 0;
        blknum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                clk = 1;
                blknum++;
                work(i);
            }
        }

        ans2 = 0;
        for (int i = 1; i <= n; i++)
            if (BFF[i] > i && (BFF[BFF[i]] == i))
                ans2 += 2 + fun(i) + fun(BFF[i]);
        cout << "Case #" << K << ": " << max(ans1, ans2) << endl;
    }
    return 0;
}
