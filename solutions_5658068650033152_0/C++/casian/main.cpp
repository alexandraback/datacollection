#include<cstdio>

using namespace std;

int solve(int n, int m, int k)
{
  int i, j, min, x;
  min = k;
  if(k <= 4)
    return k;
  for(i = 1; i <= n; ++ i)
    for(j = 1; j <= m; ++ j)
    {
      if(i * j - 4 >= k)
        x = 0;
      else
        x = k - i * j + 4;
      if(min > i + i + j + j - 8 + x)
        min = i + i + j + j - 8 + x;
    }
  return min;
}

int main()
{
  int t, i, n, m, k, j, cn, cm;
  scanf("%d", &t);
  for(i = 1; i <= t; ++ i)
  {
    scanf("%d%d%d", &n, &m, &k);
    if(n <= 2 || m <= 2)
      printf("Case #%d: %d\n", i, k);
    else
      printf("Case #%d: %d\n", i, solve(n, m, k));
  }
  return 0;
}
