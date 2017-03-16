#include <stdio.h>
#include <math.h>

struct node
{
  double time, pos;
} typedef node;

int N;
node others[2001];

double max(double a, double b)
{
  return (a > b) ? a : b;
}

double calc(double h)
{
  if (N == 1)
  {
    return 0.0;
  }
  else
  {
    double fvel = (others[N - 1].pos - others[N - 2].pos) / (others[N - 1].time - others[N - 2].time);
    return others[N - 2].time + (h - others[N - 2].pos) / fvel;
  }
}

int main()
{
  int t, T, A, i;
  double h;
  scanf("%d", &T);
  for (t = 0; t < T; t++)
  {
    scanf("%lf %d %d", &h, &N, &A);
    for (i = 0; i < N; i++)
      scanf("%lf %lf", &others[i].time, &others[i].pos);
    double vv = calc(h);
    printf("Case #%d:\n", t + 1);
    for (i = 0; i < A; i++)
    {
      double a;
      scanf("%lf", &a);
      printf("%0.7lf\n", max(vv, sqrt(h / (0.5 * a))));
    }
  }
  return 0;
}
