#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 50 + 10;

int N, M;
int zip[MAXN];
int ans[MAXN], path[MAXN];
bool visit[MAXN];
int father[MAXN];

void outputZip(int z)
{
    if (z < 10000) putchar('0');
    if (z < 1000) putchar('0');
    if (z < 100) putchar('0');
    if (z < 10) putchar ('0');
    printf("%d", z);
}

struct Edge
{
    int v, next;
} edge[MAXN * MAXN * 2];
int edgeNum, head[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

void dfs(int index, int u)
{
    //printf("in %d %d\n", index, u);
    if (index == N)
    {
        for (int i = 0; i < N; ++i)
        {
            if (path[i] > ans[i])
            {
                return;
            }
            else if (path[i] < ans[i])
            {
                break;
            }
        }
        for (int i = 0; i < N; ++i)
        {
            ans[i] = path[i];
        }
        return;
    }
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!visit[v])
        {
                visit[v] = true;
                path[index] = zip[v];
                father[v] = u;
                dfs(index + 1, v);
                visit[v] = false;
        }
    }
    if (father[u] != -1)
    {
        dfs(index, father[u]);
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    int u, v;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; ++i)
        {
            scanf("%d", &zip[i]);
        }
        clearEdge();
        for (int i = 0; i < M; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        memset(ans, 0x3f, sizeof(ans));
        for (int i = 1; i <= N; ++i)
        {
            path[0] = zip[i];
            if (path[0] > ans[0])
            {
                continue;
            }
            //printf("ss\n");
            memset(visit, false, sizeof(visit));
            visit[i] = true;
            father[i] = -1;
            dfs(1, i);
        }
        printf("Case #%d: ", cas);
        for (int i = 0; i < N; ++i)
        {
            //printf("%d ", ans[i]);
            outputZip(ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
