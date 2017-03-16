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
int t, r = 100, m = 5, n = 3, k = 7, sets[8];
bool check(int a[3])
{
  set <int> s;
  s.insert(1);
  s.insert(a[0]);s.insert(a[1]);s.insert(a[2]);
  s.insert(a[0] * a[1]);s.insert(a[0] * a[2]);s.insert(a[1] * a[2]);
  s.insert(a[0] * a[1] * a[2]);
  for (int i = 0; i < k; ++i)
    if (s.find(sets[i]) == s.end()) return false;
  return true;
}

void solve()
{
  for (int i = 0; i < k; ++i) cin >> sets[i];
  for (int i = 2; i <= m; ++i)
    for (int j = 2; j <= m; ++j)
      for (int k = 2; k <= m; ++k)
      {
        int a[3] = {i, j, k};
        if (check(a))
        {
          cout << a[0] << a[1] << a[2] << endl;
          return;
        }
      }
}
int main()
{
  freopen("C-small-1-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  cout << "Case #1: \n";
  for (int i = 1; i <= r; ++i) solve();
  return 0;
}
