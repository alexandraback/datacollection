#include <cstdio>
#include <algorithm>

using namespace std;

#define small
//#define large

int t, x, r, c;

bool isAns() {
  if (x < 3)
    return r * c % x;
  if (x == 3) {
    if (r * c % x == 0 && min(r, c) >= 2)
      return false;
    return true;
  }
  if (r * c % x == 0 && min(r, c) >= 3)
    return false;
  return true;
}

int main()
{
#ifdef small
  freopen("small.in", "r", stdin);
  freopen("small.out", "w", stdout);
#endif
#ifdef large
  freopen("large.in", "r", stdin);
  freopen("large.out", "w", stdout);
#endif

  scanf("%d", &t);
  for (int Case = 1; Case <= t; ++Case) {
    scanf("%d %d %d", &x, &r, &c);
    printf("Case #%d: %s\n", Case, isAns() ? "RICHARD" : "GABRIEL");
  }
  return 0;
}
