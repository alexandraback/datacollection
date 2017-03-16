#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector< pair<int, int> > vert;
vector<int> edg[55];
bool conn[55][55];

int stack[55];
int sttop;

bool visited[55];

bool vert_in_stack[55];
bool dfs_vis[55];

bool dfs(int v) {
  //cout << "dfs(" << v << ")\n";
  if (vert_in_stack[v]) return true;
  dfs_vis[v] = true;
  for (int i = 0; i < edg[v].size(); ++i) {
    int u = edg[v][i];
    if (visited[u] && !vert_in_stack[u]) continue;
    if (dfs_vis[u]) continue;
    if (dfs(u)) return true;
  }
  return false;
}

bool will_stay_reachable(int v, int new_top) {
  for (int i = 0; i < n; ++i) vert_in_stack[i] = false;
  for (int i = 0; i < n; ++i) dfs_vis[i] = false;
  for (int i = 0; i < new_top; ++i) {
    vert_in_stack[stack[i]] = true;
    //cout << "in stack: " << stack[i] << endl;
  }
  bool res = dfs(v);
  //cout << "will stay reachable(" << v << " " << vert[v].first << ", " << new_top << ") = " << res << endl;
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cin >> n >> m;

    vert.clear();
    for (int i = 1; i <= n; ++i) {
      int zip;
      cin >> zip;
      vert.push_back(make_pair(zip, i));
    }
    sort(vert.begin(), vert.end());

    for (int i = 0; i < n; ++i) edg[i].clear();
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) conn[i][j] = false;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      int ia, ib;
      for (int j = 0; j < n; ++j) {
        if (vert[j].second == a) ia = j;
        if (vert[j].second == b) ib = j;
      }
      edg[ia].push_back(ib);
      edg[ib].push_back(ia);
      conn[ia][ib] = conn[ib][ia] = true;
    }
    for (int i = 0; i < n; ++i) sort(edg[i].begin(), edg[i].end());

    /*
    for (int i = 0; i < n; ++i) {
      cout << i << ": ";
      for (int j = 0; j < edg[i].size(); ++j) {
        cout << edg[i][j] << ", ";
      }
      cout << endl;
    }
    // */

    cout << "Case #" << tt << ": " << vert[0].first;

    stack[0] = 0;
    sttop = 1;

    for (int i = 1; i < n; ++i) visited[i] = false;
    visited[0] = true;

    for (int visited_cnt = 1; visited_cnt < n; ++visited_cnt) {
      for (int i = 1; i < n; ++i) {
        if (visited[i]) continue;

        // is reachable from stack?
        int j;
        for (j = sttop-1; j >= 0; --j) {
          if (conn[i][stack[j]]) {
            // will not screw anything on top of it?
            for (int k = j+1; k < sttop; ++k) {
              for (int l = 0; l < edg[stack[k]].size(); ++l) {
                int child = edg[stack[k]][l];
                if (visited[child]) continue;
                if (!will_stay_reachable(child, j+1)) {
                  goto not_good;
                }
              }
            }

            break;
          }
        }
        if (!conn[i][stack[j]]) goto not_good;

        // good
        sttop = j+1; // pop everything above
        stack[sttop++] = i;
        visited[i] = true;
        cout << vert[i].first;
        break;

        not_good: ;
      }
    }

    cout << endl;
  }
}
