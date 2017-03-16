#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2020;
vector<int> adj[MAXN];
vector<int> to, from;
vector<bool> vis;
int A, B;

int dfs(int at) {
    vis[at] = true;
    for (int i=0; i<adj[at].size(); i++) if (adj[at][i] != to[at]) {
        if (from[adj[at][i]] == -1 ||
            (!vis[from[adj[at][i]]] && dfs(from[adj[at][i]]))) {
            from[adj[at][i]] = at;
            to[at] = adj[at][i];
            return 1;
        }
    }
    return 0;
}

int max_matching() {
    int ans = 0;
    vis.clear();
    for (int i=0; i<A; i++) {
        vis.assign(A, 0);
        ans += dfs(i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int cas=1; cas<=cases; cas++) {
        cout << "Case #" << cas << ": ";
        map<string, int> id;
        int lines;
        cin >> lines;
        for (int i=0; i<MAXN; i++) {
            adj[i].clear();
        }
        A = 0;
        B = 0;
        for (int i=0; i<lines; i++) {
            string a, b;
            cin >> a >> b;
            a = "L" + a;
            b = "R" + b;
            if (id.count(a) == 0) {
                id[a] = A++;
            }
            if (id.count(b) == 0) {
                id[b] = B++;
            }
            adj[id[a]].push_back(id[b]);
        }
        to.clear();
        from.clear();
        to.resize(A, -1);
        from.resize(B, -1);
        cout << lines - (id.size() - max_matching()) << '\n';
    }
    return 0;
}
