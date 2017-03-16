#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())

const int maxn = 200;

typedef long long ll;

struct st
{
  int x, y;
  ll d1 ,d2;

  st (int _x, int _y, ll _d1, ll _d2)
  {
    x = _x, y = _y, d1 = _d1, d2 = _d2;
  }
};

bool operator < (st a, st b)
{
  if (a.x != b.x)
    return a.x < b.x;
  if (a.y != b.y)
    return a.y < b.y;
  if (a.d1 != b.d1)
    return a.d1 < b.d1;
  if (a.d2 != b.d2)
    return a.d2 < b.d2;
  return 0;
}

vector <pair<ll, ll> > g[maxn][maxn];
map <st, ll> d;

int n, m;

int A[200], B[200];
ll a[200], b[200];

void solve (int tst_num)
{
  cerr<<tst_num<<endl;
  ll ans = 0;
  scanf ("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf ("%I64d %d", &a[i], &A[i]);
  for (int i = 0; i < m; i++)
    scanf ("%I64d %d", &b[i], &B[i]);

  d.clear();

  for (int i = 0; i< n; i++)
    for (int j = 0; j < m; j++)
      g[i][j].clear();

  g[0][0].pb(mp(a[0], b[0]));
  d[st(0, 0, a[0], b[0])] = 0;


  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < sz(g[i][j]); k++)
      {
//        cerr<<i<<" "<<j<<" "<<g[i][j][k].first<<" "<<g[i][j][k].second<<endl;
        ll t1 = g[i][j][k].first, t2 = g[i][j][k].second;

        if (A[i] == B[j])
        {
          ll r = min(t1, t2);
          if (d.count(st(i, j, t1 - r, t2 - r)) == 0)
          { 
            g[i][j].pb(mp(t1 - r, t2 - r));
          }
          if (d.count(st(i, j, t1 - r, t2 - r)) == 0 || d[st(i, j, t1 - r, t2 - r)] < d[st(i, j, t1, t2)] + r)
          {
            d[st(i, j, t1 - r, t2 - r)] = d[st(i, j, t1, t2)] + r;
            ans = max(ans, d[st(i, j, t1 - r, t2 - r)]);
          }
        }


        if (A[i] != B[j] || (A[i] == B[j] && min(t1, t2) == 0))
        {
          if (d.count(st(i + 1, j, a[i + 1], t2)) == 0)
            g[i + 1][j].pb(mp(a[i + 1], t2));

          if (d.count(st(i + 1, j, a[i + 1], t2)) == 0 || d[st(i + 1, j, a[i + 1], t2)] < d[st(i, j, t1, t2)])
            d[st(i + 1, j, a[i + 1], t2)] = d[st(i, j, t1, t2)];

          if (d.count(st(i, j + 1, t1, b[j + 1])) == 0)
            g[i][j + 1].pb(mp(t1, b[j + 1]));

          if (d.count(st(i, j + 1, t1, b[j + 1])) == 0 || d[st(i, j + 1, t1, b[j + 1])] < d[st(i, j, t1, t2)])
  					d[st(i, j + 1, t1, b[j + 1])] = d[st(i, j, t1, t2)];
  		 }
      }
    }

    printf ("Case #%d: %I64d\n", tst_num, ans);
  
}

int main (void)
{
  freopen ("input.txt", "rt", stdin);
  freopen ("output.txt", "wt", stdout);


  int T;

  scanf ("%d", &T);

  for (int i = 1; i <= T; i++)
    solve(i);

  return 0;
}

