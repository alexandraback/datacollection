#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

template <class Flow, class Cost>
class MinCostFlow {
    public:
    
    MinCostFlow(int n, Flow eps = 0, Cost inf = 1e9) : size(n), graph(n), EPS(eps), INF(inf) {
        pot = (Cost *)malloc(sizeof(Cost) * size);
        dist = (Cost *)malloc(sizeof(Cost) * size);
        prevv = (int *)malloc(sizeof(int) * size);
        preve = (int *)malloc(sizeof(int) * size);
    }
    
    ~MinCostFlow() {
        free(pot);
        free(dist);
        free(prevv);
        free(preve);
    }
    
    void add_edge(int from, int to, Flow cap, Cost cost) {
        graph[from].push_back(Edge(to, cap, cost, graph[to].size()));
        graph[to].push_back(Edge(from, 0, -cost, graph[from].size() - 1));
    }
    
    Cost min_cost_flow(int source, int sink, Flow flow, bool negative = false) {
        Cost cost = 0;
        
        for (int i = 0; i < size; i++) pot[i] = 0;
        
        if (negative) {
            while (1) {
                bool update = false;
                
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < graph[i].size(); j++) {
                        if (graph[i][j].cap > EPS && pot[graph[i][j].to] > pot[i] + graph[i][j].cost) {
                            pot[graph[i][j].to] = pot[i] + graph[i][j].cost;
                            update = true;
                        }
                    }
                }
                
                if (update == false) break;
            }
        }
        
        while (flow > EPS) {
            Flow res = flow;
            priority_queue <pair<Cost, int> > que;
            
            for (int i = 0; i < size; i++) dist[i] = INF;
            
            dist[source] = 0;
            que.push(make_pair(0, source));
            
            while (!que.empty()) {
                Cost tmp = -que.top().first;
                int now = que.top().second;
                
                que.pop();
                
                if (dist[now] < tmp) continue;
                
                for (int i = 0; i < graph[now].size(); i++) {
                    Edge &edge = graph[now][i];
                    
                    if (edge.cap > EPS && dist[edge.to] > dist[now] + edge.cost + pot[now] - pot[edge.to]) {
                        dist[edge.to] = dist[now] + edge.cost + pot[now] - pot[edge.to];
                        prevv[edge.to] = now;
                        preve[edge.to] = i;
                        que.push(make_pair(-dist[edge.to], edge.to));
                    }
                }
            }
            
            if (pot[sink] + dist[sink] >= 0) return cost;
            
            if (dist[sink] == INF) return INF;
            
            for (int i = sink; i != source; i = prevv[i]) res = min(res, graph[prevv[i]][preve[i]].cap);
            
            flow -= res;
            cost += res * (dist[sink] + pot[sink] - pot[source]);
            
            for (int i = sink; i != source; i = prevv[i]) {
                Edge &edge = graph[prevv[i]][preve[i]];
                
                edge.cap -= res;
                graph[i][edge.rev].cap += res;
            }
            
            for (int i = 0; i < size; i++) pot[i] += dist[i];
        }
        
        return cost;
    }
    
    private:
    
    int size;
    Flow EPS;
    Cost INF;
    Cost *pot;
    Cost *dist;
    int *prevv;
    int *preve;
    
    struct Edge {
        int to;
        Flow cap;
        Cost cost;
        int rev;
        Edge(int to, Flow cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };
    
    vector <vector <Edge> > graph;
};

char s1[21];
char s2[21];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, c, ans, j;
        map <string, int> mp, mp2;
        vector <pair<int, int> > v;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            scanf("%s %s", s1, s2);
            
            if (!mp.count(s1)) {
                int x = mp.size();
                mp[s1] = x;
            }
            if (!mp2.count(s2)) {
                int x = mp2.size();
                mp2[s2] = x;
            }
            
            v.push_back(make_pair(mp[s1], mp2[s2]));
        }
        
        c = mp.size() * 2 + mp2.size() * 2 + 2;
        MinCostFlow <int, int> mcf(c);
        
        for (j = 0; j < mp.size(); j++) {
            mcf.add_edge(c - 2, j, 1e9, 0);
            mcf.add_edge(j, mp.size() + j, 1e9, 0);
            mcf.add_edge(j, mp.size() + j, 1, -1e5);
        }
        
        for (j = 0; j < mp2.size(); j++) {
            mcf.add_edge(mp.size() * 2 + mp2.size() + j, c - 1, 1e9, 0);
            mcf.add_edge(mp.size() * 2 + j, mp.size() * 2 + mp2.size() + j, 1e9, 0);
            mcf.add_edge(mp.size() * 2 + j, mp.size() * 2 + mp2.size() + j, 1, -1e5);
        }
        
        for (j = 0; j < v.size(); j++) mcf.add_edge(mp.size() + v[j].first, mp.size() * 2 + v[j].second, 1, 1);
        
        ans = mcf.min_cost_flow(c - 2, c - 1, 1e9, true);
        ans = (ans % 100000 + 100000) % 100000;
        
        printf("Case #%d: %d\n", i + 1, n - ans);
    }
    
    return 0;
}
