#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, cap, f;
    int rev;
    Edge() {}
    Edge(int from, int to, int cap, int rev) : from(from), to(to), cap(cap), f(0), rev(rev) {}
};

class Network {
public:
    int n;
    vector< vector<Edge> > g;
    explicit Network(int n) : n(n), g(vector< vector<Edge> >(n)) {};
    void addEdge(int from, int to, int cap);
    int maxFlow(int s, int t);
    void clearFlow();
};

void Network::clearFlow() {
    forn(i, n) {
        forv(j, g[i]) {
            g[i][j].f = 0;
        }
    }
}

void Network::addEdge(int from, int to, int cap) {
    int r1 = (int)g[to].size();
    int r2 = (int)g[from].size();
    g[from].pb(Edge(from, to, cap, r1));
    g[to].pb(Edge(to, from, 0, r2));
}

int Network::maxFlow(int s, int t) {
    vector<int> pv(n), pe(n);
    vector<int> flow(n);
    vector<bool> used(n);
   
    int maxFlow = 0;
    
    while (true) {
        fill(all(used), false);
        flow[s] = INF;
        
        queue<int> q;
        q.push(s);
        used[s] = true;
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            
            forv(i, g[u]) {
                int v = g[u][i].to;
                if (used[v]) continue;
                if (g[u][i].f < g[u][i].cap) {
                    q.push(v);
                    pv[v] = u;
                    pe[v] = i;
                    used[v] = true;
                    flow[v] = min(flow[u], g[u][i].cap - g[u][i].f);
                }
            }
        }
        
        if (!used[t]) break;
        
        maxFlow += flow[t];
        
        int v = t;
        while (v != s) {
            g[pv[v]][pe[v]].f += flow[t];
            g[v][g[pv[v]][pe[v]].rev].f -= flow[t];
            v = pv[v];
        }

    }
 
    return maxFlow;
}

void solveCase(int tc) {
    printf("Case #%d: ", tc);
    cerr << tc << endl;
    int m;
    cin >> m;
    vector<int> a(m), b(m);
    map<string, int> na, nb;
    forn(i, m) {
        string s, t;
        cin >> s >> t;
        if (na.count(s) == 0) na.insert(make_pair(s, (int)na.size()));
        if (nb.count(t) == 0) nb.insert(make_pair(t, (int)nb.size()));
        a[i] = na[s];
        b[i] = nb[t];
    }
    
    int nL = (int)na.size();
    int nR = (int)nb.size();
    
    int n = nL + nR;
    int s = n++;
    int t = n++;
    int superS = n++;
    int superT = n++;
    
    vector<int> cntL(nL);
    vector<int> cntR(nR);
    forn(i, m) cntL[a[i]]++;
    forn(i, m) cntR[b[i]]++;
    
    Network net(n);
    
    forn(i, nL) {
        if (cntL[i] > 0) {
            net.addEdge(s, i, cntL[i] - 1);
        }
        net.addEdge(superS, i, 1);
        net.addEdge(s, superT, 1);
    }
    
    forn(i, nR) {
        if (cntR[i] > 0) {
            net.addEdge(i + nL, t, cntR[i] - 1);
        }
        net.addEdge(superS, t, 1);
        net.addEdge(i + nL, superT, 1);
    }
    
    forn(i, m) {
        net.addEdge(a[i], b[i] + nL, 1);
    }
    
    int lf = 0, rg = m;
    
    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        
        net.clearFlow();
        net.addEdge(t, s, mid);
        
        if (net.maxFlow(superS, superT) < nL + nR) {
            lf = mid + 1;
        } else {
            rg = mid;
        }
        
        net.g[t].pop_back();
        net.g[s].pop_back();
    }
    
    while (lf <= rg) {
        net.clearFlow();
        net.addEdge(t, s, lf);
        
        if (net.maxFlow(superS, superT) == nL + nR) {
            break;
        }
        lf++;
        
        net.g[t].pop_back();
        net.g[s].pop_back();
    }
    
    if (lf > rg) throw;
    
    cout << m - lf << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
