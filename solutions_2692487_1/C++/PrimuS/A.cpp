#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <set>

using namespace std;
long long a[1000];
long long best[1000];

int main()
{
  freopen("D:\\codejam\\A-large.in", "r", stdin);
  freopen("D:\\codejam\\alargeout.txt", "w", stdout);

  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t)
  {
    memset(a, 0, sizeof(a));
    memset(best, 0, sizeof(best));
    long long  A, n;
    scanf("%lld%lld", &A, &n);

    for (int i = 0; i < n;++i)
      scanf("%lld", &a[i]);

    if (A == 1)
    {
      printf("Case #%d: %d\n", t + 1, n);
      continue;
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
      if (A > a[i])
      {
        A += a[i];
        if (i > 0)
          best[i] = best[i-1];
      }
      else
      {
        long long k = a[i] - A + 1;
        long long u = 0;
        //long long u = k / (A - 1);
        //if (k != u * (A - 1))
        //  ++u;
        //A = A + u * (A - 1) + a[i];
        while (A <= a[i])
        {
          A = A + A - 1;
          ++u;
        }
        A += a[i];
        if (i > 0)
          best[i] = best[i-1] + u;
        else
          best[i] = u;
      }
    }

    int res = n;
    for (int i = 0; i < n; ++i)
    {
      if (best[i] + (n - i - 1) < res)
        res = best[i] + (n - i - 1);
    }

    printf("Case #%d: %d\n", t + 1, res);
  }

  fclose(stdout);
  return 0;
};