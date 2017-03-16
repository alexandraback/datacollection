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

double calc(double h, double a)
{
  int i;
  double pos = 0.0, vel = 0.0, atime = 0.0, timetk = 0.0;
  for (i = 1; i < N - 1; i++)
  {
    double dt = others[i].time - atime;
    double dx = vel*dt + 0.5*dt*dt*a;
    double dv = dt*a;
    pos += dx;
    vel += dv;
    if (pos + dx > others[i].pos)
    {
      pos = others[i].pos;
      vel = (others[i].pos - others[i - 1].pos) / (dt);
    }
    timetk += dt;
    atime += dt;
  }
  double fvel = (others[N - 1].pos - others[N - 2].pos) / (others[N - 1].time - others[N - 2].time);
  double dto = (others[N - 1].pos - h) / fvel;
  double delta = vel*vel + 4 * ((a / 2) * (h - pos));
  double dts = ((vel + sqrt(delta)) / a);
  return timetk + max(dto, dts);
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
    printf("Case #%d:\n", t + 1);
    for (i = 0; i < A; i++)
    {
      double a;
      scanf("%lf", &a);
      printf("%0.7lf\n", calc(h, a));
    }
  }
  return 0;
}
