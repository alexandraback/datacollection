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

#define taskname "c"

int tpow[10];

set < pair<int, int> > s;

void calc (int k, int a, int b)
{
  int len = 0;

  while (tpow[len] <= k)
    len++;

  for (int i = 1; i < len; i++)
  {
    if (k % tpow[i] < tpow[i - 1])
      continue;
    int nk = k / tpow[i] + (k % tpow[i]) * (tpow[len - i]); 
    if ((nk < k && nk >= a && nk <= b))
      s.insert(mp(nk, k));
  }
}

void solve (int tst_num)
{
  s.clear();
  int a, b;

  scanf ("%d %d", &a, &b);

  for (int i = a; i <= b; i++)
    calc(i, a, b);

  printf ("Case #%d: %d\n", tst_num, s.size());

  return;
}
              
int main (void)
{
  freopen (taskname".in", "r", stdin);
  freopen (taskname".out", "w", stdout);

  tpow[0] = 1;

  for (int i = 1; i < 10; i++)
    tpow[i] = tpow[i - 1] * 10;

  int tst_cnt;

  scanf ("%d", &tst_cnt);

  for (int i = 0; i < tst_cnt; i++)
    solve(i + 1);

  return 0;
}

