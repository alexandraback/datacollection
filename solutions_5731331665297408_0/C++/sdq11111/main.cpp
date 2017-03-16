#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 800 + 9, Maxm = (640000 << 1)+1, inf = 0x7fffffff;
int data[Maxn];
class Map
{
public:
    int head[Maxn], id;
    int to[Maxm], cap[Maxm], next[Maxm];
    void clear()
    {
        memset(head, -1, sizeof(head)), id = 0;
    }
    void _add(int a, int b, int c)
    {
        to[id] = b;
        cap[id] = c;
        next[id] = head[a];
        head[a] = id ++;
    }
    void add(int a, int b, int c)
    {
        _add(a, b, c);
        _add(b, a, 0);
    }
    void out(int s)
    {
        cout << "s= " << s;
        for(int i = head[s]; ~i; i = next[i])
        {
            cout <<" " <<  to[i]  ;
        }
        cout << endl;
    }
} map;
class Dinic
{
public:
    int level[Maxn], _head[Maxn];
    bool makeLevel(int s, int t, Map &map)
    {
        queue<int> q;
        memset(level, 0, sizeof(level));
        q.push(s);
        level[s] = 1;
        while(!q.empty())
        {
            int now = q.front();
            if(now == t) return 1;
            q.pop();
            for(int i = map.head[now]; ~i; i = map.next[i])
            {
                int to = map.to[i];
                if(!level[to] && map.cap[i])
                {
                    level[to] = level[now] + 1;
                    q.push(to);
                }
            }
        }
        return 0;
    }
    int dfs(int now, int limit, const int &t, Map &map)
    {
        if(now == t) return limit;
        int ret = 0, flow;
        for(int i = map.head[now]; ~i; i = map.next[i])
        {
            int to = map.to[i];
            map.head[now] = i;
            if(level[to] == level[now] + 1)
            {
                flow = dfs(to, min(map.cap[i], limit - ret), t, map);
                map.cap[i] -= flow;
                map.cap[i ^ 1] += flow;
                if((ret += flow) == limit) return ret;
            }
        }
        return ret;
    }
    int maxFlow(int s, int t, Map &map)
    {
        int ans = 0;
        memcpy(_head, map.head, sizeof(_head));
        while(makeLevel(s, t, map))
        {
            ans += dfs(s, inf, t, map);
            memcpy(map.head, _head, sizeof(_head));
        }
        return ans;
    }
} dinic;

int main()
{
    freopen("in.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    for (int t = 1; t <= cas; ++t)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        map.clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&data[i]);
        }
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            scanf("%d %d",&x, &y);
            map.add(x,y,2);
        }
        printf("Case #%d: %d\n",t,dinic.maxFlow(1,n,map));
    }
    return 0;
}

