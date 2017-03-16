#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000 * 1000 * 1000;

struct Edge {
    int b, u, c, f;
    size_t back;
};

void add_edge (vector < vector<Edge> > & g, int a, int b, int u, int c) {
    Edge r1 = { b, u, c, 0, g[b].size() };
    Edge r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int solve(int n, int k, vector<vector<Edge>>& g, int s, int t)
{
    int flow = 0,  cost = 0;
    while (flow < k) {
        vector<int> id (n, 0);
        vector<int> d (n, INF);
        vector<int> q (n);
        vector<int> p (n);
        vector<size_t> p_Edge (n);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)  qh = 0;
            for (size_t i=0; i<g[v].size(); ++i) {
                Edge & r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == n)  qt = 0;
                    }
                    else if (id[r.b] == 2) {
                        if (--qh == -1)  qh = n-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_Edge[r.b] = i;
                }
            }
        }
        if (d[t] == INF)  break;
        int addflow = k - flow;
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_Edge[v];
            addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_Edge[v],  r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            cost += g[pv][pr].c * addflow;
        }
        flow += addflow;
    }

    return cost;
}

template <class T>
int indexOf(T begin, T end, const string& what) {
    return distance(begin, lower_bound(begin, end, what));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int numTests;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        int n;
        cin >> n;
        vector<pair<string, string>> topics(n);
        vector<string> firsts, seconds;
        for (int i = 0; i < n; ++i) {
            cin >> topics[i].first >> topics[i].second;
            firsts.push_back(topics[i].first);
            seconds.push_back(topics[i].second);
        }
        sort(firsts.begin(), firsts.end());
        sort(seconds.begin(), seconds.end());
        firsts.erase(unique(firsts.begin(), firsts.end()), firsts.end());
        seconds.erase(unique(seconds.begin(), seconds.end()), seconds.end());
        int sf = firsts.size();
        int ss = seconds.size();
        int m = 1 + sf + ss + 1;
        int s = m, t = m + 1;
        vector<vector<Edge>> g(t + 1);
        for (int i = 0; i < sf; ++i) {
            add_edge(g, 0, i + 1, INF, 0);
            add_edge(g, s, i + 1, 1, 0);
        }
        add_edge(g, s, m - 1, ss, 0);
        for (int j = 0; j < ss; ++j) {
            add_edge(g, sf + 1 + j, m - 1, INF, 0);
            add_edge(g, sf + 1 + j, t, 1, 0);
        }
        add_edge(g, 0, t, sf, 0);
        add_edge(g, m - 1, 0, INF, 0);
        for (int i = 0; i < topics.size(); ++i) {
            int a = indexOf(firsts.begin(), firsts.end(), topics[i].first);
            int b = indexOf(seconds.begin(), seconds.end(), topics[i].second);
            a++;
            b += 1 + sf;
            add_edge(g, a, b, 1, 1);
        }
        cout << "Case #" << test << ": " << n - solve(t + 1, INF, g, s, t) << endl;
    }    
    return 0;
}
