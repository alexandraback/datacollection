#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define M 300
#define C (M + M)

char Z[10000], F[10000];

char V[M + 1][C + 1][C + 1];

int main () {
  int tn;
  scanf ("%d", &tn);

  V[0][M][M] = 1;
  for (int l = 1; l <= M; l++) {
    for (int x = 0; x <= C; x++)
      for (int y = 0; y <= C; y++)
	if (V[l - 1][x][y]) {
	  if (x + l <= C) V[l][x + l][y] = 1;
	  if (x - l >= 0) V[l][x - l][y] = 1;
	  if (y + l <= C) V[l][x][y + l] = 1;
	  if (y - l >= 0) V[l][x][y - l] = 1;
	}
  }


  for (int t = 1; t <= tn; t++) {
    int x, y;
    scanf ("%d%d", &x, &y);
    int l = abs (x) + abs (y), k;
    for (k = 1; k <= 10000; k++) {
      int s = k * (k + 1) / 2;
      if (s >= l && (s & 1) == (l & 1)) break;
    }
    Z[k + 1] = 0;
    int ch = 1, a = abs (x), b = abs (y);
    //printf ("%d %d %d\n", a, b, k);
    while (ch) {
      ch = 0;
      while (a >= k && k > 0) {
	Z[k] = x < 0 ? 'W' : 'E';
	a -= k;
	ch = 1;
	--k;
      }
      while (b >= k && k > 0) {
	Z[k] = y < 0 ? 'S' : 'N';
	b -= k;
	ch = 1;
	--k;
      }
    }
    //printf ("%d %d %d\n", a, b, k);
    assert (a <= M && b <= M && k <= M && V[k][a + M][b + M]);
    if (x < 0) a = -a;
    if (y < 0) b = -b;
    a += M; b += M;
    assert (V[k][a][b]);

    while (k > 0) {
      if (a + k <= C && V[k - 1][a + k][b]) { a += k; Z[k] = 'W'; } else
      if (a - k >= 0 && V[k - 1][a - k][b]) { a -= k; Z[k] = 'E'; } else
      if (b + k <= C && V[k - 1][a][b + k]) { b += k; Z[k] = 'S'; } else
      if (b + k >= 0 && V[k - 1][a][b - k]) { b -= k; Z[k] = 'N'; } else assert (false);
      --k;
    }

    printf ("Case #%d: %s\n", t, Z + 1);
  }
}
