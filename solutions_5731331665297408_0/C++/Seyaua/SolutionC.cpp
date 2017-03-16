#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int maxN = 210;

int n, m;
vector <int> g[maxN];
int code[maxN];

map<int, vector <int> > cur;
set<int> used;

void dfs(int v) {
  if (used.count(v)) return;
  used.insert(v);
  vector <int> buf = cur[v];
  for (int i = 0; i < buf.size(); ++i) {
    dfs(buf[i]);
  }
}

bool check(int v) {
  used.clear();
  dfs(v);
  cur.clear();
  return used.size() == n;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
  return code[a.second] < code[b.second];
}

vector <int> bl;

void go_blocked(map<int, vector <int> >& cur, int v) {
  bl.push_back(v);
  if (!cur.count(v)) return;
  vector <int> buf = cur[v];
  for (int i = 0; i < buf.size(); ++i) {
    go_blocked(cur, buf[i]);
  }
}

void solve(int tcase) {
  printf("Case #%d: ", tcase);

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%d", &code[i]);
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector <int> have(n, 0);
  int index = -1;
  int mn = 999999;
  for (int i = 0; i < n; ++i) {
    if (code[i] < mn) {
      mn = code[i];
      index = i;
    }
  }

  have[index] = 1;
  vector <int> res;
  res.push_back(code[index]);

  map<int, vector <int> > have_edges;

  while (res.size() < n) {
    vector <pair<int, int> > edges;
    for (int i = 0; i < n; ++i) {
      if (have[i]) {
        for (int j = 0; j < g[i].size(); ++j) {
          if (have[g[i][j]]) continue;
          edges.push_back(make_pair(i, g[i][j]));
        }
      }
    }
    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < edges.size(); ++i) {
      int x = edges[i].first;
      int y = edges[i].second;

      vector <int> tk = have_edges[x];
      bl.clear();
      for (int j = 0; j < tk.size(); ++j) {
        go_blocked(have_edges, tk[j]);
      }

      set<int> tcur(bl.begin(), bl.end());

      have_edges[x].push_back(y);
      map<int, vector <int> > ngraph = have_edges;
      for (int j = 0; j < n; ++j) {
        if (!tcur.count(j)) {
          for (int k = 0; k < g[j].size(); ++k) {
            ngraph[j].push_back(g[j][k]);
          }
        }
      }

      cur = ngraph;
      if (check(index)) {
        have[y] = 1;
        for (int j = 0; j < bl.size(); ++j) {
          g[bl[j]].clear();
        }
        res.push_back(code[y]);
        break;
      } else {
        have_edges[x].pop_back();
      }
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    printf("%d", res[i]);
  }
  printf("\n");
}

vector <int> myres;
vector <int> curres;

void mydfs(int v, set<int> used, vector <int> curres, vector <int> pars) {
  if (curres > myres) return;
  if (!used.count(v)) curres.push_back(code[v]);
  used.insert(v);
  if (used.size() == n) {
    myres = min(myres, curres);
    return;
  }

  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (!used.count(to)) {
      vector <int> npars = pars;
      npars.push_back(v);
      mydfs(to, used, curres, npars);
    }
  }

  if (pars.size() > 0) {
    int nv = pars.back();
    pars.pop_back();
    mydfs(nv, used, curres, pars);
  }
}

void solve2(int tcase) {
  printf("Case #%d: ", tcase);

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    scanf("%d", &code[i]);
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int v = min_element(code, code + n) - code;
  myres.clear();
  myres.push_back(999999);
  curres.clear();

  set<int> buf;
  vector <int> p1, p2;
  mydfs(v, buf, p1, p2);

  for (int i = 0; i < n; ++i) {
    printf("%d", myres[i]);
  }
  printf("\n");
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    solve2(i + 1);
    cerr << i + 1 << endl;
  }

  return 0;
}
