#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 128;
const int INF = 0x3f3f3f3f;

int n, s, p;
int a[N];
int f[N][N][2];
int F[N][N];

int solve(int i, int j) {
  if (F[i][j] != -1)
    return F[i][j];
  if (i == n)
    return j == s ? 0 : -INF;
  int res = -INF;
  for (int y = 0; y <= 10; y++)
    for (int z = 0; z < 2; z++)
      if (f[a[i]][y][z])
        res = max(res, (y >= p) + solve(i + 1, j + z));
  return F[i][j] = res;
}

int main() {
  for (int i = 0; i <= 10; i++)
    for (int j = 0; j <= 10; j++) if (abs(i - j) <= 2)
      for (int k = 0; k <= 10; k++) if (abs(i - k) <= 2 && abs(j - k) <= 2) {
        f[i + j + k][max(i, max(j, k))][abs(i - j) == 2 || abs(j - k) == 2 || abs(i - k) == 2]++;
      }
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d %d %d", &n, &s, &p);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    memset(F, -1, sizeof F);
    printf("Case #%d: %d\n", t, solve(0, 0));
  }
  return 0;
}
