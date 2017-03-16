#include <iostream>
using namespace std;

char grid[51][51];
int cnt[51][51];
bool vis[50][50];

int di[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int R, C;

int seen = 0;
void dfs(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = true;
  seen++;
  for (int k = 0; k < 8; k++) {
    unsigned ni = i + di[k], nj = j + dj[k];
    if (ni < R && nj < C) {
      if (cnt[ni][nj] == 0) {
        dfs(ni, nj);
      } else if (!vis[ni][nj] && grid[ni][nj] == '.') {
        vis[ni][nj] = true;
        seen++;
      }
    }
  }
}

bool ok() {
  int zeros = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      vis[i][j] = 0;
      if (grid[i][j] == '.') {
        cnt[i][j] = 0;
        zeros++;
        for (int k = 0; k < 8; k++) {
          unsigned ni = i + di[k], nj = j + dj[k];
          if (ni < R && nj < C && grid[ni][nj] == '*') {
            cnt[i][j]++;
          }
        }
      } else {
        cnt[i][j] = 9;
      }
    }

  bool marked = false;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (grid[i][j] == '.' && cnt[i][j] == 0) {
        seen = 0;
        dfs(i,j);
        if (seen == zeros) {
          grid[i][j] = 'c';
          return true;
        }
      } else if (grid[i][j] == '.' && zeros == 1) {
        grid[i][j] = 'c';
        return true;
      }

  return false;
}

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int M; cin >> R >> C >> M;
    printf("Case #%d:\n", t);

    bool found = false;
    for (int mask = 0; mask < (1<<(R*C)); mask++) {
      int ct = 0;
      for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
          if (mask & (1<<(i*C+j))) {
            ct++;
            grid[i][j] = '*';
          } else {
            grid[i][j] = '.';
          }

      if (ct == M && ok()) {
        found = true;
        break;
      }
    }

    if (found) {
      for (int i = 0; i < R; i++, cout << endl)
        for (int j = 0; j < C; j++) {
          cout << grid[i][j];
        }
    } else {
      cout << "Impossible" << endl;
    }
  }
}
