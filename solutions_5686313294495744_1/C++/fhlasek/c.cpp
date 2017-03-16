/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

class BipartiteGraph {
  private:
    vector<int> partity1, partity2; // Original indexes
    map<int, int> new_index1, new_index2; // Mapping to new indexes
    vector< vector<int> > graph1, graph2; // Lists of neighbours

    // Tries to match a vertex v from the first partity with some
    // vertex from the other partity.
    bool match(int v);
    vector<int> matched1, matched2; // Some auxiliary variables
    vector<bool> visited1, visited2;

  public:
    void add_edge(int index1, int index2);
    void add_vertex1(int index);
    void add_vertex2(int index);

    // Returns a list of edges in the matching
    vector<pair<int, int> > maximum_matching();

    // Returns a list of pairs (original index, partity), where partity is 1 or 2
    vector<pair<int, int> > maximum_independent_set();
    vector<pair<int, int> > minimum_vertex_cover();
};

void BipartiteGraph::add_edge(int index1, int index2) {
  add_vertex1(index1);
  add_vertex2(index2);
  int i1 = new_index1[index1], i2 = new_index2[index2];
  graph1[i1].push_back(i2);
  graph2[i2].push_back(i1);
}

void BipartiteGraph::add_vertex1(int index) {
   // if a vertex with that index is already in the graph, don't add it again
  if (new_index1.find(index) != new_index1.end()) return;

  new_index1[index] = (int)partity1.size();
  partity1.push_back(index);
  graph1.push_back(vector<int>());
}

void BipartiteGraph::add_vertex2(int index) {
   // if a vertex with that index is already in the graph, don't add it again
  if (new_index2.find(index) != new_index2.end()) return;

  new_index2[index] = (int)partity2.size();
  partity2.push_back(index);
  graph2.push_back(vector<int>());
}

bool BipartiteGraph::match(int v) {
  visited1[v] = true;
  REP(i, graph1[v].size()) {
    int w = graph1[v][i];
    if (matched2[w] == -1 || (!visited1[matched2[w]] && match(matched2[w]))) {
      matched1[v] = w;
      matched2[w] = v;
      return true;
    }
  }
  return false;
}

vector<pair<int, int> > BipartiteGraph::maximum_matching() {
  matched1.clear(); matched2.clear();
  visited1.clear(); visited2.clear();
  REP(i, partity1.size()) {
    matched1.push_back(-1);
    visited1.push_back(false);
  }
  REP(i, partity2.size()) {
    matched2.push_back(-1); // not matched yet
    visited2.push_back(false);
  }
  REP(i, partity1.size()) {
    REP(j, partity1.size()) visited1[j] = false;
    match(i);
  }
  vector< pair<int, int> > result;
  REP(i, partity1.size()) if (matched1[i] != -1) {
    result.push_back(make_pair(partity1[i], partity2[matched1[i]]));
  }
  return result;
}

#define MAXN 111111
map<string, int> wa, wb;
int Wa, Wb, N;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    Wa = Wb = 0; wa.clear(); wb.clear();
    scanf("%d", &N);
    BipartiteGraph bg;
    REP(i, N) {
      string a, b;
      cin >> a >> b;
      if (!wa.count(a)) wa[a] = Wa++;
      if (!wb.count(b)) wb[b] = Wb++;
      bg.add_edge(wa[a], wb[b]);
    }
    int ans = N - Wa - Wb + bg.maximum_matching().size();
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
