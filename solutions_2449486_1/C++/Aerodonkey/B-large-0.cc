#include <iostream>
#include <vector>

bool IsFeasible(int width, int length, const std::vector<std::vector<int> >& heights) {
  for (int r = 0; r < width; r++) {
    for (int c = 0; c < length; c++) {
      bool feasible;
      // row
      feasible = true;
      for (int i = 0; i < length; i++) {
        if (heights[r][i] > heights[r][c]) {
          feasible = false;
          break;
        }
      }
      if (feasible) {
        continue;
      }
      // column
      feasible = true;
      for (int i = 0; i < width; i++) {
        if (heights[i][c] > heights[r][c]) {
          feasible = false;
          break;
        }
      }
      if (feasible) {
        continue;
      }
      // failure
      return false;
    }
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int numCases;
  std::cin >> numCases;
  for (int caseNum = 1; caseNum <= numCases; caseNum++) {
    int length, width;
    std::cin >> width >> length;
    std::vector<std::vector<int> > heights(width);
    for (int i = 0; i < width; i++) {
      heights[i].resize(length);
      for (int j = 0; j < length; j++) {
        std::cin >> heights[i][j];
      }
    }
    bool feasible = IsFeasible(width, length, heights);
    std::cout << "Case #" << caseNum << ": " << (feasible ? "YES" : "NO") << std::endl;
  }
}
