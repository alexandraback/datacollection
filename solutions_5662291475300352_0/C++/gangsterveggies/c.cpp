#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int main()
{
  int i;
  int t, T;

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int n, ans = 0;
    scanf("%d", &n);
    double a0, t0, a1, t1;

    if (n == 1)
    {
      scanf("%lf %*d %lf", &a0, &t0);
      a1 = a0;
      t1 = t0 + 1;
    }
    else
    {
      scanf("%lf %*d %lf", &a0, &t0);
      scanf("%lf %*d %lf", &a1, &t1);
    }

    t0 = 360 / t0;
    t1 = 360 / t1;

    if (t1 < t0)
    {
      swap(t0, t1);
      swap(a0, a1);
    }

    double vl0 = (360 - a0) / t0;
    double vl1 = (2 * 360 - a1) / t1;

    if (vl1 <= vl0)
      ans = 1;

    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}
