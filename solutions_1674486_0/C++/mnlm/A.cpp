/*
ID   : mnlm1991
PROG : 
LANG : C++
*/

#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<iterator>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1000 + 5;
const int M = N * 10;
struct LIST
{
    int next, num;
}E[M];
int head[N];
int NC;
void Insert(int x, int y)
{
    E[NC].next = head[x];
    E[NC].num = y;
    head[x] = NC++;
}
bool vis[N][N];
int in[N];
bool solve(int n)
{
    queue <int> que;
    for (int i = 0; i < n; i++)
    {
        if (!in[i])
        {
            que.push(i);
        
        }
    }
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u][u] = true;
        for (int i = head[u]; i != -1; i = E[i].next)
        {
            int v = E[i].num;
            for (int j = 0; j < n; j++)
            {
                if (vis[u][j])
                {
                    if (vis[v][j])
                    {
                        return true;
                    }
                    vis[v][j] = true;
                }
            }
            if (--in[v] == 0)
            {
                que.push(v);
            }
        }
    }
    return false;
}
int main()
{
    int T;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out.txt", "w", stdout);
    while (scanf("%d", &T) != EOF)
    {
        int tc = 1;
        while (T--)
        {
            memset(head, -1, sizeof(head));
            memset(vis, 0, sizeof(vis));
            memset(in, 0, sizeof(in));
            NC = 0;
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int m;
                scanf("%d", &m);
                while (m--)
                {
                    int y;
                    scanf("%d", &y);
                    Insert(i, --y);
                    in[y]++;
                }
            }
            printf("Case #%d: %s\n", tc++, solve(n) ? "Yes" : "No");
        }
    }
    return 0;
}
