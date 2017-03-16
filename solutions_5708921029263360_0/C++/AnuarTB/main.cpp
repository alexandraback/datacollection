#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef long long ll;

const int N = 5000;

struct edge {
  int a, b, cap, flow;
};

vector<edge> e;
vector<int> g[N];

int start;
int finish;

void addEdge(int u, int v, int c) {
  g[u].pb(e.size());
  e.pb({u, v, c, 0});
  g[v].pb(e.size());
  e.pb({v, u, 0, 0});
}

int d[N];
int q[N];

int head, tail;

inline bool bfs() {
  memset(d, -1, sizeof d);
  d[start] = 0;
  head = tail = 0;
  q[tail++] = start;
  while (head < tail) {
    int v = q[head++];
    for (auto id : g[v]) {
      int to = e[id].b;
      if (d[to] == -1 && e[id].flow < e[id].cap) {
        d[to] = d[v] + 1;
        q[tail++] = to;
      }
    }
  }
  return d[finish] != -1;
}

int pt[N];

int dfs(const int &v, const int &flow) {
  if (v == finish || flow == 0) return flow;
  for (int &i = pt[v]; i < g[v].size(); i++) {
    int id = g[v][i];
    int to = e[id].b;
    if (d[to] == d[v] + 1 && e[id].cap > e[id].flow) {
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
  }
  return 0;
}

int dinitz() {
  for (auto &it : e)
    it.flow = 0;

  int res = 0;
  while (bfs()) {
    memset(pt, 0, sizeof pt);
    while (int x = dfs(start, (int) 1e9))
      res += x;
  }
  return res;
}

int id[11][11][11];
int next_free;

int wa[N];
int wb[N];
int wc[N];

int get(int a, int b, int c) {
  if (id[a][b][c])
    return id[a][b][c];
  id[a][b][c] = ++next_free;
  wa[next_free] = a;
  wb[next_free] = b;
  wc[next_free] = c;
  return id[a][b][c];
}

int cases;

int main() {
  #ifdef LOCAL
	  freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  #endif // LOCAL


  cin >> cases;
  for (int case_id = 1; case_id <= cases; case_id++) {
    cout << "Case #" << case_id << ": ";
    next_free = 0;
    int j, p, s, k;
    cin >> j >> p >> s >> k;
    memset(id, 0, sizeof id);
    for (int a = 1; a <= j; a++) {
      for (int b = 1; b <= p; b++) {
        addEdge(start, get(a, b, 0), k);
        for (int c = 1; c <= s; c++) {
          addEdge(get(a, b, 0), get(0, b, c), 1);
          addEdge(get(0, b, c), get(a, 0, c), k);
        }
      }
    }
    finish = ++next_free;
    for (int a = 1; a <= j; a++)
      for (int c = 1; c <= s; c++)
        addEdge(get(a, 0, c), finish, k);
    int total = dinitz();
    cout << total << endl;
    for (int a = 1; a<= j; a++) {
      for (int b = 1; b <= p; b++) {
        for (auto to : g[get(a,b,0)]) {
          if (e[to].flow > 0) {
            cout << a << ' ' << b << ' ' << wc[e[to].b] <<  endl;
          }
        }
      }
    }
    for (int i = 0; i <= finish; i++)
      g[i].clear();
    e.clear();
  }


  return 0;
}
