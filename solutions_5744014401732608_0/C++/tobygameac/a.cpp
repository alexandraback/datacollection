#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void Traverse(size_t current_index, const std::vector<std::string> &map, std::vector<int> &visited, size_t max_need, size_t &ways) {
  if (current_index == map.size() - 1) {
    ++ways;
    return;
  }
  if (ways > max_need) {
    return;
  }
  for (size_t i = 0; map[current_index][i]; ++i) {
    if (map[current_index][i] == '1') {
      if (!visited[i]) {
        visited[i] = true;
        Traverse(i, map, visited, max_need, ways);
        visited[i] = false;
      } else {
        ways = max_need + 1;
      }
    }
  }
}

void Solve(size_t r, size_t c, std::vector<std::string> &map, size_t target, bool &solved) {
  if (solved) {
    return;
  }
  if (r == map.size()) {
    size_t ways = 0;
    std::vector<int> visited(map.size());
    Traverse(0, map, visited, target, ways);
    if (ways == target) {
      solved = true;
      std::cout << "POSSIBLE\n";
      for (size_t r = 0; r < map.size(); ++r) {
        std::cout << map[r] << "\n";
      }
    }
    return;
  }
  if (c == map.size()) {
    Solve(r + 1, 0, map, target, solved);
    return;
  }
  if ((r != c) && (r != (map.size() - 1))) {
    map[r][c] = '1';
    Solve(r, c + 1, map, target, solved);
  }
  map[r][c] = '0';
  Solve(r, c + 1, map, target, solved);
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t B, M;
    std::cin >> B >> M;
    std::cout << "Case #" << t << ": ";
    std::vector<std::string> map(B, std::string(B, '0'));
    bool solved = false;
    Solve(0, 0, map, M, solved);
    if (!solved) {
      std::cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}
