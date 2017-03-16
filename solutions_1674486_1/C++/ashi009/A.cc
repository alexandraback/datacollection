#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n;
vector<int> m[1001];
vector<bool> trace(1001);

bool dfs(int start) {
  //cout << "dfs: " << start << endl;
  trace[start] = true;
  for (auto it = m[start].begin(); it != m[start].end(); it++) {
    if (trace[*it])
      return true;
    else if (dfs(*it))
      return true;
  }
  return false;
}

int main (int argc, char const* argv[])
{
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
  
    bool ok = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k, t;
      cin >> k;
      m[i].clear();
      while (k--) {
        cin >> t;
        m[i].push_back(t-1);
      }
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        trace[j] = false;
      //cout << "dfs start: " << i << endl;
      if (dfs(i)) {
        ok = true;
        break;
      }
    }
  
    cout << "Case #" << Case << ": ";
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}

