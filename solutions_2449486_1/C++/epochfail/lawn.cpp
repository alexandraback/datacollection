#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int grid[105][105];
bool r[105][105];

void solve() {
  memset(r, 0, sizeof(r));

  int h, w;
  scanf("%d %d ", &h, &w);
  for (int i = 0; i < h; i++)
    for (int k = 0; k < w; k++)
      scanf("%d ", &grid[i][k]);

  for (int y = 0; y < h; y++) {
    int top = 0;
    for (int x = 0; x < w; x++)
      top = max(top, grid[y][x]);

    for (int x = 0; x < w; x++)
      if (grid[y][x] == top)
        r[y][x] = true;
  }

  for (int x = 0; x < w; x++) {
    int top = 0;
    for (int y = 0; y < h; y++)
      top = max(top, grid[y][x]);

    for (int y = 0; y < h; y++)
      if (grid[y][x] == top)
        r[y][x] = true;
  }

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (!r[y][x]) {
        printf("NO\n");
        return;
      }
  printf("YES\n");
}

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    printf("Case #%d: ", i+1);
    solve();
  }
}
