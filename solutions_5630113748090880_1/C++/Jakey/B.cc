#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <cstdlib>
#include <algorithm>

void resetHeights(int* h, int size) {
  for (int i = 0; i < size; i++) {
    h[i] = 0;
  }
}

int main(int argc, char** argv) {
  unsigned int T;
  unsigned int N;
  int heights[3000];
  int numHeights = 3000;


  std::cin >> T;

  for (int i = 0; i < T; i ++) {
    resetHeights(heights, numHeights);
    std::cin >> N;
    int h;
    for (int j = 0; j < (2*N - 1); j++) {
      for (int k = 0; k < N; k++) {
        std::cin >> h; 
        if (heights[h] > 0)
          heights[h] -= 1;
        else
          heights[h] += 1;
      }
    }

    std::vector<int> remaining;
    for (int j = 0; j < numHeights; j++) {
      if (heights[j] != 0)
        remaining.push_back(j);
    } 

    std::sort (remaining.begin(), remaining.end()); 

    std::cout << "Case #" << i+1 << ":";

    for (int j = 0; j < remaining.size(); j++) {
      std::cout << " " << remaining[j];
    }

    std::cout << std::endl;

  }

  return 0;
}

