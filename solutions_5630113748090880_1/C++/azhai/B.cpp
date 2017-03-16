#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

const int N_MAX = 60;
const int VAL_MAX = 3000;
int N;
int papers[2 * N_MAX][N_MAX];
int counts[VAL_MAX];
//int grid[N_MAX][N_MAX];

/*
void swap(int x, int y) {
  int temp[N_MAX];
  for (int i = 0; i < N; i++)
    temp[i] = papers[x][i];
  for (int i = 0; i < N; i++)
    papers[x][i] = papers[y][i];
  for (int i = 0; i < N; i++)
    papers[y][i] = temp[i];
}
*/

void init() {
  for (int i = 0; i < VAL_MAX; i++)
    counts[i] = 0;

  cin >> N;
  for (int i = 0; i < 2 * N - 1; i++) {
    for (int j = 0; j < N; j++) {
      cin >> papers[i][j];
      counts[papers[i][j]]++;
    }
  }
}

void solve_case(int t) {
  init();

  cout << "Case #" << t << ":";
  for (int i = 0; i < VAL_MAX; i++) {
    if (counts[i] % 2 == 1)
      cout << " " << i;
  }
  cout << "\n";

  // for (int k = N; k > 0; k--) {
  //   int max1 = -1, max2 = -1;
  //   for (int i = 0; i < k; i++) {
  //     int cur_max = papers[i][k - 1];

  //     if (max1 == -1) {
  //       max1 = i;
  //     } else if (cur_max > papers[max1][k - 1]) {
  //       max1 = i; max2 = -1;
  //     } else if (cur_max == papers[max1][k - 1]) {
  //       max2 = i;
  //     }
  //   }

  //   assert(max1 != -1);
  //   if (max2 == -1) {
  //     // ready to solve

  //   } else {
  //     for (int i = 0; i < k; i++) {
  //       grid[k - 1][i] = papers[max1][i];
  //       grid[i][k - 1] = papers
  //     }

  //   }
  // }
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
