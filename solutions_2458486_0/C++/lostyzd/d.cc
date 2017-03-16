#include <iostream>
#include <vector>
#include <cstring>

int k, n;
int keys[201];
bool v[201];
int t[201];
std::vector<int> res;
std::vector<int> chest[201];

bool dfs(int u, int cnt) {
  v[u] = true;
  if (cnt >= n) {
    res.push_back(u);
    return true;
  }

  for (auto it = chest[u].begin(); it != chest[u].end(); ++it) {
    ++keys[*it];
  }

  for (int i = 1; i <= n; ++i) if (!v[i] && keys[t[i]]) {
    --keys[t[i]];
    if (dfs(i, cnt + 1)) {
      res.push_back(u);
      return true;
    }
    ++keys[t[i]];
  }

  for (auto it = chest[u].begin(); it != chest[u].end(); ++it) {
    --keys[*it];
  }

  return false;
}


int main() {
  int T;
  std::cin >> T;
for (int tt = 1; tt <= T; ++tt) {
  std::cin >> k >> n;
  memset(keys, 0, sizeof keys);
  for (int i = 0; i < k; ++i) {
    int key;
    std::cin >> key;
    ++keys[key];
  }

  for (int i = 1; i <= n; ++i) {
    chest[i].clear();
    int ki;
    std::cin >> t[i] >> ki;
    for (int j = 0; j < ki; ++j) {
      int key;
      std::cin >> key;
      chest[i].push_back(key);
    }
  }

  std::cout << "Case #" << tt << ":";
  res.clear();
  for (int i = 1; i <= n; ++i) if (keys[t[i]]) {
    memset(v, 0, sizeof v);
    --keys[t[i]];
    if (dfs(i, 1)) {
      for (auto it = res.rbegin(); it != res.rend(); ++it) {
        std::cout << " " << *it;
      }
      break;
    }
    ++keys[t[i]];
  }

  if (res.size() == 0) {
    std::cout << " IMPOSSIBLE" << std::endl;
  } else {
    std::cout << std::endl;
  }
}

  return 0;
}
