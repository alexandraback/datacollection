#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string zip[51];
vector<vector<int> > adj;
bool used[51];
vector<char> vis;

void dfs(int i) {
  vis[i] = true;

  for (int j = 0; j < adj[i].size(); j++)
    if (!vis[adj[i][j]]) dfs(adj[i][j]);
}

bool reachable(int st, const vector<char>& done) {
  vis = done;
  dfs(st);
  
  for (int i = 0; i < N; i++)
    if (!vis[i] && !used[i]) return false;
  return true;
}

int main() {
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int M; cin >> N >> M;
    adj = vector<vector<int> >(N);

    int st = -1;
    for (int i = 0; i < N; i++) {
      cin >> zip[i];
      used[i] = false;
      if (st == -1 || zip[i] < zip[st]) {
        st = i;
      }
    }

    for (int i = 0; i < M; i++) {
      int a, b; cin >> a >> b;
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
    }

    string ans = zip[st];
    used[st] = true;
    vector<int> stk;
    vector<char> fked(N);
    stk.push_back(st);
    for (int n = 0; n < N-1; n++) {
      // which one is available next??
      string low = "";
      int lowptr = -1, node = -1;
      for (int i = stk.size()-1; i >= 0; i--) {
        for (int j = 0; j < adj[stk[i]].size(); j++) {
          int k = adj[stk[i]][j];
          if (!fked[k] && !used[k] && (node == -1 || zip[k] < low)) {
            // see what happens if we go here. is it still viable?
            vector<char> nfk = fked;
            // all of these become unusable
            for (int l = i+1; l < stk.size(); l++) {
              nfk[stk[l]] = true;
            }
            // see if the graph is still connected (minus fucked nodes)
            if (reachable(st, nfk)) {
              low = zip[k];
              lowptr = i;
              node = k;
            }
          }
        }
      }

      if (node == -1) throw;
      ans += low;
      used[node] = true;
      while (stk.size() != lowptr+1) {
        fked[stk.back()] = true;
        stk.pop_back();
      }
      stk.push_back(node);
    }
  
    cout << "Case #" << tt << ": " << ans << endl;
  }
}
