#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
  if (!b)
    return a;
  return gcd(b, a % b);
}

int iscase(int p, int q)
{
  int cnt = 0;
  float x = p;
  q = q / 2;
  while (((x / (q * 1.0)) - 1.0) < 0.0)
  {
    q = q / 2;
    cnt++;
  }

  return cnt + 1;
}

int ispow2(int a)
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
  int val;
  int p, q;
  int g;
  int h = 1;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d/%d", &p, &q);
    g = gcd(p, q);
    p /= g;
    q /= g;
    val = ispow2(q);
    if (val == -1)
      printf ("Case #%d: impossible\n", h++);
    else {
      val = iscase(p, q);
      printf ("Case #%d: %d\n", h++, val);
    }
  }

  return 0;
}
