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

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void testCase()
{
  ll p, q;
  char delim;
  cin >> p >> delim >> q;
  cerr << p << " " << q << endl;

  ll d = gcd(p, q);
  p /= d, q /= d;
  assert(1 <= p && p < q);

  int deg = 1;
  for (deg = 1; deg <= 40; deg++)
    if (q == (1LL << deg))
      break;
  if (deg > 40)
  {
    printf("impossible\n");
    return;
  }

  p *= (1LL << 40) / q;
  cerr << "p = " << p << endl;
  int ans = 40;
  while (p >= 2)
  {
    p /= 2;
    ans--;
  }
  printf("%d\n", ans);
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
//    cout << "Case #" << t << ": ";
    printf("Case #%d: ", t);
    testCase();
  }
  return 0;
}
