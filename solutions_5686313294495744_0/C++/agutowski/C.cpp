#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
using namespace std;
const int N = 1003;
int T, n, gid[2], _pair[2*N], vis[2*N], gvis;
vector<int> v[2*N];
unordered_map<string, int> id[2];
bool dfs(int a) {
  vis[a] = gvis;
  for (int b: v[a]) {
    if (_pair[b] == -1 || (vis[_pair[b]] != gvis && dfs(_pair[b]))) {
      _pair[a] = b;
      _pair[b] = a;
      return true;
    }
  }
  return false;
}
string a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    id[0].clear();
    id[1].clear();
    gid[0] = 0;
    gid[1] = n;
    for (int i=0; i<n; i++) v[i].clear(), v[n+i].clear();
    for (int i=0; i<n; i++) {
      cin >> a >> b;
      if (!id[0].count(a)) {
        id[0][a] = gid[0]++;
        _pair[id[0][a]] = -1;
      }
      if (!id[1].count(b)) {
        id[1][b] = gid[1]++;
        _pair[id[1][b]] = -1;
      }
      int x = id[0][a], y = id[1][b];
      v[x].push_back(y);
      v[y].push_back(x);
    }
    bool change;
    do {
      gvis++;
      change = false;
      for (int i=0; i<gid[0]; i++)
        if (_pair[i] == -1 && vis[i] != gvis && dfs(i)) change = true;
    } while (change);
    int original = 0;
    for (int i=0; i<gid[0]; i++)
      if (_pair[i] != -1) original++;
    for (int i=n; i<gid[1]; i++)
      if (_pair[i] != -1) original++;
    assert(original % 2 == 0);
    original /= 2;
    cout << 2*n - (gid[0] + gid[1] - original) << "\n";
  }
  return 0;
}
