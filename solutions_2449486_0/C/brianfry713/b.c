#define DEBUG 0

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
  int tc, cn, x, y, X, Y, max_x[100], max_y[100], valid, i, j;
  int g[100][100], a[100][100];
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    vector<pair<int, pair<int, int> > > v;
    scanf("%d%d", &Y, &X);
    for(y = 0; y < Y; y++)
      max_y[y] = 1;
    for(x = 0; x < X; x++)
      max_x[x] = 1;
    for(y = 0; y < Y; y++)
      for(x = 0; x < X; x++) {
        scanf("%d", &g[x][y]);
        a[x][y] = 100;
        max_x[x] = max(max_x[x], g[x][y]);
        max_y[y] = max(max_y[y], g[x][y]);
        v.push_back(make_pair(-g[x][y], make_pair(x, y)));
      }
    sort(v.begin(), v.end());

    for(i = 0, valid = 1; i < X * Y; i++) {
      x = v[i].second.first;
      y = v[i].second.second;
      if(a[x][y] == g[x][y])
        continue;
      if(g[x][y] == max_x[x])
        for(j = 0; j < Y; j++)
          a[x][j] = g[x][y];
      else if(g[x][y] == max_y[y])
        for(j = 0; j < X; j++)
          a[j][y] = g[x][y];
      else {
        valid = 0;
        if(DEBUG)
          printf("%d,%d max_x=%d max_y=%d\n", x, y, max_x[x], max_y[y]);
        break;
      }
    }
    printf("Case #%d: %s\n", cn, valid ? "YES" : "NO");
  }
  return 0;
}
