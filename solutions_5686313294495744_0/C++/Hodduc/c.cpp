#include<stdio.h>
#include<cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <limits>
#include <queue>

using namespace std;

// From: https://github.com/kcm1700/algorithms/blob/master/graph/maxflow.cpp
struct MaxFlowDinic
{
  typedef long long flow_t;

  struct Edge
  {
    int next;
    int inv; /* inverse edge index */
    flow_t res; /* residual */
  };

  int n;
  vector<vector<Edge> > graph;

  vector<unsigned> q, l, start;

  void Init(int _n){
    n = _n;
    graph.resize(n);
    for(int i = 0; i < n; i++) graph[i].clear();
  }
  void AddNodes(int count) {
    n += count;
    graph.resize(n);
  }
  void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
    Edge forward = { e, graph[e].size(), cap };
    Edge reverse = { s, graph[s].size(), caprev };
    graph[s].push_back(forward);
    graph[e].push_back(reverse);
  }

  bool AssignLevel(int source, int sink) {
    int t = 0;
    memset(&l[0], 0, sizeof(l[0]) * l.size());
    l[source] = 1;
    q[t++] = source;
    for(int h = 0; h < t && !l[sink]; h++) {
      int cur = q[h];
      for(unsigned i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i].next;
        if (l[next]) continue;
        if (graph[cur][i].res > 0) {
          l[next] = l[cur] + 1;
          q[t++] = next;
        }
      }
    }
    return l[sink] != 0;
  }

  flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
    if (cur == sink) return currentFlow;
    for(unsigned &i = start[cur]; i < graph[cur].size(); i++) {
      int next = graph[cur][i].next;
      if (graph[cur][i].res == 0 || l[next] != l[cur]+1)
        continue;
      if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
        int inv = graph[cur][i].inv;
        graph[cur][i].res -= res;
        graph[next][inv].res += res;
        return res;
      }
    }
    return 0;
  }

  flow_t Solve(int source, int sink)
  {
    q.resize(n);
    l.resize(n);
    start.resize(n);
    flow_t ans = 0;
    while(AssignLevel(source,sink)) {
      memset(&start[0], 0, sizeof(start[0])*n);
      while(flow_t flow = BlockFlow(source,sink,numeric_limits<flow_t>::max())) {
        ans += flow;
      }
    }
    return ans;
  }
};


int A, B, E, T;
int map_i[1003][1003];
char words_A[1003][30], words_B[1003][30];

int main() {
  char t1[35], t2[35];
  scanf("%d", &T);
  for(int t=1; t<=T; t++) {
    scanf("%d", &E);
    A = B = 0;
    memset(map_i, 0, sizeof(map_i));

    for(int i=1; i<=E; i++) {
      scanf("%s %s", t1, t2);

      int n1, n2;
      for(n1 = 0; n1 < A; n1++)
        if (strcmp(words_A[n1], t1) == 0) break;
      if(n1 == A) {
        A++; strcpy(words_A[n1], t1);
      }

      for(n2 = 0; n2 < B; n2++)
        if (strcmp(words_B[n2], t2) == 0) break;
      if(n2 == B) {
        B++; strcpy(words_B[n2], t2);
      }

      map_i[n1][n2]++;
    }

    MaxFlowDinic mf;
    mf.Init(A+B+2);
    for(int i = 0; i < A; i++) for(int j = 0; j < B; j++) {
      if(map_i[i][j]) mf.AddEdge(i+1, j+A+1, map_i[i][j]);
    }
    for(int i = 1; i <= A; i++) mf.AddEdge(0, i, 1);
    for(int i = 1; i <= B; i++) mf.AddEdge(i+A, A+B+1, 1);

    long long matching = mf.Solve(0, A+B+1);
    long long vcov = A+B - matching;

    printf("Case #%d: %lld\n", t, (long long)E - vcov);
  }
  return 0;
}
