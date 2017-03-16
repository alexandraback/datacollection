#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
typedef long double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define y1 djeudyw92
const int N = 1e4 + 10;
set <int> s;
pair <int, int> a[N];
int n, en[N], v[N], energy[N];
ll e, r;
ll solve()
{
  s.clear();
  cin >> e >> r >> n;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a[i].f);
    a[i].s = -(i + 1);
    v[i + 1] = a[i].f;
  }
  s.insert(0);
  s.insert(n + 1);
  en[0] = en[n + 1] = 0;
  energy[0] = e;
  sort(a, a + n);
  for (int i = n - 1; i >= 0; --i)
  {
    a[i].s = -a[i].s;
    s.insert(a[i].s);
    set <int>::iterator it = s.find(a[i].s), it1;
    it++;
    int nxt = *it;
    it--;
    it--;
    int prev = *it;
    energy[a[i].s] = min(e, energy[prev] + r * (a[i].s - prev));
    /*ll L = energy[a[i].s] - en[nxt] + r * (nxt - a[i].s);////next
    ll R = energy[prev] + r * (a[i].s - prev);////prev*/
    ll L = e, R = e;
    it1 = it;
    it1++;
    it1++;
    ll sum = 0;
    for (; (*it) != 0; it--)
    {
      R = min(R, energy[*it] + r * (a[i].s - (*it)) - sum);
      sum += en[*it];
    }
    sum = 0;
    for (; (*it1) != n + 1; it1++)
    {
      L = min(L, energy[a[i].s] - en[(*it1)] + r * ((*it1) - a[i].s) - sum);
      sum += en[*it1];
    }
    en[a[i].s] = max(0LL, min(L, R));
    energy[a[i].s] -= en[a[i].s];
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
  {
    ans += 1LL * v[i] * max(0, en[i]);
    //cout << en[i] << endl;
  }
  return ans;
}
int main()
{
  freopen("B-large (1).in", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i)
    cout << "Case #" << i << ": " << solve() << endl;
  return 0;
}
