/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.11
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
  long long a, b;
  scanf("%I64d/%I64d", &a, &b);

  long long g = __gcd(a, b);
  a /= g, b /= g;
  if (b & (b - 1))
  {
    puts("impossible");
    return;
  }

  int x = 0;
  while (a < b)
    a <<= 1, x++;
  printf("%d\n", x);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(i, tn)
  {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
