#include <stdio.h>

void solve()
{
  double c,f,x;

  double time = 0;

  double rate = 2.0;
  double num = 0;

  scanf("%lf%lf%lf", &c, &f, &x);

  while (true) {
    double newrate = rate + f;
    double timewithfactory = c / rate + x / (rate + f);
    double timewithout = x / rate;

    if (timewithout <= timewithfactory) {
      time += timewithout;
      break;
    } else {
      time += c / rate;
      rate += f;
    }
  }

  printf("%.7lf\n", time);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    printf("Case #%d: ", t + 1);
    solve();
  }

  return 0;
}
