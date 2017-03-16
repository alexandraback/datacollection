#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_CPS 2.0

int main (int carg, char* args[])
{
  // read and populate data
  int trials;

  double cost;
  double farm_cps;
  int farms;
  double target;

  double current;
  double time;

  fscanf(stdin, "%d", &trials);
  for (int t = 0; t < trials; t++)
  {
    fscanf(stdin, "%lf", &cost);
    fscanf(stdin, "%lf", &farm_cps);
    fscanf(stdin, "%lf", &target);

    time = 0.0;
    farms = 0;
    current = 0.0;

    double cps = BASE_CPS;
    while (current < target)
    {
      double time_farm = (cost - current) / cps;
      double time_target = (target - current) / cps;
      double time_diff = time_target - time_farm;
      double time_add_farm = target / (cps + farm_cps);

      if (time_target < time_farm)
      {
        time += time_target;
        current = target;
      }
      else if (time_diff < time_add_farm)
      {
        time += time_target;
        current = target;
      }
      else
      {
        farms += 1;
        time += time_farm;
        cps += farm_cps;
      }
    }

    printf("Case #%d: %.7f\n", t + 1, time);
  }
}
