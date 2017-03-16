#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct union_find {
    vi p; union_find(int n) : p(n, -1) { }
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp,yp);
        p[xp] += p[yp], p[yp] = xp;
        return true; }
    int size(int x) { return -p[find(x)]; } };

vector<bool> visited;
vi order;

void scc_dfs(const vvi &adj, int u) {
    int v; visited[u] = true;
    rep(i,0,size(adj[u]))
        if (!visited[v = adj[u][i]]) scc_dfs(adj, v);
    order.push_back(u);
}

pair<union_find, vi> scc(const vvi &adj) {
    int n = size(adj), u, v;
    order.clear();
    union_find uf(n);
    vi dag;
    vvi rev(n);
    rep(i,0,n) rep(j,0,size(adj[i])) rev[adj[i][j]].push_back(i);
    visited.resize(n), fill(visited.begin(), visited.end(), false);
    rep(i,0,n) if (!visited[i]) scc_dfs(rev, i);
    fill(visited.begin(), visited.end(), false);
    stack<int> S;
    for (int i = n-1; i >= 0; i--) {
        if (visited[order[i]]) continue;
        S.push(order[i]), dag.push_back(order[i]);
        while (!S.empty()) {
            visited[u = S.top()] = true, S.pop(), uf.unite(u, order[i]);
            rep(j,0,size(adj[u])) if (!visited[v = adj[u][j]]) S.push(v);
        }
    }
    return pair<union_find, vi>(uf, dag);
}

int height(const vvi &down, int at, int par) {
    int mx = 1;
    iter(it,down[at]) {
        if (*it == par) continue;
        mx = max(mx, 1 + height(down, *it, at));
    }
    return mx;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        int n;
        cin >> n;
        vvi adj(n);
        vvi down(n);
        rep(i,0,n) {
            int nxt;
            cin >> nxt;
            nxt--;
            adj[i].push_back(nxt);
            down[nxt].push_back(i);
        }
        pair<union_find, vi> res = scc(adj);
        union_find uf = res.first;
        map<int,int> cnt;
        rep(i,0,n) {
            cnt[uf.find(i)]++;
        }
        int mx = 0,
            sm = 0;
        iter(it,cnt) {
            if (it->second == 2) {
                sm += height(down, it->first, adj[it->first][0]);
                sm += height(down, adj[it->first][0], it->first);
            } else if (it->second > 2) {
                mx = max(mx, it->second);
            }
        }
        mx = max(mx, sm);
        cout << "Case #" << (t+1) << ": " << mx << endl;
    }
    return 0;
}

