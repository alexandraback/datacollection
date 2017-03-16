#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int T, N;

  std::cin >> T;
  for (int ii = 1; ii <= T; ii++) {
    std::cout << "Case #" << ii << ": ";
    std::cin >> N;

    std::vector<double> blocks1, blocks2;
    double input;
    for (int jj = 0; jj < N; jj++) {
      std::cin >> input;
      blocks1.push_back(input);
    }
    for (int jj = 0; jj < N; jj++) {
      std::cin >> input;
      blocks2.push_back(input);
    }
    std::sort(blocks1.begin(), blocks1.end());
    std::sort(blocks2.begin(), blocks2.end());

    std::vector<double> blocks1_copy(blocks1.begin(), blocks1.end());
    std::vector<double> blocks2_copy(blocks2.begin(), blocks2.end());
    int war_score = 0;

    while (blocks1_copy.size()) {
      double block = blocks1_copy[0];
      if (block > blocks2_copy[blocks2_copy.size()-1]) {
        war_score += 1;
        blocks2_copy.erase(blocks2_copy.begin());
        blocks1_copy.erase(blocks1_copy.begin());
      }
      else {
        for (int jj = 0; jj < blocks2_copy.size(); jj++) {
          if (blocks2_copy[jj] > block) {
            blocks2_copy.erase(blocks2_copy.begin()+jj);
            blocks1_copy.erase(blocks1_copy.begin());
            break;
          }
        }
      }
    }

    int deceit_score = 0;

    while (blocks1.size()) {
      bool okayToWin = true;
      for (int ii = 0; ii < blocks1.size(); ii++) {
        if (blocks1[ii] < blocks2[ii]){
          okayToWin = false;
          break;
        }
      }
      if (okayToWin) {
        deceit_score += blocks1.size();
        break;
      }
      double block = blocks1[0];
      if (block > blocks2[blocks2.size()-1]) {
        deceit_score += 1;
        blocks2.erase(blocks2.begin());
        blocks1.erase(blocks1.begin());
      }
      else {
        blocks2.erase(blocks2.begin()+(blocks2.size()-1));
        blocks1.erase(blocks1.begin());
      }
    }

    std::cout << deceit_score << " " << war_score << std::endl;
  }
}
