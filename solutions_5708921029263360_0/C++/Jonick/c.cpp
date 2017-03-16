#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int cap = 0;
  int flow = 0;
};

bool remove(vector<vector<Edge>>& gr, const vector<vector<int>>& adj, vector<bool>& vis, int v, int dest) {
  if (v == dest) {
    return true;
  }
  if (vis[v]) {
    return false;
  }
  vis[v] = true;
  for (int x : adj[v]) {
    if (vis[x])
      continue;
    if (gr[v][x].flow > 0 && remove(gr, adj, vis, x, dest)) {
      gr[v][x].flow -= 1;
      gr[x][v].flow += 1;
      return true;
    }
  }
  assert(false);
  return false;
}

int dfs(vector<vector<Edge>>& gr, const vector<vector<int>>& adj, vector<bool>& vis, int v, int dest, int curFl) {
  if (v == dest && curFl > 0) {
    return curFl;
  }
  if (vis[v]) {
    return 0;
  }
  vis[v] = true;
  for (int x : adj[v]) {
    if (vis[x])
      continue;
    if (gr[v][x].flow < gr[v][x].cap) {
      int res = dfs(gr, adj, vis, x, dest, std::min(curFl, gr[v][x].cap - gr[v][x].flow));
      if (res > 0) {
	gr[v][x].flow += res;
	gr[x][v].flow -= res;
	return res;
      }
    }
  }
  return 0;
}

void solveTest() {
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  int n = A * B * C + A * B + B * C + A * C + 2;
  vector<vector<Edge> > edges(n, vector<Edge>(n));
  vector<vector<int>> adj(n);
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      for (int k = 0; k < C; k++) {
	int pos = i * B * C + j * C + k;
	edges[n-1][pos].cap = 3;
	int pos1 = A * B * C + (i * B + j);
	int pos2 = A * B * C + (A * B + i * C + k);
	int pos3 = A * B * C + (A * B + A * C + j * C + k);
	assert(pos1 < n - 2 && pos2 < n - 2 && pos3 < n - 2);
	edges[pos1][n - 2].cap = K;
	edges[pos][pos1].cap = 1;
	edges[pos2][n - 2].cap = K;
	edges[pos][pos2].cap = 1;
	edges[pos3][n - 2].cap = K;
	edges[pos][pos3].cap = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (edges[i][j].cap > 0 || edges[j][i].cap > 0) {
	adj[i].push_back(j);
      }
    }
  }

  vector<tuple<int, int, int>> result;
  while (true) {
    while (true) {
      vector<bool> vis(n);
      int res = dfs(edges, adj, vis, n - 1, n - 2, 1000);
      if (res == 0)
	break;
    }
    bool has = false;
    for (int i = 0; i < A * B * C; i++) {
      if (edges[n-1][i].flow < 3 && edges[n-1][i].cap > 0) {
	for (int j = 0; j < edges[n-1][i].flow; j++) {
	  vector<bool> vis(n);
	  assert(remove(edges, adj, vis, i, n - 2));
	}
	edges[n-1][i].flow = 0;
	edges[n-1][i].cap = 0;
	edges[i][n-1].flow = 0;
	edges[i][n-1].cap = 0;
	has = true;
	break;
      }
    }
    if (!has)
      break;
  }
  
  for (int i = 0; i < A * B * C; i++) {
    if (edges[n-1][i].flow == 3) {
      int tmp = i;
      int x = tmp / (B * C);
      tmp %= B * C;
      int y = tmp / C;
      tmp %= C;
      int z = tmp;
      result.push_back(make_tuple(x, y, z));
    }
  }
  
  cout << result.size() << "\n";
  for (auto tup : result) {
    cout << get<0>(tup) + 1 << " " << get<1>(tup) + 1 << " " << get<2>(tup) + 1 << "\n";
  }
}

int main() {
  int tn;
  cin >> tn;
  for (int tc = 0; tc < tn; tc++) {
    cout << "Case #" << (tc+1) << ": ";
    solveTest();
  }
  return 0;
}
