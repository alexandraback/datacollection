#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int maxl = 1000;
const int MAXN = 2010;
const int INF = 1e9;
typedef pair<string, string> Node;
map<string, int> im[2];
int imi;
multiset<string> cm[2];
set<string> covered[2];
Node nodes[maxl+5];
bool valid[maxl+5];

struct Edge {
  int from, to, cap, flow, cost; // No need for cost if only using maximum flow algorithm
  Edge(int u, int v, int c, int f);
};

struct EdmondsKarp {
  int n, m; // Number of nodes and edges
  vector<Edge> edges; // Edges vector that saves information of all edges
  vector<int> graph[MAXN]; // Adjacency list that saves index to edges vector
  int a[MAXN]; // Minimum flow in the augmenting path from source to i
  int p[MAXN]; // Parent pointer array to retrieve path (This saves the index of edges NOT vertices)
  // Initialization
  void init(int n);
  // Add an edge
  void addEdge(int from, int to, int cap);
  // Run Edmond Karp's algorithm to find the maximum flow from s to t
  int maxFlow(int s, int t);
};

EdmondsKarp flow;

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int kase = 1; kase <= tc; kase++) {
    int cnt;
    cin >> cnt;
    string line;
    getline(cin, line);
    cm[0].clear();
    cm[1].clear();
    for(int i = 0; i < cnt; i++) {
      getline(cin, line);
      stringstream ss(line.c_str());
      ss >> nodes[i].first >> nodes[i].second;
      cm[0].insert(nodes[i].first);
      cm[1].insert(nodes[i].second);
    }
    im[0].clear();
    im[1].clear();
    covered[0].clear();
    covered[1].clear();
    imi = 1;
    int vcnt = 0;
    for(int i = 0; i < cnt; i++) {
      if(cm[0].count(nodes[i].first) > 1 && cm[1].count(nodes[i].second) > 1) {
	valid[i] = true;
	vcnt++;
      } else {
	valid[i] = false;
	if(cm[0].count(nodes[i].first) > 1) {
	  covered[0].insert(nodes[i].first);
	}
	if(cm[1].count(nodes[i].second) > 1) {
	  covered[1].insert(nodes[i].second);
	}
      }
    }
    for(int i = 0; i < cnt; i++) {
      if(valid[i]) {
	//printf("valid is %d\n", i);
	if(!covered[0].count(nodes[i].first) && !im[0].count(nodes[i].first)) {
	  im[0][nodes[i].first] = imi++;
	}
	if(!covered[1].count(nodes[i].second) && !im[1].count(nodes[i].second)) {
	  im[1][nodes[i].second] = imi++;
	}
      }
    }
    
    int s = 0, t = imi++;
    flow.init(imi);
    for(map<string, int>::iterator itr = im[0].begin(); itr != im[0].end(); itr++) {
      flow.addEdge(s, itr->second, 1);
    }
    for(map<string, int>::iterator itr = im[1].begin(); itr != im[1].end(); itr++) {
      flow.addEdge(itr->second, t, 1);
    }
    for(int i = 0; i < cnt; i++) {
      if(valid[i]) {
	flow.addEdge(im[0][nodes[i].first], im[1][nodes[i].second], 1);
      }
    }
    int val = flow.maxFlow(s, t);
    //printf("flow is %d imi is %d vcnt is %d\n", val, imi, vcnt);
    int mincover = imi - 2 - val;
    printf("Case #%d: %d\n", kase, vcnt - mincover);
  }
  return 0;
}

Edge::Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}

void EdmondsKarp::init(int n) {
  for(int i = 0; i < n; i++) {
    graph[i].clear();
  }
  edges.clear();
  this->n = n;
}

void EdmondsKarp::addEdge(int from, int to, int cap) {
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0)); // Remember to add a back edge
  m = edges.size();
  graph[from].push_back(m-2);
  graph[to].push_back(m-1);
}

int EdmondsKarp::maxFlow(int s, int t) {
  int flow = 0;
  while(true) {
    memset(a, 0, sizeof a);
    queue<int> q;
    q.push(s);
    a[s] = INF;
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      for(int i = 0; i < graph[x].size(); i++) {
	Edge& e = edges[graph[x][i]];
	if(!a[e.to] && e.cap > e.flow) {
	  p[e.to] = graph[x][i];
	  a[e.to] = min(a[x], e.cap - e.flow);
	  q.push(e.to);
	}
      }
      if(a[t])
	break;
    }
    if(!a[t])
      break;
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    flow += a[t];
  }
  return flow;
}
