//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

const int N = 1005;
int f[N], q[N];
bool vis[N];

int calc_cir(int n)
{
    for(int i = 1; i <= n; i++) vis[i] = false;
    int mx = 0;
    for(int i = 1; i <= n; i++) if(!vis[i])
        {
            int now(i), r(0);
            while(!vis[now])
            {
                vis[now] = true;
                q[r++] = now;
                now = f[now];
            }
            int id(-1);
            for(int j = 0; j < r; j++) if(q[j] == now)
                {
                    id = j;
                    break;
                }
            if(id != -1) mx = max(mx, r - id);
        }
    return mx;
}

const int INF = 1000000000;
int head[N], to[N], nxt[N], nedge;
int dis[N];

void init(int n)
{
    for(int i = 0; i <= n; i++) head[i] = -1;
    nedge = 0;
}

void add(int u, int v)
{
    to[nedge] = v, nxt[nedge] = head[u], head[u] = nedge++;
}

int bfs(int st)
{
    int res(1);
    dis[st] = 1;
    queue<int> Q;
    Q.push(st);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        res = max(res, dis[now]);
        for(int i = head[now]; i >= 0; i = nxt[i])
        {
            dis[to[i]] = dis[now] + 1;
            Q.push(to[i]);
        }
    }
    return res;
}

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
#endif // PKWV
//    freopen("C-small-attempt0.in","r",stdin);
//    freopen("C-small.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &f[i]);
        int res = calc_cir(n);
        init(n);
        for(int i = 1; i <= n; i++) if(f[f[i]] != i)
                add(f[i], i);
        for(int i = 1; i <= n; i++) dis[i] = INF;
        int cnt(0);
        for(int i = 1; i <= n; i++) if(f[f[i]] == i)
                cnt += bfs(i);
        res = max(res, cnt);
        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}

