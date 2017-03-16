#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#define LL long long
#define MAXN 20
using namespace std;
int vis[1000005];
struct Node
{
    int u, step;
};
int main()
{
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("outA.out", "w", stdout);
    int n;
    int t;
    scanf("%d", &t);
    for(int ii = 1; ii <= t; ii++)
    {
        int ans;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        queue <Node> Q;
        while(!Q.empty()) Q.pop();
        Node now, next;
        now.u = 1;
        now.step = 1;
        vis[1] = 1;
        Q.push(now);
        while(!Q.empty())
        {
            now = Q.front();
            Q.pop();
            if(now.u == n)
            {
                ans = now.step;
                break;
            }
            for(int i = 0; i < 2; i++)
            {
                if(i == 0)
                {
                    next.u = now.u + 1;
                    next.step = now.step + 1;
                    if(!vis[next.u] && next.u <= n)
                    {
                        Q.push(next);
                        vis[next.u] = 1;
                    }
                }
                else
                {
                    int temp = now.u;
                    int nn[20];
                    int nnm = 0;
                    while(temp)
                    {
                        nn[nnm++] = temp % 10;
                        temp /= 10;
                    }
                    if(nn[nnm - 1] == 0) continue;
                    next.u = 0;
                    for(int j = 0; j < nnm; j++)
                    {
                        next.u *= 10;
                        next.u += nn[j];
                    }
                    next.step = now.step + 1;
                    if(!vis[next.u] && next.u <= n)
                    {
                        Q.push(next);
                        vis[next.u] = 1;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ii , ans);
    }
    return 0;
}
