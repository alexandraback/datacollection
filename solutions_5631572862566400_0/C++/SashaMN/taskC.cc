// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

int bfs(const std::vector<std::vector<int>> & g, int s,
    int first, int second) {
  std::queue<int> q;
  int n = g.size();
  q.push(s);
  std::vector<int> used(n), d(n);
  used[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); ++i) {
      int to = g[v][i];
      if (to != first && to != second && !used[to]) {
        used[to] = true;
        q.push(to);
        d[to] = d[v] + 1;
      }
    }
  }
  return *std::max_element(d.begin(), d.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    int n;
    std::cin >> n;
    std::vector<int> f(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
      int value;
      std::cin >> value;
      --value;
      f[i] = value;
      g[value].push_back(i);
    }
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
      if (f[f[i]] == i) {
        pairs.push_back({i, f[i]});
      }
    }
    int first_ans = 0;
    for (const auto & pair : pairs) {
      int first = bfs(g, pair.first, pair.first, pair.second);
      int second = bfs(g, pair.second, pair.first, pair.second);
      first_ans += first + second + 2;
    }
    int second_ans = 0;
    for (int i = 0; i < n; ++i) {
      int cur = i;
      std::vector<int> used(n);
      used[cur] = true;
      int counter = 0;
      while (true) {
        cur = f[cur];
        ++counter;
        if (cur == i) {
          second_ans = std::max(second_ans, counter);
          break;
        } else if (used[cur]) {
          break;
        }
        used[cur] = 1;
      }
    }
    std::cout << "Case #" << tt + 1 << ": " << std::max(first_ans / 2, second_ans) << std::endl;
  }
  return 0;
}

