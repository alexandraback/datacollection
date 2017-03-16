#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 110;

int N, S, p;
int t[MAXN];
int high[2][31];

void init() {
  memset(high, -1, sizeof(high));
  for (int i = 0; i <= 10; ++i)
    for (int j = i; j <= 10; ++j)
      for (int k = j; k <= 10; ++k) {
	if (k - i > 2) continue;
	int suprising = 0;
	if (k - i == 2) suprising = 1;
	int s = i + j + k;
	int h = max(max(i, j), k);
	if (high[suprising][s] < h) high[suprising][s] = h;
      }
}

int f[MAXN][MAXN];

int solve() {
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= S; ++j) {
      for (int k = 0; k < 2; ++k) {
	if (j < k || f[i - 1][j - k] == -1) continue;
	int tmp = f[i - 1][j - k] + (high[k][t[i]] >= p);
	if (tmp > f[i][j]) f[i][j] = tmp;
      }
    }
  return f[N][S];
}

int main() {
  init();

  int T;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d%d%d", &N, &S, &p);
    for (int i = 1; i <= N; ++i) scanf("%d", t + i);
    printf("Case #%d: %d\n", c, solve());
  }
  return 0;
}
