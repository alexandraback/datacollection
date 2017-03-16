#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXS = 12;

struct str {
  int a, b, c;
};

int ima[MAXS][MAXS][MAXS];
int zad[MAXS];
int p[3], kk;
vector <str> R;

int Ok(int a, int b, int c)
{
  if (ima[a][b][c])
    return 0;

  if (a >= p[0] || b >= p[1] || c >= p[2])
    return 0;

  int br = 1;
  for (int i=0; i<p[2]; i++)
    br += ima[a][b][i];

  if (br > kk)
    return 0;

  br = 1;
  for (int i=0; i<p[1]; i++)
    br += ima[a][i][c];

  if (br > kk)
    return 0;

  br = 1;
  for (int i=0; i<p[0]; i++)
    br += ima[i][b][c];

  if (br > kk)
    return 0;

  return 1;
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    scanf("%d%d%d", &p[0], &p[1], &p[2]);
    scanf("%d", &kk);
    printf("Case #%d: ", br);

    P sor[3];
    for (int i=0; i<3; i++)
      sor[i] = P(p[i], i);

    sort(sor, sor + 3);
    
    memset(ima, 0, sizeof ima);
    memset(zad, -1, sizeof zad);
    if (sor[2].X <= kk) {
      printf("%d\n", p[0] * p[1] * p[2]);
      for (int i=0; i<p[0]; i++)
        for (int j=0; j<p[1]; j++)
          for (int k=0; k<p[2]; k++) {
            assert(Ok(i, j, k));
            ima[i][j][k] = 1;
            printf("%d %d %d\n", i+1, j+1, k+1);
          }
      continue;
    }

    R.clear();
    for (int i=0, k=(zad[0] + 1) % sor[2].X; i<sor[0].X; i++, k=(zad[0] + 1) % sor[2].X)
      for (int j=0; j<sor[1].X; j++) {
        for (int kol=0; kol<kk; kol++, k = (k+1) % sor[2].X) {
          int nov[3];
          nov[sor[0].Y] = i;
          nov[sor[1].Y] = j;
          nov[sor[2].Y] = k;
          zad[j] = k;

          assert(Ok(nov[0], nov[1], nov[2]));
          ima[nov[0]][nov[1]][nov[2]] = 1;
          R.push_back(str{nov[0], nov[1], nov[2]});
        }
      }

    printf("%d\n", (int) R.size());
    for (auto it : R)
      printf("%d %d %d\n", it.a+1, it.b+1, it.c+1);

    assert((int) R.size() == min(p[0] * p[1] * p[2], min(p[0] * p[1], min(p[1] * p[2], p[0] * p[2])) * kk));
  }

  return 0;
}

