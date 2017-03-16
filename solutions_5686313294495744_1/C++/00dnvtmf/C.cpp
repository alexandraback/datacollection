//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 1010;
int n;
char topics[NUM][2][22];
int word_num[2];
int id[NUM][2];
map<string, int> mp;
map<string, int> :: iterator it;
const int MAXV = 2010;
struct edge {int next, to;} e[NUM];
int head[MAXV], edge_num;
void gInit()
{
    memset(head, -1, sizeof(head));
    edge_num = 0;
}
void add_edge(int u, int v)
{
    e[edge_num] = (edge) {head[u], v};
    head[u] = edge_num++;
}
int match[MAXV];
bool vis[MAXV];
bool dfs(int u)//通过dfs寻找增广路
{
    vis[u] = true;
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].to, w = match[v];
        if(!vis[v] && (w < 0 || (!vis[w] && dfs(w))))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

//求最大匹配数
int bipartite_matching(int V)//0-based
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < V; v++)
    {
        if(match[v] < 0)
        {
            memset(vis, 0, sizeof(vis));
            if(dfs(v)) ++res;
        }
    }
    return res;
}
int solve()
{
    gInit();
    for(int i = 0; i < n; ++i)
    {
        add_edge(id[i][0], id[i][1] + word_num[0]);
    }
    return n - (word_num[0] + word_num[1] - bipartite_matching(word_num[0] + word_num[1]));
}
int main()
{
#ifdef ACM_TEST
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%s %s", topics[i][0], topics[i][1]);
        }
        for(int j = 0; j < 2; ++j)
        {
            mp.clear();
            word_num[j] = 0;
            for(int i = 0; i < n; ++i)
            {
                it = mp.find(topics[i][j]);
                if(it == mp.end())
                {
                    id[i][j] = word_num[j];
                    mp[topics[i][j]] = word_num[j]++;
                }
                else
                {
                    id[i][j] = it->SE;
                }
            }
        }
        printf("Case #%d: %d\n", cas, solve());
    }
    return 0;
}
