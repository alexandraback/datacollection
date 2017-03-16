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

void test_case(int test_no) {
  int a, b;
  scanf("%d%d", &a, &b);

  double ans = b + 2;
  double p = 1;
  for (int k = a; k >= 0; --k) {
    double len = p * (2 * k + b - a + 1) + (1 - p) * (2 * (k + b) - a + 2);
    ans = min(ans, len);
    if (k != 0) {
      double factor;
      scanf ("%lf", &factor);
      p *= factor;
    }
  }

  printf("Case #%d: %.10f\n", test_no, ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ++ti) {
    test_case(ti + 1);
  }
  return 0;
}
