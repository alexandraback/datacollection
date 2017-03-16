#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
typedef pair <int, ll> pii;
const int N = 110;
int z, n, m;
int ta[N], tb[N];
ll a[N], b[N], ans;
ll sum[N][N];
vector <pii> t;
void precalc()
{
  for(int i = 1; i <= 100; i++)
    for(int j = 0; j < m; j++)
      sum[i][j] = (j == 0 ? 0 : sum[i][j - 1]) + (tb[j] == i) * b[j];
}
ll calc(int l, int k, int tp)
{
  return sum[tp][l + k - 1] - (l == 0 ? 0 : sum[tp][l - 1]);
}
ll solve2()
{
  ll ans = 0;
  for(int i = 0; i <= m; i++)
  {
    int j = m - i;
    ll c0 = 0, c1 = 0;
    if (i)
      c0 = calc(0, i, t[0].first);
    if (j)
      c1 = calc(i, j, t[1].first);
    ll res = min(t[0].second, c0) + min(t[1].second, c1);
    ans = max(ans, res);
  }
  return ans;
}
ll solve3()
{
  ll ans = 0;
  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= m; j++)
    {
      int k = m - i - j;
      if (k < 0) continue;
      ll c0 = 0, c1 = 0, c2 = 0;
      if (i)
        c0 = calc(0, i, t[0].first);
      if (j)
        c1 = calc(i, j, t[1].first);
      if (k)
        c2 = calc(i + j, k, t[2].first);
      ll res = min(t[0].second, c0) + min(t[1].second, c1) + min(t[2].second, c2);
      ans = max(ans, res);
    }
  return ans;
}
vector <pii> build(int mask)
{
  vector <pii> res;
  res.clear();
  if (mask == 7)
  {
    if (ta[0] == ta[1] && ta[1] == ta[2])
      res.pb(mp(ta[0], a[0] + a[1] + a[2]));
    else if (ta[0] == ta[1])
    {
      res.pb(mp(ta[0], a[0] + a[1]));
      res.pb(mp(ta[2], a[2]));
    }
    else if (ta[1] == ta[2])
    {
      res.pb(mp(ta[0], a[0]));
      res.pb(mp(ta[1], a[1] + a[2]));
    }
    else
    {
      res.pb(mp(ta[0], a[0]));
      res.pb(mp(ta[1], a[1]));
      res.pb(mp(ta[2], a[2]));
    }
  }
  else if (mask == 6)
  {
    if (ta[1] == ta[2])
      res.pb(mp(ta[1], a[1] + a[2]));
    else
    {
      res.pb(mp(ta[1], a[1]));
      res.pb(mp(ta[2], a[2]));
    }
  }
  else if (mask == 5)
  {
    if (ta[0] == ta[2])
      res.pb(mp(ta[0], a[0] + a[2]));
    else
    {
      res.pb(mp(ta[0], a[0]));
      res.pb(mp(ta[2], a[2]));
    }
  }
  else if (mask == 3)
  {
    if (ta[0] == ta[1])
      res.pb(mp(ta[0], a[0] + a[1]));
    else
    {
      res.pb(mp(ta[0], a[0]));
      res.pb(mp(ta[1], a[1]));
    }
  }
  else if (mask == 4)
    res.pb(mp(ta[2], a[2]));
  else if (mask == 2)
    res.pb(mp(ta[1], a[1]));
  else if (mask == 1)
    res.pb(mp(ta[0], a[0]));
  return res;
}
int main()
{
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("O.txt", "w", stdout);
  cin >> z;
  for(int q = 0; q < z; q++)
  {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      cin >> a[i] >> ta[i];
    for(int i = 0; i < m; i++)
      cin >> b[i] >> tb[i];
    precalc();
    ans = 0;
    if (n == 1)
      ans = min(a[0], calc(0, m, ta[0]));
    else if (n == 2)
    {
      for(int w = 1; w < 4; w++)
      {
        t = build(w);
        if (t.size() == 1)
          ans = max(ans, min(t[0].second, calc(0, m, t[0].first)));
        else
          ans = max(ans, solve2());
      }
    }
    else
    {
      for(int w = 1; w < 8; w++)
      {
        t = build(w);
        if (t.size() == 1)
          ans = max(ans, min(t[0].second, calc(0, m, t[0].first)));
        else if (t.size() == 2)
          ans = max(ans, solve2());
        else
          ans = max(ans, solve3());
      }
    }
    cout << "Case #" << q + 1 << ": " << ans << endl;
  }
  return 0;
}
