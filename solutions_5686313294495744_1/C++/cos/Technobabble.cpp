#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}


typedef int Weight;
struct Edge {
  int index;
  int src;
  int dest;
  Weight capacity;
  Weight cost;
  Edge(int index, int src, int dest, Weight capacity, Weight cost) : index(index), src(src), dest(dest), capacity(capacity), cost(cost) {;}
  bool operator<(const Edge &rhs) const {
    if (cost != rhs.cost) { return cost > rhs.cost; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void printMatrix(const Matrix &matrix) {
  for (int y = 0; y < (int)matrix.size(); y++) {
    for (int x = 0; x < (int)matrix[y].size(); x++) {
      cout << matrix[y][x] << " ";
      // printf("%d ", matrix[y][x]);
    }
    puts("");
  }
}

// index^1 is reverse edge
pair<Weight, Weight> MinCostFlow(const Graph &g, int e, int s, int t, int target) {
  const int n = g.size();
  Array capacity(e, 0);
  for (int from = 0; from < n; from++) {
    for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
      capacity[it->index] += it->capacity;
    }
  }
  pair<Weight, Weight> ret = make_pair(0, 0);
  vector<pair<int, int> > parent(n);
  vector<Weight> prev_dist(n, 0);
  vector<Weight> now_dist(n);

  // calc potential
  for (int iter = 0; iter < n; iter++) {
    bool end = true;
    for (int from = 0; from < n; from++) {
      for (int i = 0; i < (int)g[from].size(); i++) {
        if (capacity[g[from][i].index] <= 0) { continue; }
        int to = g[from][i].dest;
        Weight ncost = prev_dist[from] + g[from][i].cost;
        if (ncost < prev_dist[to]) {
          end = false;
          prev_dist[to] = ncost;
        }
      }
    }
    if (end) { break; }
    if (iter == n - 1) {
      assert(false); // exist negative cycle
    }
  }

  while (true) {
    fill(parent.begin(), parent.end(), make_pair(-1, -1));
    fill(now_dist.begin(), now_dist.end(), 2000000000LL);
    priority_queue<Edge> que;
    que.push(Edge(e, s, s, 0, 0));
    now_dist[s] = 0;
    while (!que.empty()) {
      Edge node = que.top();
      que.pop();
      if (parent[node.dest].first != -1) { continue; }
      parent[node.dest] = make_pair(node.src, node.index);
      int from = node.dest;
      for (int i = 0; i < (int)g[from].size(); i++) {
        int to = g[from][i].dest;
        int index = g[from][i].index;
        Weight ncost = node.cost + g[from][i].cost + (prev_dist[from] - prev_dist[to]);
        if (capacity[index] <= 0) { continue; }
        if (ncost >= now_dist[to]) { continue; }
        now_dist[to] = ncost;
        que.push(Edge(i, from, to, 0, ncost));
      }
    }
    if (parent[t].first == -1) { break; }
    pair<int, int> index = parent[t];
    Weight flow = 2000000000LL;
    while (index.second != e) {
      flow = min(flow, capacity[g[index.first][index.second].index]);
      index = parent[index.first];
    }
    ret.first += flow;
    index = parent[t];
    while (index.second != e) {
      Edge edge = g[index.first][index.second];
      ret.second += flow * edge.cost;
      capacity[edge.index] -= flow;
      capacity[edge.index^1] += flow;
      index = parent[index.first];
    }
    for (int i = 0; i < n; i++) {
      prev_dist[i] += now_dist[i];
    }
    if (ret.second == -target) { break; }
  }
  return ret;
}

void AddEdge(Graph &g, int &e, int from, int to, Weight capacity, Weight cost) {
  g[from].push_back(Edge(e++, from, to, capacity, cost));
  g[to].push_back(Edge(e++, to, from, 0, -cost));
}

int n;
char str[30];
int str_num[1010][2];
map<string, int> opens[2];

inline int FIRST(int x) { return x; }
inline int SECOND(int x) { return opens[0].size() + x; }
inline int SOURCE() { return opens[0].size() + opens[1].size(); }
inline int DEST() { return opens[0].size() + opens[1].size() + 1; }
inline int SIZE() { return opens[0].size() + opens[1].size() + 2; }

void solve() {
  REP(i, 2) {opens[i].clear(); }
  scanf("%d", &n);
  REP(i, n) {
    REP(j, 2) {
      scanf("%s", str);
      if (!opens[j].count(str)) {
        int cnt = opens[j].size();
        opens[j][str] = cnt;
      }
      str_num[i][j] = opens[j][str];
    }
  }
  Graph g = Graph(SIZE());
  int e = 0;
  REP(i, n) {
    AddEdge(g, e, FIRST(str_num[i][0]), SECOND(str_num[i][1]), 1, 0);
  }
  REP(i, opens[0].size()) {
    AddEdge(g, e, SOURCE(), FIRST(i), 1, -1);
    AddEdge(g, e, SOURCE(), FIRST(i), n, 0);
  }
  REP(i, opens[1].size()) {
    AddEdge(g, e, SECOND(i), DEST(), 1, -1);
    AddEdge(g, e, SECOND(i), DEST(), n, 0);
  }
  int ans = n - MinCostFlow(g, e, SOURCE(), DEST(), SIZE() - 2).first;
  printf("%d\n", ans);
}
