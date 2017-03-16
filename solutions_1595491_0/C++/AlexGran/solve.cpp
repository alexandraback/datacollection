#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define zero(a) memset (a, 0, sizeof(a))
#define sz(a) (int)(a.size())
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair

#define taskname "b"

const int maxn = 102;
const int inf = 1000000;

int t[maxn];
int f[maxn][maxn];

int intresting (int a, int b, int c)
{
  if (c - a == 2)
    return 1;
  return 0;
}

bool good (int a, int b, int c)
{
  if (b < a || c < b || c < a)
    return false;
  if (b - a > 2 || c - a > 2 || c - b > 2)
    return false; 
  return true;
}

void relax (int ni, int nj, int i, int j, bool v)
{
  f[ni][nj] = max(f[ni][nj], f[i][j] + v);
}

void solve (int tst_num)
{
  int n, s, p;

  scanf ("%d %d %d", &n, &s, &p);

  for (int i = 0; i < n; i++)
    scanf ("%d", &t[i]);

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      f[i][j] = -inf;

  f[0][0] = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      for (int k = 0; k <= t[i]; k++)
        for (int l = k; l + k <= t[i]; l++)
        {
          if (!good(k, l, t[i] - k - l))
            continue;
          relax(i + 1, j + intresting(k, l, t[i] - k - l), i, j, (t[i] - k - l >= p));
        }
    }
  }

  printf ("Case #%d: %d\n", tst_num, f[n][s]);

  return;
}
              
int main (void)
{
  freopen (taskname".in", "r", stdin);
  freopen (taskname".out", "w", stdout);

  int tst_cnt;

  scanf (" %d", &tst_cnt);

  for (int i = 1; i <= tst_cnt; i++)
    solve(i);

  return 0;
}

