/*
    Title:
    Author: RudySnow
    Algorithm:
    Date:
    License: GNU GPL
    Quote: Night Gathers, and My Watch Begins, it shall Never End until My Death
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct edge
{
    int to, nxt;
} e[50005];

int head[1005], vis[1005], deg[1005], t, n, idx;

void addedge(int from, int to)
{
    e[idx].to = to;
    e[idx].nxt = head[from];
    head[from] = idx++;
}

int bfs(int x)
{
    int i;
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    vis[x] = 1;
    Q.push(x);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        for(i = head[tmp]; i != -1; i = e[i].nxt)
        {
            if(vis[e[i].to]) return 0;
            else
            {
                Q.push(e[i].to);
                vis[e[i].to] = 1;
            }
        }
    }
    return 1;
}


int main()
{
    int m;
    int i, j, k;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &t);
    for(k = 1; k <= t; ++k)
    {
        scanf("%d", &n);
        idx = 0;
        memset(vis, 0, sizeof(vis));
        memset(e, 0, sizeof(e));
        memset(head, -1, sizeof(head));
        memset(deg, 0, sizeof(deg));
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &m);
            int tmp;
            for(j = 0; j < m; ++j)
            {
                scanf("%d", &tmp);
                addedge(i+1, tmp);
                deg[tmp]++;
            }
        }
        int flag, flag1 = 0;
        for(i = 1; i <= n; ++i)
        {
            if(!deg[i])
            {
                flag = bfs(i);
                if(!flag)
                {
                    printf("Case #%d: Yes\n", k);
                    flag1 = 1;
                    break;
                }
            }
        }
        if(!flag1) printf("Case #%d: No\n", k);
    }
    return 0;
}
