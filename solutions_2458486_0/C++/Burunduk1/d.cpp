/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.13
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define IS(a, i) (((a) >> (i)) & 1)

const int K = 40;
const int N = 20;

int good, k, n, a[K], need[N], num[N][N], have[N], deg[N], c[N][N];
int cc, u[1 << N];
int rn, r[N];
map <int, int> m;

int getInd( int x )
{
  int sz = m.size();
  if (!m.count(x))
    m[x] = sz;
  return m[x];
}

void go( int pr )
{
  if (good)
    return;
  u[pr] = cc;
  if (pr == (1 << n) - 1)
  {
    good = 1;
    forn(i, rn)
      printf("%d%c", r[i] + 1, " \n"[i == rn - 1]);
    return;
  }

  forn(i, n)
    if (!IS(pr, i) && have[need[i]] && u[pr | (1 << i)] != cc)
    {
      r[rn++] = i;
      have[need[i]]--;
      forn(j, m.size())
        have[j] += num[i][j];
      go(pr | (1 << i));
      have[need[i]]++;
      forn(j, m.size())
        have[j] -= num[i][j];
      rn--;
    }
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);
    scanf("%d%d", &k, &n);
    forn(i, k)
      scanf("%d", &a[i]);
    m.clear();
    forn(i, n)
    {
      int x;
      scanf("%d%d", &x, &deg[i]);
      need[i] = getInd(x);
      forn(j, deg[i])
        scanf("%d", &c[i][j]);
    }
    fill(num, 0);
    forn(i, n)
      forn(j, deg[i])
        if (m.count(c[i][j]))
          num[i][m[c[i][j]]]++;
    fill(have, 0);
    forn(i, k)
      if (m.count(a[i]))
        have[m[a[i]]]++;
    good = 0, rn = 0, cc++;
    go(0);
    if (!good)
      puts("IMPOSSIBLE");
  }                 
  return 0;
}
