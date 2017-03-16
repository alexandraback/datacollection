#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double dbl;

void testCase()
{
  int n, x, y;
  cin >> n >> x >> y;
  if (x < 0)
    x = -x;
  assert(x >= 0 && y >= 0);
  if (n == 1)
  {
    cout << ((x == 0 && y == 0) ? "1.0" : "0.0") << endl;
    return;
  }
  int k = 1;
  for (; 4 * k - 3 < n; k++)
    n -= 4 * k - 3;
  //cerr << k << " " << n << endl;
  assert(0 < n && n <= 4 * k - 3);
  
  int s = 2 * k - 2;
  assert(n <= 2 * s + 1);

  if (x + y != s)
  {
    cout << ((x + y < s) ? "1.0" : "0.0") << endl;
    return;
  }

  if (n == 2 * s + 1)
  {
    cout << "1.0" << endl;
    return;
  }

  if (y == s)
  {
    cout << "0.0" << endl;
    return;
  }

  vector<dbl> p0(s + 1, 0), p1(s + 1, 0);
  p0[0] = 1;

  for (int i = 0; i < n; i++)
  {
    int mj = min(i + 1, s);
    for (int j = 0; j <= mj; j++)
    {
      if (j < s && i - j < s)
        p1[j] = p0[j] * 0.5;
      else if (j >= s)
        p1[j] = p0[j];
      else
        p1[j] = 0;

      if (j > 0)
      {
        if (i - (j - 1) < s)
          p1[j] += p0[j - 1] * 0.5;
        else
          p1[j] += p0[j - 1];
      }
    }
    p0.swap(p1);
  }
  assert(0 <= y && y < sz(p0));
  dbl ans = 0;
  for (int i = sz(p0) - 1; i > y; i--)
    ans += p0[i];
  //cout << " ## ";
  cout.precision(20);
  cout << fixed << ans << endl;
}

int main() {
//  freopen("sample.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int n;
  cin >> n;
  for (int ti = 0; ti < n; ++ti) {
    cout << "Case #" << (ti + 1) << ": ";
    testCase();
  }
  return 0;
}
