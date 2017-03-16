#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define y1 troly
typedef long long ll;
typedef pair <int, int> pii;
typedef double db;
typedef pair <ll, int> pli;
const int N = 105;

vector <pli>  a, b;

vector <pli> compress(vector <pli> v)
{
  vector <pli> d;
  if (v.size() == 0) return v;
  d.pb(v[0]);
  for (int i = 1; i < v.size(); i++)
    if (d.back().s == v[i].s) d[d.size() - 1].f += v[i].f;
    else d.pb(v[i]);
  return d;
}

ll mx;
void rec(int x, int y, ll sm)
{
  if (x == a.size() || y == b.size())
  {
    mx = max(mx, sm);
    return;
  }
  if (a[x].s == b[y].s)
  {
    ll mv = min(a[x].f, b[y].f);
    a[x].f -= mv;
    b[y].f -= mv;
    if (a[x].f == 0) rec(x + 1, y, sm + mv);
    else rec(x, y + 1, sm + mv);
    a[x].f += mv;
    b[y].f += mv;
  } else
  {
    rec(x, y + 1, sm);
    rec(x + 1, y, sm);
  }
}
ll solve()
{
  int n, m;
  bool use[N] = {0};
  a.clear();
  b.clear();
  cin >> n >> m;
  mx = 0;
  a.resize(n);
  b.resize(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].f >> a[i].s;
    use[a[i].s] = true;
  }
  for (int i = 0; i < m; i++)
    cin >> b[i].f >> b[i].s;
  //for (int i = ds - 1; i >= 0; i--)
    //if (!use[b[i].s]) b.erase(b.begin() + i);
  //a = compress(a);
  //b = compress(b);
  rec(0, 0, 0);
  return mx;
}
int main()
{
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int ts;
  cin >> ts;
  for (int i = 1; i <= ts; i++)
  {
    ll sl = solve();
    cout << "Case #" << i << ": " << sl << endl;
  }

/*
1
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 1
5000000 10
5000000 100

1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1

1
3 100
10000000000000000 1 10000000000000000 2 10000000000000000 3
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
100000000 2 100000000 3 10000 2 10000 1 1000000 2
*/
  return 0;
}
