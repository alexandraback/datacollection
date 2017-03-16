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

void testCase()
{
  ll w;
  int n;
  cin >> w >> n;
  vector<int> m(n);
  for (int i = 0; i < n; i++)
    cin >> m[i];
  if (w == 1)
  {
    cout << n << endl;
    return;
  }
  assert(n > 0);

  sort(all(m));
  int ans = n, cur = 0;
  for (int i = 0; i < n; i++)
  {
    ans = min(ans, cur + n - i);
    while (w <= m[i])
    {
      w += w - 1;
      cur++;
    }
    w += m[i];
  }
  ans = min(ans, cur);
  cout << ans << endl;
}

int main() {
//  freopen("sample.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int n;
  cin >> n;
  for (int ti = 0; ti < n; ++ti) {
    printf("Case #%i: ", ti + 1);
    testCase();
  }
  return 0;
}
