#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi adj;
vi enter[1024];

int dist(int u, int res){
  int Ma = 0;
  for (int v : enter[u]){
    if (v == res) continue;
    Ma = max(Ma, 1 + dist(v, u));
  }
  return Ma;
}

void solve(){
  int n; cin >> n;
  for (int i = 0; i < 1024; i++) enter[i].clear();

  adj.resize(n);
  for (int i = 0; i < n; i++){
    cin >> adj[i];
    adj[i]--;
    enter[adj[i]].push_back(i);
  }
  int res = 0;
  vi allow;
  int maxcyc = 0;
  vi used(n, 0);
  for (int i = 0; i < n; i++){
    if (used[i]) continue;
    vi vis(n, 0);
    int cur = adj[i], len = 1;
    while (cur != i){
      if (vis[cur]) break;
      vis[cur] = 1;
      cur = adj[cur];
      len++;
    }
    if (i == cur){
      used[i] = 1;
      cur = adj[i];
      used[cur] = 1;
      cur = adj[cur];
      if (len == 2){
	allow.push_back(i);
	allow.push_back(adj[i]);
	res += 2;
      } else {
	maxcyc = max(maxcyc, len);
      }
    }
  }
  for (int i = 0; i < (int) allow.size(); i++){
    res += dist(allow[i], allow[i ^ 1]);
  }
  res = max(res, maxcyc);
  cout << res << endl;
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ": ";
    solve();
  }


  return 0;
}
