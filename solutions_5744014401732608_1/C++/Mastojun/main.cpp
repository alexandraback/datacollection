#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include <string>
using namespace std;

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
    int B, M;
    cin >> B >> M;

    vector<int> path(B, 0);
    path[B - 1] = 1;
    path[B - 2] = 1;
    int num = 2;
    for (int i = B - 3; i >= 0; i--) {
      path[i] = num;
      num *= 2;
    }

    M = path[0] - M;

    cout << "Case #" << kase << ": ";
    if (M >= 0) {
      cout << "POSSIBLE" << endl;

      for (int i = 1; i < B; i++) {
        if (path[i] <= M) {
          M -= path[i];
          path[i] = 0;
        }
        else {
          path[i] -= M;
          break;
        }
      }
      vector<vector<int>> route(B, vector<int>(B, 0));
      for (int i = B - 2; i >= 0; i--) {
        if (path[i] == 0) break;
        route[i][B - 1] = 1;
        for (int j = i + 1; j < B; j++) {
          int r = path[i] - 1;
          int nextIdx = B - 2;
          while (r) {
            int next = r % 2;
            r /= 2;
            if (next) {
              route[i][nextIdx] = 1;
            }
            nextIdx--;
          }
        }
      }
      for (int i = 1; i < B; i++) {
        if (path[i]) {
          route[0][i] = 1;
        }
      }
      for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
          cout << route[i][j];
        }
        cout << endl;
      }
    }
    else {
      cout << "IMPOSSIBLE" << endl;
    }
    fprintf(stderr, "now : %d\n", kase);
  }

  return 0;
}
