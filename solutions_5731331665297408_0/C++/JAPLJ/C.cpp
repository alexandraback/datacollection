#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <stack>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

int N;
int code[64];
int adj[64][64];
int start;

struct candidate {
  int code, u;
  int from, start;
  candidate(int c, int u, int f, int s) : code(c), u(u), from(f), start(s) { }
};
bool operator < (const candidate& a, const candidate& b) {
  return (a.code != b.code ? a.code < b.code : a.start < b.start);
}

void dfs(int u, const vector<int>& vis, vector<int>& vis2, bool start_used) {
  vis2[u] = 1;
  for (int i = 0; i < N; ++i) {
    if (adj[u][i] && !vis2[i]) {
      if (vis[i] && (i != start || start_used)) {
        continue;
      }
      dfs(i, vis, vis2, start_used);
    }
  }
}

bool can_visitall(int u, const vector<int>& vis, bool start_used) {
  vector<int> vis2(N, 0);
  dfs(u, vis, vis2, start_used);
  for (int i = 0; i < N; ++i) {
    if (!vis[i] && !vis2[i]) {
      return false;
    }
  }
  return true;
}

vector<int> travel(int cur, vector<int> visited, vector<int> st, bool start_used) {
  vector<candidate> cands;
  int cand_in[55][2];
  memset(cand_in, 0, sizeof(cand_in));
  // cout<<cur<<": ";pv(visited.begin(),visited.end());pv(st.begin(),st.end());

  for (int i = (int)st.size() - 1; i >= 0; --i) {
    int u = st[i];
    for (int j = 0; j < N; ++j) {
      if (!visited[j] && adj[u][j] && !cand_in[j][0]) {
        cands.push_back(candidate(code[j], j, u, 0));
        cand_in[j][0] = 1;
      }
    }
    if (!start_used && adj[u][start]) {
      for (int j = 0; j < N; ++j) {
        if (!visited[j] && adj[start][j] && !cand_in[j][1]) {
          cands.push_back(candidate(code[j], j, u, 1));
          cand_in[j][1] = 1;
        }
      }
    }
  }

  if (cands.empty()) {
    return vector<int>();
  }

  int last = 100000;
  sort(cands.begin(), cands.end());
  vector<int> res;
  for (const candidate& cand : cands) {
    if (last < cand.code) {
      break;
    }

    for (int i = 0; i < st.size(); ++i) {
      visited[st[i]] = 0;
      if (st[i] == cand.from) break;
    }
    bool can = can_visitall(cand.u, visited, start_used | (cand.start == 1));
    for (int i = 0; i < st.size(); ++i) {
      visited[st[i]] = 1;
      if (st[i] == cand.from) break;
    }

    if (can) {
      visited[cand.u] = 1;
      vector<int> new_st;
      for (int i = 0; i < st.size(); ++i) {
        new_st.push_back(st[i]);
        if (st[i] == cand.from) {
          break;
        }
      }
      new_st.push_back(cand.u);
      vector<int> tmp = travel(cand.u, visited, new_st, start_used | (cand.start == 1));
      visited[cand.u] = 0;
      last = cand.code;
      if (res.empty() || tmp < res) {
        res = tmp;
      }
    }
  }

  res.insert(res.begin(), last);
  return res;
}

void solve() {
  N = in();
  int M = in();

  for (int i = 0; i < N; ++i) {
    code[i] = in();
  }

  memset(adj, 0, sizeof(adj));
  for (int i = 0; i < M; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    adj[a][b] = adj[b][a] = 1;
  }

  start = min_element(code, code + N) - code;
  vector<int> visited(N, 0);
  vector<int> st;
  visited[start] = 1;
  st.push_back(start);
  vector<int> res = travel(start, visited, st, true);

  printf("%d", code[start]);
  for (const int c : res) {
    printf("%d", c);
  }
  puts("");
}

int main()
{
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
