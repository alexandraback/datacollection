#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
 
const int N = 10010;
const int M = 200010;
const int oo = 1000000000;
struct edge
{
    int v,next,flow;
}e[M];
 
int head[N],last[N],d[N],que[N],cnt,ans,s,t;
 
void addedge(int u,int v,int f)
{
    e[cnt].v = v;
    e[cnt].flow = f;
    e[cnt].next = head[u];
    head[u] = cnt ++;
}
 
void addEdge(int u,int v,int f)
{
    addedge(u,v,f);
    addedge(v,u,0);
}
 
int bfs()
{
    memset(d,-1,sizeof(d));
    d[s] = 0;
    int top = 0,tail = 1;
    que[0] = s;
    while(top < tail) {
        int u = que[top ++];
        for(int i = head[u]; i != -1; i = e[i].next) {
            if(e[i].flow > 0 && d[e[i].v] == -1) {
                d[e[i].v] = d[u] + 1;
                que[tail ++] = e[i].v;
                if(e[i].v == t) break;
            }
        }
    }
    return d[t] != -1;
}
 
void dfs()
{
    for(int i = s; i <= t; i ++) last[i] = head[i];
    int top = 1,tmp,x;
    que[1] = s;
    while(top) {
        x = que[top];
        if(x == t) {
            int minf = oo;
            for(int i = 1; i < top; i ++)
                if(e[last[que[i]]].flow < minf) {
                    minf = e[last[que[i]]].flow;
                    tmp = i;
                }
            for(int i = 1; i < top; i ++) {
                int m = last[que[i]];
                e[m].flow -= minf;
                e[m ^ 1].flow += minf;
            }
            ans += minf;
            top = tmp;
            continue;
        }
        int i;
        for(i = last[x]; i != -1; i = e[i].next)
            if(e[i].flow > 0 && d[e[i].v] == d[x] + 1) {
                que[++ top] = e[i].v;
                break;
            }
        last[x] = i;
        if(last[x] == -1) {
            top --;
            last[que[top]] = e[last[que[top]]].next;
        }
    }
}

void solve(int cas) {
    map<string, int> ma1, ma2;
    char ss[1010][25], str[1010][25];
    int f1[1010], f2[1010];
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2)); 
    int n;
    scanf("%d", &n);
    int x = 0, y = 0; 
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", ss[i], str[i]);
        if (!ma1.count(ss[i])) ma1[ss[i]] = ++ x;
        if (!ma2.count(str[i])) ma2[str[i]] = ++ y;
        int xx = ma1[ss[i]], yy = ma2[str[i]];
        f1[xx]++, f2[yy]++;
    }
    s = 0, t = x * 2  + y * 2 + 1;
    cnt = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= x; i++) addEdge(s, i, oo), addEdge(i, i + x, f1[i] - 1);
    for (int i = 1; i <= y; i++) addEdge(2 * x +y + i, t, oo), addEdge(2 * x + i, 2 * x + y + i, f2[i] - 1);
    for (int i = 1; i <= n; i++) {
        int xx = ma1[ss[i]], yy = ma2[str[i]];
        addEdge(xx + x, 2 * x + yy, 1);
    }
    ans = 0;
    while(bfs()) dfs();
    printf("Case #%d: %d\n", cas, ans);
}
int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int cas = 1; cas <= n; cas++) {
        solve(cas);
    }
    return 0;
}
