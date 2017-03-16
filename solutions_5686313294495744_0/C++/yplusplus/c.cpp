#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<string, string> Topic;
const int N = 5555;
const int M = 100000;

int que[N], head, tail;
int eh[N], cur[N], tot;
int dist[N];

struct Edge {
    int u, v, flow, cap, next;
} et[M];

void init() {
    memset(eh, -1, sizeof(eh));
    tot = 0;
}

void add(int u, int v, int flow, int cap) {
    Edge e = {u, v, flow, cap, eh[u]};
    et[tot] = e;
    eh[u] = tot++; 
}

void addedge(int u, int v, int cap) {
    add(u, v, 0, cap);
    add(v, u, 0, 0);
}

bool bfs(int s, int t) {
    head = 0;
    tail = 0;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    que[tail++] = s;
    while (head < tail && dist[t] == -1) {
        int u = que[head++];
        for (int i = eh[u]; i != -1; i = et[i].next) {
            int v = et[i].v;
            if (et[i].flow < et[i].cap && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que[tail++] = v;
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int t, int d) {
    if (u == t) return d;
    int l = d;
    for (int &i = cur[u]; i != -1; i = et[i].next) {
        int v = et[i].v;
        if (et[i].cap > et[i].flow && dist[u] + 1 == dist[v]) {
            int tmp = dfs(v, t, min(et[i].cap - et[i].flow, l));
            et[i].flow += tmp;
            et[i ^ 1].flow -= tmp;
            l -= tmp;
            if (l == 0) break;
        }
    }
    return d - l;
}

int Dinic(int s, int t, int n) {
    int flow = 0;
    while (bfs(s, t)) {
        for (int i = 0; i < n; i++) cur[i] = eh[i];
        flow += dfs(s, t, 1111);
        //cout << flow << endl;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Topic> topics;
        map<string, int> lt;
        map<string, int> rt;
        map<string, int> lt_index;
        map<string, int> rt_index;
        topics.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> topics[i].first >> topics[i].second;
            const Topic &topic = topics[i];
            lt[topic.first]++;
            rt[topic.second]++;
            if (lt_index.count(topic.first) == 0) {
                lt_index[topic.first] = lt_index.size();
            }
            if (rt_index.count(topic.second) == 0) {
                rt_index[topic.second] = rt_index.size();
            }
        }
        init();
        int S = lt_index.size() + rt_index.size();
        int T = S + 1;
        for (auto it = lt.begin(); it != lt.end(); it++) {
            if (it->second > 1)
            addedge(S, lt_index[it->first], it->second - 1);
        }
        for (auto it = rt.begin(); it != rt.end(); it++) {
            if (it->second > 1)
            addedge(rt_index[it->first] + lt_index.size(), T, it->second - 1);
        }
        for (auto it = topics.begin(); it != topics.end(); it++) {
            addedge(lt_index[it->first], lt_index.size() + rt_index[it->second], 1);
        }
        int flow = Dinic(S, T, T + 1);
        cout << "Case #" << Case++ << ": " << flow << endl;
    }
    return 0;
}
