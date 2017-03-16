/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.13
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 1010;

int tn, h, w, a[N][N], b[N][N];

int main()
{
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);
    scanf("%d%d", &h, &w);
    forn(i, h)
      forn(j, w)
        scanf("%d", &a[i][j]), b[i][j] = 100;
    for (int run = 1; run; )
    {
      run = 0;
      forn(i, h)
      {
        int ma = 0;
        forn(j, w)
          ma = max(ma, a[i][j]);
        forn(j, w)
          if (b[i][j] > ma)
            b[i][j] = ma, run = 1;
      }
      forn(j, w)
      {
        int ma = 0;
        forn(i, h)
          ma = max(ma, a[i][j]);
        forn(i, h)
          if (b[i][j] > ma)
            b[i][j] = ma, run = 1;
      }
    }

    int bad = 0;
    forn(i, h)
      forn(j, w)
        bad |= a[i][j] != b[i][j];
    puts(bad ? "NO" : "YES");
  }
  return 0;
}
