#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  srand(531830291);

  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    int best = 0;
    bool bestUsed[15][15][15];

    for(int j = 0; j < 100; ++j) {
      int nr = 0;
      bool used[15][15][15] = {false};
      int a[15][15] = {0};
      int b[15][15] = {0};
      int c[15][15] = {0};

      for(int i = 0; i < 10000; ++i) {
        int x = (rand() % J) + 1;
        int y = (rand() % P) + 1;
        int z = (rand() % S) + 1;

        if(!used[x][y][z] && a[x][y] < K && b[x][z] < K && c[y][z] < K) {
          used[x][y][z] = true;
          ++a[x][y];
          ++b[x][z];
          ++c[y][z];
          ++nr;
        }
      }

      if(nr > best) {
        best = nr;
        for(int i = 1; i <= J; ++i) for(int j = 1; j <= P; ++j) for(int h = 1; h <= S; ++h) {
          bestUsed[i][j][h] = used[i][j][h];
        }
      }
    }

    // if(best != J*S*min(S, K)) {
    //   cout << "WHAT!?!?" << endl;
    // }

    cout << best << endl;
    for(int i = 1; i <= J; ++i) for(int j = 1; j <= P; ++j) for(int h = 1; h <= S; ++h) {
      if(bestUsed[i][j][h]) {
        cout << i << " " << j << " " << h << endl;
      }
    }


    
  }
  return 0;
}