#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const string PROGRAM_NAME = "google";

typedef int dintype;
struct edge {
  edge(int t_ = 0, int n_ = 0, dintype c_ = 0) {
    to = t_;
    next = n_;
    cap = c_;
  }
  int to, next;
  dintype cap;
};
const int max_edges = 131010;
const int max_nodes = 16010;
const dintype inf = 2000000000;
edge e[max_edges];
int first[max_edges];
int edges_num = 0;
int vis[max_nodes], used[max_nodes];
int source, sink;
inline void add_edge(int from, int to, dintype cap) {
  if (edges_num == 0) {
    memset(first, -1, sizeof(first));
  }
  e[edges_num].to = to;
  e[edges_num].cap = cap;
  e[edges_num].next = first[from];
  first[from] = edges_num++;

  e[edges_num].to = from;
  e[edges_num].cap = 0;
  e[edges_num].next = first[to];
  first[to] = edges_num++;
}
dintype dfs(int node, dintype cap) {
  dintype r;
  if (node == sink) {
    return cap;
  }
  for (int index = first[node]; index != -1; index = e[index].next) {
    if (!used[e[index].to] && e[index].cap > 0
        && vis[node] == vis[e[index].to] + 1) {
      r = dfs(e[index].to, min(cap, e[index].cap));
      if (r != -1) {
        e[index].cap -= r;
        e[index ^ 1].cap += r;
        return r;
      }
    }
  }
  used[node] = 1;
  return -1;
}
dintype dinitz(const vector<vector<pair<int, dintype> > >& nt, int so, int si) {
  memset(used, 0, sizeof(used));
  memset(vis, 0, sizeof(vis));
  edges_num = 0;
  int n = (int) nt.size();
  source = so;
  sink = si;
  dintype flow = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) nt[i].size(); j++) {
      add_edge(i, nt[i][j].first, nt[i][j].second);
    }
  }
  while (true) {
    queue<int> tc;
    memset(vis, -1, sizeof(vis));
    tc.push(sink);
    vis[sink] = 0;
    while (!tc.empty() && vis[source] == -1) {
      int c = tc.front();
      tc.pop();
      for (int index = first[c]; index != -1; index = e[index].next) {
        if (e[index ^ 1].cap > 0 && vis[e[index].to] == -1) {
          tc.push(e[index].to);
          vis[e[index].to] = vis[c] + 1;
          if (e[index].to == source)
            break;
        }
      }
    }
    if (vis[source] == -1) {
      break;
    }
    memset(used, 0, sizeof(used));
    bool updated = false;
    while (1) {
      dintype f = dfs(so, inf);
      if (f == -1)
        break;
      flow += f;
      updated = true;
    }
    if (!updated)
      break;
  }
  return flow;
}

int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int N;
    cin >> N;
    map<string, int> first_words, second_words;
    string first_word, second_word;
    vector<pair<int, int> > edges;
    for (int i = 0;i < N; ++i) {
      cin >> first_word >> second_word;

      map<string, int>::iterator it = first_words.find(first_word);
      int u, v;
      if (it == first_words.end()) {
        u = (int)first_words.size();
        first_words.insert(mpair(first_word, u));
      } else {
        u = it->second;
      }
      it = second_words.find(second_word);
      if (it == second_words.end()) {
        v = (int)second_words.size();
        second_words.insert(mpair(second_word, v));
      } else {
        v = it->second;
      }
      edges.push_back(mpair(u, v));
    }

    int n = (int)first_words.size(), m = (int)second_words.size();
    vector<int> brn(n), brm(m);
    for (int i = 0; i < (int)edges.size(); ++i) {
      brn[edges[i].first]++;
      brm[edges[i].second]++;
    }
    int total_size = n + m + 2;
    int source = n + m;
    int sink = source + 1;
    vector<vector<pair<int, int> > > ne(total_size);
    for (int i = 0; i < n; ++i) {
      ne[source].push_back(mpair(i, brn[i] - 1));
    }

    for (int i = 0; i < m; ++i) {
      ne[i + n].push_back(mpair(sink, brm[i] - 1));
    }
    for (int i = 0; i < (int)edges.size(); ++i) {
      ne[edges[i].first].push_back(mpair(edges[i].second + n, 1));
    }
    cout << "Case #" << it << ": " << dinitz(ne, source, sink) << endl;
  }
  return 0;
}
