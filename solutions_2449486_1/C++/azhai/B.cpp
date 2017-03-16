#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 200, M_MAX = 200;
const int HEIGHT_MAX = 100000;

int N, M;
int height[N_MAX][M_MAX];

int row_heights[N_MAX];
int col_heights[M_MAX];

void solve_case(int t) {
  cin >> N >> M;

  memset(row_heights, 0, sizeof(row_heights));
  memset(col_heights, 0, sizeof(col_heights));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      height[i][j] = a;

      row_heights[i] = max(row_heights[i], a);
      col_heights[j] = max(col_heights[j], a);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (height[i][j] != min(row_heights[i], col_heights[j])) {
        cout << "Case #" << t << ": NO\n";
        return;
      }
    }
  }

  cout << "Case #" << t << ": YES\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }
  return 0;
}
