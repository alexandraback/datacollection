#include <bits/stdc++.h>
using namespace std;

#define MAXV 1010

static int conta, lbl[MAXV], bconta, low[MAXV], visited[MAXV], comp[MAXV];
vector<int> s;

struct node{
    int index, parent;
};

struct graph{
    node nodes[MAXV];
    vector<int> edges[MAXV];
    int size;
};

void init(graph &g, int v){
    g.size = v;
    for (int i = 0; i < v; i++){
        g.nodes[i].index = i;
        g.nodes[i].parent = -1;
        g.edges[i].clear();
    }
}

void Tarjan (graph &G, int v) {
    int p; int w;
    lbl[v] = conta++;
    low[v] = lbl[v];
    s.push_back(v);
    visited[v] = true;
    for (p = 0; p < G.edges[v].size(); ++p){
        w = G.edges[v][p]; //para grafo não-direcionado, apenas remova o .first
        if (lbl[w = G.edges[v][p]] == -1) //aqui também
            Tarjan(G, w);
        if (visited[w]) low[v] = min(low[v], low[w]);
    }
    if (low[v] == lbl[v]) {
        while (true){
            int u = s.back(); s.pop_back(); visited[u] = false;
            //printf("%d ", u);
            comp[u] = bconta;
            if (u == v) break;
        }
        bconta++;
        //printf("\n");
    }
}

void SCC (graph &G) {
    int v;
    conta = bconta = 0;
    for (int j = 0; j < G.size; ++j){ lbl[j] = -1; low[j] = j; visited[j] = false; comp[j] = j;}
    for (v = 0; v < G.size; v++)
        if (lbl[v] == -1) { Tarjan(G, v);}
}

graph g;

int main(){
    int t, cases = 1;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        init(g, n);

        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            g.edges[i].push_back(p-1);
            indegree[p-1]++;
        }

        SCC(g);

        vector<int> have(bconta, 0), together(bconta, 0);

        for (int i = 0; i < n; i++)
            have[comp[i]]++;

        vector<int> calc(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()){
            int ac = q.front();
            q.pop();

            int j = g.edges[ac][0];
            indegree[j]--;
            calc[j] = max(calc[j], calc[ac]+1);

            if (indegree[j] == 0)
                q.push(j);
        }

        for (int i = 0; i < n; i++){
            if (have[comp[i]] == 2){
                together[comp[i]] += calc[i];
            }
        }

        int y = 0;
        for (int i = 0; i < bconta; i++){
            y += together[i];
        }
        for (int i = 0; i < bconta; i++){
            y = max(have[i], y);
        }


        cout << "Case #" << cases++ << ": " << y << endl;
    }
    return 0;
}
