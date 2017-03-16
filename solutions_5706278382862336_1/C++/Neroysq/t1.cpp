#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long p, q;

long long gcd(long long a, long long b)
{
  return !b ? a : gcd(b, a % b);
}

int get(long long p, long long q, int k)
{
  if (k > 40) return 41;
  p <<= 1;
  if (p >= q) return k;
  return get(p, q, k + 1);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    printf("Case #%d: ", cases);
    scanf("%I64d/%I64d", &p, &q);
    long long d = gcd(p, q);
    p /= d;
    q /= d;
    if (p == 0) {
      printf("impossible\n");
      continue;
    }
    long long k = 1, l = 0;
    while (k < q) k <<= 1, ++l;
    if (k != q || l > 40) {
      printf("impossible\n");
      continue;
    }
    int ans = get(p, q, 1);
    if (ans <= 40)
      printf("%d\n", ans);
    else
      printf("impossible\n");
  }
  return 0;
}

