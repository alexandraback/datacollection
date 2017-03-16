#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 100

using namespace std;

int grid[MAX][MAX], RMAX[MAX], CMAX[MAX];

int main() {
  int ncases, n, m;

  scanf("%i", &ncases);
  for (int caseno = 1; caseno <= ncases; caseno++) {
    fill(RMAX, RMAX + MAX, 0);
    fill(CMAX, CMAX + MAX, 0);

    scanf("%i%i", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf("%i", grid[i] + j);
        RMAX[i] = max(RMAX[i], grid[i][j]);
        CMAX[j] = max(CMAX[j], grid[i][j]);
      }

    bool pass = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        pass &= grid[i][j] == min(RMAX[i], CMAX[j]);

    printf("Case #%i: %s\n", caseno, pass ? "YES" : "NO");
  }
}
