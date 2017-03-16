#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> subsetIndices(int n) {
    if (n == 1) {
        std::vector<std::vector<int>> vec;
        vec.push_back(std::vector<int>());
        vec.push_back(std::vector<int>());
        vec[1].push_back(0);
        return vec;
    }
    std::vector<std::vector<int>> vec = subsetIndices(n - 1);
    std::vector<std::vector<int>> vecAdd = vec;
    for (int i = 0; i < vecAdd.size(); i++) {
      vecAdd[i].push_back(n - 1);
      vec.push_back(vecAdd[i]);
    }
    return vec;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;
    std::vector<int> bffs;
    for (int j = 0; j < n; j++) {
        int bff;
        std::cin >> bff;
        bffs.push_back(bff);
    }
    std::vector<std::vector<int>> subsets = subsetIndices(n);
    int max = 1;
    for (int a = 0; a < subsets.size(); a++) {
      do {
        bool satisfied = true;
        for (int b = 0; b < subsets[a].size() && satisfied; b++) {
          int left = b - 1;
          int right = b + 1;
          if (b == 0) {
            left = subsets[a].size() - 1;
          } else if (b == subsets[a].size() - 1) {
            right = 0;
          }
          int leftKid = subsets[a][left] + 1;
          int rightKid = subsets[a][right] + 1;
          int bff = bffs[subsets[a][b]];
          if (leftKid != bff && rightKid != bff) {
            satisfied = false;
          }
        }
        if (satisfied) {
          int lenSatisfied = subsets[a].size();
          if (lenSatisfied > max) {
            max = lenSatisfied;
          }
        }
      } while (std::next_permutation(subsets[a].begin(), subsets[a].end()));
    }
    std::cout << "Case #" << (i + 1) << ": " << max << "\n";
  }
}
