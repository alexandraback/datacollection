#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

int const maxn = 2005;

int cap[maxn][maxn];
int fl[maxn][maxn];

int used[maxn];
int dist[maxn];
int que[maxn];

bool bfs(int s, int f)
{
    memset(dist, -1, sizeof(dist));
    int l = 0;
    que[0] = s;
    dist[s] = 0;
    int r = 1;
    while(l < r)
    {
        int v = que[l++];
        for(int to = 0; to < maxn; ++to)
            if (dist[to] < 0 && cap[v][to] > fl[v][to])
            {
                dist[to] = dist[v] + 1;
                que[r++] = to;
            }
    }
    return dist[f] >= 0;
}

int ptr[maxn];

int dfs(int v, int f, int flow)
{
    if (flow == 0) return 0;
    if (v == f) return flow;
    for(int& to = ptr[v]; to < maxn; ++to)
    {
        if (dist[to] == dist[v] + 1)
        {
            int val = dfs(to, f, min(flow, cap[v][to] - fl[v][to]));
            if (val > 0)
            {
                fl[v][to] += val;
                fl[to][v] -= val;
                return val;
            }
        }
    }
    return 0;
}

int const inf = 1e9+9;

long long get_flow(int s, int f)
{
    long long ans = 0;
    while (bfs(s, f))
    {
        while (int val = dfs(s, f, inf))
        {
            memset(used, 0, sizeof(used));
            ans += val;
        }
        memset(used, 0, sizeof(used));
        memset(ptr, 0, sizeof(ptr));
    }
    return ans;
}


void solve(int numtest)
{
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            cap[i][j] = fl[i][j] = 0;

    int n;
    cin >> n;
    map<string, int> fi;
    map<string, int> si;
    int cntv = 2;

    for(int i = 0; i < n; ++i)
    {
        string a,b;
        cin >> a >> b;

        auto ita = fi.find(a);
        if (ita == fi.end())
        {
            fi[a] = cntv++;
            ita = fi.find(a);
        }
        auto itb = si.find(b);
        if (itb == si.end())
        {
            si[b] = cntv++;
            itb = si.find(b);
        }
        int v = ita->second;
        int u = itb->second;
        cap[0][v] = 1;
        ++cap[v][u];
        cap[u][1] = 1;
    }
    int t = get_flow(0, 1);

    int y = ( (cntv - 2) - 2 * t);
    int ans = n - y - t;
    cout << "Case #" << numtest << ": " << ans <<'\n';
}

int main()
{
//    freopen("in.txt", "r", stdin);
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
        solve(i);
}

