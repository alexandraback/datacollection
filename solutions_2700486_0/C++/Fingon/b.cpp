#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int t;

long double newton(int n, int k, int divsLeft)
{
  long double term = 1;

  for(int s = 0; s < k; s++)
  {
    term *= (n - s)/(static_cast<long double>(s + 1));
    if(term > 2 && divsLeft)
    {
      term /= 2;
      divsLeft--;
    }
  }

  while(divsLeft)
  {
    term /= 2;
    divsLeft--;
  }

  return term;
}

long double solve(int tossCount, int minOnesCount, int maxSameCount)
{
 // printf("toss %d; ones %d; maxsame %d\n", tossCount, minOnesCount, maxSameCount);

  if(minOnesCount * 2 == tossCount && minOnesCount == maxSameCount)
  {
    return 1.0;
  }

  long double res = 0.0;

  for(int i = minOnesCount; i <= min(tossCount, maxSameCount); ++i)
  {
    if(tossCount - i > maxSameCount)
    {
      continue;
    }

    if(tossCount - i == maxSameCount || i == maxSameCount)
    {
    
      long double term = 1;
      for(int n = maxSameCount; n <= tossCount; ++n)
      {
        res += newton(n - 1, maxSameCount - 1, n);
      }


    }
    else
    {
      res += newton(tossCount, i, tossCount);
    }
  }

  return res;
}

int main()
{
  scanf("%d", &t);

  for(int z = 1; z <= t; ++z)
  {
    printf("Case #%d: ", z);
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    int r = 1;
    int sum = 1;
    while(sum + 2*r + 3 <= n)
    {
      sum += 2*r + 3;
      r += 2;
    }

    int k = n - sum;

    x = abs(x);
    if(x + y <= r - 1)
    {
      printf("1.0\n");
    }
    else if(x + y > r + 1)
    {
      printf("0.0\n");
    }
    else
    {
      //k rzutow, musi wypasc przynajmniej x + 1, jedynek
      int ones = y + 1;
      printf("%0.9Lf\n", solve(k, ones, r + 1));
    }

  }

  return 0;
}
