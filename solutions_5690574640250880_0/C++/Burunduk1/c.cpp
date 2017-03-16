/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.04.12
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 103;

char s[N][N];

void solve( int tn )
{
  printf("Case #%d:\n", tn);

  int r, c, m, f;
  scanf("%d%d%d", &r, &c, &m), m = r * c - m;
  if (r > c)
    f = 1, swap(r, c);
  else
    f = 0;
  memset(s, 0, sizeof(s));
  forn(i, r)
    forn(j, c)
      s[i][j] = '*';
  if (m > 1)
    if (r == 1)
      forn(i, m)
        s[0][i] = '.';
    else if (r == 2)
    {
      if ((m & 1) || m == 2)
      {
        puts("Impossible");
        return;
      }
      forn(i, m / 2)
        s[0][i] = s[1][i] = '.';
    }
    else
    {
      if (m == 2 || m == 3 || m == 5 || m == 7)
      {
        puts("Impossible");
        return;
      }

      int k = r;
      if (k * k > m && m < 2 * k + 2)
        k = sqrt(m);
      int w = m / k;
      forn(i, k)
        forn(j, w)
          s[i][j] = '.';
      m -= k * w;
      if (m)
      {
        if (m == 1)
          s[k - 1][w - 1] = '*', m++;
        forn(i, m)
          s[i][w] = '.';
      }
    }
  s[0][0] = 'c';
  if (f)
  {
    forn(i, N)
      forn(j, i)
        swap(s[i][j], s[j][i]);
    swap(r, c);
  }
  forn(i, r)
    puts(s[i]);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
    solve(t + 1);
  return 0;
}
