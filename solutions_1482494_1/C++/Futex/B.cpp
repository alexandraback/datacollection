#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;



int main() {

  int cases;
  cin >> cases;
  for (int c = 0; c < cases; ++c) {

    int levels;
    cin >> levels;

    vector<int> one(levels);
    vector<int> two(levels);
    for (int lev = 0; lev < levels; ++lev) {
      cin >> one[lev] >> two[lev];
    }

    int stars = 0;
    int moves = 0;
    while (true) {
      bool acted = false;
      int best_one = -1;

      for (int idx = 0; idx < levels; ++idx) {
        if (two[idx] == -1) {
          continue;
        }

        if (two[idx] >= 0 &&
            two[idx] <= stars) {
          two[idx] = -1;
          if (one[idx] >= 0) {
            one[idx] = -1;
            stars += 2;
          } else {
            ++stars;
          }
          acted = true;
          break;
        }

        if (one[idx] >= 0 &&
            one[idx] <= stars) {
          if (best_one >= 0) {
            if (two[idx] >= two[best_one]) {
              best_one = idx;
            }
          } else {
            best_one = idx;
          }
        }
      }

      if (acted) {
        ++moves;
        continue;
      }
      if (best_one >= 0) {
        one[best_one] = -1;
        ++stars;
        ++moves;
        continue;
      }

      break;
    }

    cout << "Case #" << (c + 1) << ": ";
    if (stars == 2 * levels) {
      cout << moves;
    } else {
      cout << "Too Bad";
    }
    cout << endl;
  }

  return 0;
}
