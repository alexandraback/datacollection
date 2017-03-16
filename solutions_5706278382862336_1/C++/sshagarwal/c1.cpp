#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b)
{
  if (!b)
    return a;
  return gcd(b, a % b);
}

long long iscase(long p, long q)
{
  long long cnt = 0;
  long double x = p;
  q = q / 2;
  while (((x / (q * 1.0)) - 1.0) < 0.0)
  {
    q = q / 2;
    cnt++;
  }

  return cnt + 1;
}

long long ispow2(long long a)
{
  int cnt = 0;
  while (a > 1) {
    if (a % 2 == 1)
      return -1;
    a = a / 2;
    cnt++;
  }

  return cnt;
}

int main ()
{
  int t;
  long long val;
  long long p, q;
  long long g;
  int h = 1;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%lld/%lld", &p, &q);
    g = gcd(p, q);
    p /= g;
    q /= g;
    val = ispow2(q);
    if (val == -1)
      printf ("Case #%d: impossible\n", h++);
    else {
      val = iscase(p, q);
      printf ("Case #%d: %lld\n", h++, val);
    }
  }

  return 0;
}
