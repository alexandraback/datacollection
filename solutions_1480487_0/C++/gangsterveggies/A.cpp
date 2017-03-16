#include <stdio.h>

#define MAX 500

double list [MAX];

double max(double a, double b)
{
  return (a > b) ? a : b;
}

int main()
{
  int n, t, T, i;
  scanf("%d", &T);
  for (t = 0; t < T; t++)
  {
    scanf("%d", &n);
    int sum = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%lf", &list[i]);
      sum += (int)list[i];
    }
    double a = (2.0 / n) * sum, ns;
    int nt = n, flag = 1;
    while (flag)
    {
      flag = 0;
      ns = 0.0;
      for (i = 0; i < n; i++)
      {
        if ((a - list[i]) / sum < 0)
        {
          nt--;
          ns += list[i];
          list[i] = -1;
          flag = 1;
        }
      }
      if (ns > 0)
      {
        for (i = 0; i < n; i++)
          if (list[i] != -1)
            list[i] += ns / nt;
      }
      a = (2.0 / nt) * sum;
    }

    printf("Case #%d: ", t + 1);
    for (i = 0; i < n - 1; i++)
    {
      if (list[i] != -1)
        printf("%lf ", 100 * ((a - list[i]) / (double)sum));
      else
        printf("0.0 ");
    }
    if (list[n - 1] != -1)
      printf("%lf\n", 100 * ((a - list[n - 1]) / (double)sum));
    else
      printf("0.0\n");
  }
  return 0;
}
