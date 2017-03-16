#include <bits/stdc++.h>

using namespace std;

map <string, int> memo;
int idx = 0;
inline int getId(const string& s) {
    if (memo.count(s))
        return memo[s];
    memo[s] = idx++;
}

const int inf = 0x3f3f3f3f;

struct edge {
    int x, y, cap, flow;
};

struct DinicFlow {
    vector <edge> e;
    vector <int> cur, d;
    vector < vector <int> > adj;
    int n, source, sink;

    DinicFlow() {}

    DinicFlow(int v) {
        n = v;
        cur = vector <int> (n + 1);
        d = vector <int> (n + 1);
        adj = vector < vector <int> > (n + 1);
    }

    void addEdge(int from, int to, int cap) {
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }

    int bfs() {
        queue <int> q;
        for(int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while(!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for(int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if(d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }

    int dfs(int x, int flow) {
        if(!flow) return 0;
        if(x == sink) return flow;
        for(;cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if(d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow(int src, int snk) {
        this->source = src; this->sink = snk;
        int flow = 0;
        while(bfs()) {
            for(int i = 0; i <= n; ++i) cur[i] = 0;
            while(int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

void solve() {
    memo.clear();
    idx = 0;
    int n;
    cin >> n;

    set <int> lt, rt;
    vector < pair <int, int> > edges;

    for (int i = 0; i < n; ++i) {
        string x, y;
        cin >> x >> y;
        int u = getId(x);
        int v = getId(y);
        edges.push_back(make_pair(u, v));
        lt.insert(u);
        rt.insert(v);
    }
    DinicFlow net(lt.size() + rt.size() + 2);
    int source = lt.size() + rt.size();
    int sink = source + 1;
    for (int x : lt) {
        net.addEdge(source, x, 1);
    }
    for (int x : rt) {
        net.addEdge(x, sink, 1);
    }
    for (auto e : edges) {
        net.addEdge(e.first, e.second, 1);
    }
    int match = net.maxFlow(source, sink);
    int maxIndSet = lt.size() + rt.size() - match;
    int ans = n - maxIndSet;
    cerr << ans << '\n';
    cout << ans << '\n';
}

int main() {
    int numTests;
    cin >> numTests;
    for (int testId = 1; testId <= numTests; ++testId) {
        cerr << "Case #" << testId << ": ";
        cout << "Case #" << testId << ": ";
        solve();
    }
    return 0;
}
