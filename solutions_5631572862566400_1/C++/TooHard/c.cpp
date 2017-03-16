#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define x first
#define y second
#define INF (0x3f3f3f3f)

typedef long long LL;
typedef pair<int, int> P2;
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}


const int MAXN = 1005;
int g_leader[MAXN];

class StronglyConnectedComponent {
    typedef vector<int> VI; typedef vector<VI> VVI;
public:
    struct edge{
        int e, nxt;
        edge() {}
        edge(int _e, int _nxt) : e(_e), nxt(_nxt) {}
    };
    int V, E;
    vector<edge> e, er;
    vector<int> sp, spr, group_num, stk;
    int group_cnt; vector<set<int>> graph; // reduced graph
    vector<bool> visited;
    // Vertices are 1-based indexed.
    StronglyConnectedComponent() {}
    StronglyConnectedComponent(int _V) {
        V = _V; E = 0; group_cnt = 0; group_num = vector<int>(V + 5);
        sp = vector<int>(V + 5); spr = vector<int>(V + 5); stk = vector<int>(V + 5);
        visited = vector<bool>(V + 5); e.push_back(edge()); er.push_back(edge());
    }
    void fill_forward(int x){
        visited[x] = true;
        for(int i = sp[x]; i; i = e[i].nxt) if (!visited[e[i].e]) fill_forward(e[i].e);
        stk[++stk[0]] = x;
    }
    void fill_backward(int x){
        visited[x] = false;
        group_num[x] = group_cnt;
        g_leader[group_cnt] = x;
        for(int i = spr[x]; i; i = er[i].nxt) if (visited[er[i].e]) fill_backward(er[i].e);
    }
    void add_edge(int v1, int v2){ // Add edge v1->v2
        E++;
        e.push_back(edge(v2, sp[v1])); sp[v1] = E;
        er.push_back(edge(v1, spr[v2])); spr[v2] = E;
    }
    void cal_scc() {
        stk[0] = 0;
        fill(visited.begin(), visited.end(), false);
        for(int i = 1; i <= V; i++) if (!visited[i]) fill_forward(i);
        group_cnt = 0;
        for(int i = stk[0]; i >= 1; i--) if (visited[stk[i]]) { group_cnt++; fill_backward(stk[i]); }
    }
    void cal_reduced_graph() { // need to call cal_scc() before
        graph = vector<set<int>>(group_cnt + 1);
        for (int i = 1; i <= V; i++) { int u = group_num[i];
            for (int j = sp[i]; j; j = e[j].nxt) {
                int v = group_num[e[j].e];
                // If we don't need to remove duplicates, use Vector instead of Set.
                if (u != v) graph[u].insert(v);
            }
        }
    }
};


int cycle_len[MAXN];
bool visited[MAXN];
vector<int> order;
StronglyConnectedComponent scc;

vector<int> adj[MAXN];
void dfs(int at) {
    visited[at] = true;
    for (int v : scc.graph[at]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    order.PB(at);
}
void dfs2(int at) {
    visited[at] = true;
    for (int v : adj[at]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
    order.PB(at);
}

int dp[MAXN];
int fff[MAXN];

void solve() {
    int N;
    cin >> N;
    int bbf;
    scc = StronglyConnectedComponent(N);
    REP(i, N) {
        cin >> bbf;
        scc.add_edge(i + 1, bbf);
        fff[i + 1] = bbf;
    }
    MEMSET(cycle_len, 0);
    MEMSET(visited, 0);
    scc.cal_scc();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cycle_len[scc.group_num[i]]++;
    }
    scc.cal_reduced_graph();
    for (int i = 1; i <= scc.group_cnt; i++) {
        maxa(ans, cycle_len[i]);
    }
//    cout << ans << endl;
    order.clear();
    for (int i = 1; i <= scc.group_cnt; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    REP(i, MAXN) adj[i].clear();
    MEMSET(dp, 0);
    for (int u : order) {
        if (cycle_len[u] >= 3) {
            dp[u] = 0;
        } else if (cycle_len[u] == 2) {
            dp[u] = 2;
        } else {
            dp[u] = 1;
            for (int v : scc.graph[u]) {
                if (maxa(dp[u], 1 + dp[v])) {
                }
            }
            if (dp[u] == 1) dp[u] = 0;
        }
        maxa(ans, dp[u]);
    }
//    cout << ans << endl;
    for (int i = 1; i <= scc.group_cnt; i++) {
        for (int v : scc.graph[i]) {
            adj[v].PB(i);
        }
    }
    order.clear();
    MEMSET(visited, false);
    for (int i = 1; i <= scc.group_cnt; i++) {
        if (!visited[i]) {
            dfs2(i);
        }
    }
    MEMSET(dp, 0);
    int sum = 0;
    for (int u : order) {
        if (cycle_len[u] >= 3) {
            //cout << "#" << endl;
            dp[u] = 0;
            //sum += 3;
        } else if (cycle_len[u] == 2) {
            dp[u] = 2;
            for (int i = 0; i < SZ(adj[u]); i++) {
                for (int j = i + 1; j < SZ(adj[u]); j++) {
                    if (fff[g_leader[adj[u][i]]] != fff[g_leader[adj[u][j]]])
                        maxa(dp[u], 2 + dp[adj[u][i]] + dp[adj[u][j]]);
                    else
                        maxa(dp[u], 2 + max(dp[adj[u][i]], dp[adj[u][j]]));
                }
            }
            for (int i = 0; i < SZ(adj[u]); i++) {
                maxa(dp[u], 2 + dp[adj[u][i]]);
            }
            sum += dp[u];
//            cout << dp[u] << endl;
            maxa(ans, dp[u]);
        } else {
            dp[u] = 1;
            for (int v : adj[u]) {
                maxa(dp[u], 1 + dp[v]);
            }
        }
       // cout << u << " " << dp[u] << endl;
//        maxa(ans, dp[u]);
    }
//    cout << sum << endl;
    maxa(ans, sum);
    cout << ans << endl;
}

int main() {
    int test;
    cin >> test;
    REP(tt, test) {
        printf("Case #%d: ", tt + 1);
        solve();
    }

    return 0;
}
