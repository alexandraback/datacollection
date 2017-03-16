#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

struct Triple
{
  Triple() { }
  Triple(int xx, int yy, ll mmask) : x(xx), y(yy), mask(mmask) { }

  bool operator<(Triple const& other) const
  {
    if (x == other.x)
      return y == other.y ? mask < other.mask : y < other.y;
    return x < other.x;
  }

  int x, y;
  ll mask;
};

int a, b, c, k;
map<Triple, int> M;
map<Triple, int> movement;

ll fix(ll mask, int qtt)
{
  vector<int> v(c);
  for (int i = 0; i < c; ++i)
  {
    v[i] = mask % 11;
    mask /= 11;
  }
  for (int i = 0; i < qtt; ++i)
  {
    if (++v[i] > k)
      return -1;
  }
  sort(v.begin(), v.end(), std::greater<int>());

  ll res = 0;
  for (int i = 0; i < c; ++i)
  {
    res *= 11;
    res += v[i];
  }

  return res;
}

ll fix_mask(ll mask, int qtt, vector<int>& hint)
{
  vector<pair<int, int> > v(c);
  for (int i = 0; i < c; ++i)
  {
    v[i].first = mask % 11;
    v[i].second = hint[i];
    mask /= 11;
  }
  for (int i = 0; i < qtt; ++i)
  {
    if (++v[i].first > k)
      return -1;
  }
  sort(v.begin(), v.end(), std::greater<pair<int, int> >());

  ll res = 0;
  for (int i = 0; i < c; ++i)
  {
    res *= 11;
    res += v[i].first;
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < c; ++i)
    hint[i] = v[i].second;

  return res;
}

ostream& operator<<(ostream& out, Triple t)
{
  out << t.x << " " << t.y << " [";
  for (int i = 0; i < c; ++i)
  {
    out << " " << t.mask % 11;
    t.mask /= 11;
  }
  out << " ]";
  return out;
}

int dp(Triple t)
{
  if (t.x == a + 1)
    return 0;
  if (t.y == b + 1)
    return dp(Triple(t.x + 1, 1, 0));

  map<Triple, int>::iterator it = M.find(t);
  if (it == M.end())
  {
    int res = -1;
    for (int i = 0; i <= min(k, c); ++i)
    {
      ll new_mask = fix(t.mask, i);
      if (new_mask >= 0)
      {
        int candidate = dp(Triple(t.x, t.y + 1, new_mask)) + i;
        if (candidate > res)
        {
          //cerr << t << endl;
          //cerr << " " << i << " " << Triple(t.x, t.y + 1, new_mask) << endl;
          res = candidate;
          movement[t] = i;
        }
      }
    }
    M[t] = res;
    return res;
  }
  return it->second;
}

void print_solution(Triple t, vector<int>& hint)
{
  if (t.x == a + 1)
    return;
  if (t.y == b + 1)
  {
    for (int i = 1; i <= c; ++i)
      hint[i - 1] = i;
    print_solution(Triple(t.x + 1, 1, 0), hint);
    return;
  }
  
  int best = movement[t];
  for (int i = 0; i < best; ++i)
    cout << t.x << " " << t.y << " " << hint[i] << endl;

  ll mask = fix_mask(t.mask, best, hint);
  print_solution(Triple(t.x, t.y + 1, mask), hint);
}

void solve()
{
  cin >> a >> b >> c >> k;
  M.clear();
  movement.clear();

  cout << dp(Triple(1, 1, 0)) << endl;
  vector<int> hint(c);
  for (int i = 1; i <= c; ++i)
    hint[i - 1] = i;
  print_solution(Triple(1, 1, 0), hint);
}

int main()
{
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas)
  {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
