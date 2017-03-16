#include <algorithm>
#include <functional>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;

typedef int Matrix[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void Paint(int x, int y, int color, int N, int M, Matrix& field) {
  field[x][y] = color;

  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (nx >= 0 && ny >= 0 && nx < N && ny < M && field[nx][ny] == 0) {
      Paint(nx, ny, color, N, M, field);
    }
  }
}

int Solve() {
  int N, M, K;
  cin >> N >> M >> K;

  int result = K;

  Matrix field;
  int goog_colors[41];

  int field_size = N * M;
  int mask_size = 1 << field_size;
  for (int mask = 0; mask < mask_size; ++mask) {
    int count_K = 0;

    std::memset(field, 0, sizeof(Matrix));
    for (int i = 0; i < field_size; ++i) {
      if ((1 << i) & mask) {
        int x = i / M;
        int y = i % M;
        field[x][y] = -1;
        ++count_K;
      }
    }

    if (count_K > result) {
      continue;
    }

    std::memset(goog_colors, 0, sizeof(goog_colors));
    int color = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (field[i][j] == 0) {
          Paint(i, j, color, N, M, field);
          goog_colors[color] = 1;
          ++color;
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      assert(field[i][0] != 0);
      assert(field[i][M - 1] != 0);

      if (field[i][0] != -1) {
        goog_colors[field[i][0]] = 0;
      }
      if (field[i][M - 1] != -1) {
        goog_colors[field[i][M - 1]] = 0;
      }
    }
    for (int j = 0; j < M; ++j) {
      assert(field[0][j] != 0);
      assert(field[N - 1][j] != 0);

      if (field[0][j] != -1) {
        goog_colors[field[0][j]] = 0;
      }
      if (field[N - 1][j] != -1) {
        goog_colors[field[N - 1][j]] = 0;
      }
    }

    int actual_K = count_K;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (field[i][j] != -1) {
          if (goog_colors[field[i][j]]) {
            ++actual_K;
          }
        }
      }
    }

    if (actual_K >= K) {
      result = std::min(result, count_K);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
//  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/1.txt", "rb", stdin);
  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/C-small-attempt0.in", "rb", stdin);
  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/C-small-attempt0.out", "wb", stdout);
  int T;
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": " << Solve() << '\n';
  }
  return 0;
}
