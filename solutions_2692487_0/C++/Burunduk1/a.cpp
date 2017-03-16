/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.05.04
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 103;

int n, a0, a[N];
int f[N][N];

void relax( int i, int j, int F )
{
  if (j < N && f[i][j] < F)
    f[i][j] = F;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    printf("Case #%d: ", tt + 1);
    scanf("%d%d", &a0, &n);
    forn(i, n)
      scanf("%d", &a[i]);
    sort(a, a + n);
    memset(f, -1, sizeof(f));
    f[0][0] = a0;

    const int ma = n;
    forn(i, n)
      forn(j, ma + 1)
      {
        int b = f[i][j];
        relax(i + 1, j + 1, b);
        if (b > 1)
        {
          int cnt = 0;
          while (b <= a[i])
            b += b - 1, cnt++;
          relax(i + 1, j + cnt, b + a[i]);
        }
      }

    int j = 0;
    while (f[n][j] == -1)
      j++;
    printf("%d\n", j);
  }
  return 0;
}
