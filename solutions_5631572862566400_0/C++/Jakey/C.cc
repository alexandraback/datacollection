#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <cstdlib>

int main(int argc, char** argv) {
  unsigned int T;
  unsigned int N;

  std::cin >> T;

  for (int i = 0; i < T; i ++) {
    std::cin >> N;
    std::map<int, int> bffs;
    std::map<int, bool> visited_in;
    std::map<int, bool> visited_out;
    
    int bff;
    for (int j = 1; j <= N; j++) {
      std::cin >> bff;
      bffs[j] = bff;
    }

    int max = 0;

    for (int j = 1; j <= N; j++) {
      int idx = bffs[j];
      int prevIdx = j;
      int count = 1;
      // reset visited
      for (int k = 1; k <= N; k++) {
        visited_in[k] = false;
        visited_out[k] = false;
      }
      
      while (!visited_in[idx]) {
        if (!visited_in[bffs[idx]] || bffs[idx] == prevIdx) {
          visited_in[idx] = true;
          visited_out[prevIdx] = true;
          count++;
          prevIdx = idx;
          idx = bffs[idx];
        }
        else {
          visited_in[idx] = true;
          visited_out[prevIdx] = true;
        }
      }

      // See if we can append any remaining kinder
      int start = j;
      bool added = true;
      while (added) {
        added = false;
      for (int k = 1; k <= N; k++) {
        if (!visited_in[k]) {
          for (int l = 1; l <= N; l++) {
            if (l == k || (visited_out[l]))
              break;

            if (bffs[k] == l ) {
              visited_in[k] = true;
              visited_out[l] = true;
              count++;
              added = true;
            }
          }
        }
        else if (!visited_out[k]) {
          if (!visited_in[bffs[k]]) {
            visited_out[k] = true;
            visited_in[bffs[k]] = true;
            count++;
            added = true;
          }
        }
      }
      }

      if (count > max)
        max = count;

      if (max == N)
        break;
    }

    std::cout << "Case #" << i+1 << ": " << max << std::endl;
  }

  return 0;
}

