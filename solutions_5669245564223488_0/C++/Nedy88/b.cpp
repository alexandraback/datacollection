#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007LL;

const int MAXN = 100;
const int MAXL = 26;

string inp[MAXN];
int found[MAXL];
int used[MAXL];
int adj[MAXL][MAXL];
int inDeg[MAXL];
int outDeg[MAXL];

ll fact(ll num) {
  ll res = 1LL;
  for (ll i = 2; i <= num; ++i) {
    res *= i;
    res = res % MOD;
  }
  return res;
}

void dfs(int u) {
  used[u] = 1;
  for (int v = 0; v < MAXL; ++v) {
    if (adj[u][v] || adj[v][u]) {
      if (!used[v]) {
        dfs(v);
      }
    }
  }
}

void printFailed(int test) {
  cout << "Case #" << test << ": 0\n";
}

void solve(int test) {
  int n;
  cin >> n;
  memset(found, 0, sizeof found);
  for (int i = 0; i < n; ++i) {
    cin >> inp[i];
    for (size_t j = 0; j < inp[i].size(); ++j) {
      found[inp[i][j] - 'a'] = 1;
    }
  }
  memset(adj, 0, sizeof adj);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < int(inp[i].size()) - 1; ++j) {
      int first = int(inp[i][j] - 'a');
      int second = int(inp[i][j + 1] - 'a');
      if (first != second) {
        adj[first][second]++;
      }
    }
  }
  bool failed = false;
  for (int i = 0; i < MAXL; ++i) {
    for (int j = 0; j < MAXL; ++j) {
      if (adj[i][j] > 1) {
        failed = true;
      }
    }
  }
  for (int i = 0; i < MAXL; ++i) {
    for (int j = i + 1; j < MAXL; ++j) {
      if (adj[i][j] > 0 && adj[j][i] > 0) {
        failed = true;
      }
    }
  }
  memset(inDeg, 0, sizeof inDeg);
  memset(outDeg, 0, sizeof outDeg);
  for (int i = 0; i < MAXL; ++i) {
    for (int j = 0; j < MAXL; ++j) {
      if (adj[i][j] > 0) {
        ++outDeg[i];
      }
      if (adj[j][i] > 0) {
        ++inDeg[i];
      }
    }
    if (outDeg[i] > 1 || inDeg[i] > 1) {
      failed = true;
    }
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < MAXL; ++i) {
    if (!found[i]) continue;
    if (!used[i] && inDeg[i] == 0) {
      dfs(i);
    }
  }
  for (int i = 0; i < MAXL; ++i) {
    if (!found[i]) continue;
    if (!used[i]) {
      failed = true;
      break;
    }
  }
  if (failed) {
    printFailed(test);
    return;
  }

  int nComp = 0;
  memset(used, 0, sizeof used);
  for (int i = 0; i < MAXL; ++i) {
    if (found[i] && !used[i]) {
      dfs(i);
      ++nComp;
    }
  }
  ll res = fact(nComp);
  for (int i = 0; i < MAXL; ++i) {
    if (!found[i]) continue;
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      bool ok = true;
      for (int k = 0; k < int(inp[j].size()); ++k) {
        if (int(inp[j][k] - 'a') != i) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++cnt;
      }
    }
    if (cnt > 1) {
      ll temp = fact(cnt);
      res = (res * temp) % MOD;
    }
  }
  cout << "Case #" << test << ": " << res << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int nTests;
  cin >> nTests;
  for (int test = 1; test <= nTests; ++test) {
    solve(test);
  }
  return 0;
}
