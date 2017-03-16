#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;

int solve(int h, int n, int k)
{
  if (n == k)
    return k;
  if (n < k)
    return 0;
  if (n % k == 0)
    return n / k * h + (k - 1);

  int res = (n - k) / k * h;
  n = k + n % k;
  assert(k + 1 <= n && n < 2 * k);

  cerr << res << " " << n << endl;
  return res + h + k;
}

void testCase()
{
  int len, w, h;
  scanf("%d%d%d", &h, &w, &len);

  printf("%d\n", solve(h, w, len));
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
//  cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
//    cout << "Case #" << t << ": ";
    printf("Case #%d: ", t);
    testCase();
  }
  return 0;
}
