#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long p10[16];

long long rev (long long i)
{
  long long ret = 0;
  while (i > 0)
  {
    ret = ret * 10 + i % 10;
    i /= 10;
  }
  return ret;
}

int digits (long long n)
{
  int res = 0;
  while (n > 0)
    n /= 10, res++;
  return res;
}
long long ans (long long n)
{
//  printf ("  %d", (int) n);
  if (n <= 10)
    return n-1;
  int d = digits(n);
  long long next = n / p10 [(d+1)/2] * p10 [(d+1)/2] + 1;
  if (next > n || (next == n && rev(n) == n))
  {
//    printf ("(-1)");
    return ans (n - 1) + 1;
  }
//  printf ("(-%d -> %d)", (int) (n-next), (int) next);
  return ans (rev(next)) + n - next + (rev(next) != next);
}              
int main (void)
{
  int i, test, tests;
  p10[0] = 1;
  for (i = 1; i < 16; i++)
    p10[i] = p10[i-1] * 10;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    long long n;
    scanf ("%I64d", &n);
    printf ("Case #%d: %I64d\n", test + 1, ans(n) + 1);
  }
  return 0;
}
