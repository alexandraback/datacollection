#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int findIndex(vector<string> &a, string b) {
    for(int i = 0; i < a.size(); i++)
        if (a[i] == b) return i;
    return -1;
}

int solve() {
    vector<string> a, b;
    int n;
    cin >> n;
    vector<int> ida(n), idb(n);
    for(int i = 0; i < n; i++) {
        string aa, bb;
        cin >> aa >> bb;
        int ia = findIndex(a, aa);
        if (ia == -1) {
            ia = a.size(); a.push_back(aa);
        }
        ida[i] = ia;
        int ib = findIndex(b, bb);
        if (ib == -1) {
            ib = b.size(); b.push_back(bb);
        }
        idb[i] = ib;
    }

    int na = a.size(), nb = b.size();
    vector<int> dega(na, 0), degb(nb, 0);
    for(int i = 0; i < n; i++) {
        dega[ida[i]]++; degb[idb[i]]++;
    }
    Dinic d(na + nb + 2);
    for(int i = 0; i < na; i++) d.AddEdge(0, i + 1, dega[i] - 1);
    for(int i = 0; i < nb; i++) d.AddEdge(na + 1 + i, na + nb + 1, degb[i] - 1);
    for(int i = 0; i < n; i++) d.AddEdge(ida[i] + 1, na + 1 + idb[i], 1);

    return d.GetMaxFlow(0, na + nb + 1);
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int ntests;
    cin >> ntests;
    for(int tc = 1; tc <= ntests; tc++) {
        cout << "Case #" << tc << ": ";
        cout << solve() << endl;
    }
}
