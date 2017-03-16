#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long count(long long a, long long b, long long k, int depth)
{
//  fprintf(stderr, "%d, %d, %d, %d\n", a, b, k, depth);
  int cur = 1 << depth;
  if (k == 0) return (a + 1) * (b + 1);
  if ((a < cur) && (b < cur))
    return count(a, b, k, depth - 1);
  if (k & cur)
  {
    if ((a & cur) == 0) return 0;
    if ((b & cur) == 0) return 0;
    if (depth > 0)
      return count(a & (cur - 1), b & (cur - 1), k & (cur - 1), depth - 1);
    else
      return 1;
  }
  else
  {
    if (depth > 0)
    {
      long long ret = 0;
      if (((a & cur) == 0) && ((b & cur) == 0))
        ret += count(a, b, k, depth - 1);
      if (((a & cur) != 0) && ((b & cur) == 0))
      {
        ret += count(cur - 1, b, k, depth - 1);
        ret += count(a - cur, b, k, depth - 1);
      }
      if (((a & cur) == 0) && ((b & cur) != 0))
      {
        ret += count(a, cur - 1, k, depth - 1);
        ret += count(a, b - cur, k, depth - 1);
      }
      if (((a & cur) != 0) && ((b & cur) != 0))
      {
        ret += count(cur - 1, cur - 1, k, depth - 1);
        ret += count(a - cur, b - cur, 0, depth - 1);
        ret += count(cur - 1, b - cur, k, depth - 1);
        ret += count(a - cur, cur - 1, k, depth - 1);
      }
      return ret;
    }
    else
    {
      long long ret = 0;
      if (((a & cur) == 0) && ((b & cur) == 0))
        ret += 1;
      if (((a & cur) != 0) && ((b & cur) == 0))
      {
        ret += 2;
      }
      if (((a & cur) == 0) && ((b & cur) != 0))
      {
        ret += 2;
      }
      if (((a & cur) != 0) && ((b & cur) != 0))
      {
        ret += 4;
      }
      return ret;
    }
  }
}

int main()
{
  int cases;
  cin >> cases;
  for (int t = 1; t <= cases; ++t)
  {
    printf("Case #%d: ", t);
    long long a, b, k;
    cin >> a >> b >> k;
    long long ans = a * b;
    ans -= count(a - 1, b - 1, k, 31);

    printf("%lld\n", ans);
  }
  return 0;
}
