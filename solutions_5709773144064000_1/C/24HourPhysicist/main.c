#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Google Code Jam
Qualification 2014
Problem B. Cookie Clicker Alpha
*/

#define TRUE 1
#define FALSE 0

#define INITIAL_RATE 2

int Should_Buy_Farm(double farm_cost, double farm_rate, double cookie_goal, double current_rate)
{
  //time required at current rate, with enough cookies to buy a farm
  double t_current;
  //time required if I buy a new farm, and start from 0
  double t_new;

  t_current = (cookie_goal - farm_cost) / current_rate;
  t_new = (cookie_goal) / (current_rate + farm_rate);

  if (t_new < t_current) {
    return TRUE;
  }
  return FALSE;
}

void Run(int c)
{
  double farm_cost, farm_rate, cookie_goal;
  double t_total, current_rate;

  t_total = 0;
  current_rate = INITIAL_RATE;

  scanf("%lf", &farm_cost);
  scanf("%lf", &farm_rate);
  scanf("%lf", &cookie_goal);

  while(Should_Buy_Farm(farm_cost, farm_rate, cookie_goal, current_rate))
  {
    t_total += (farm_cost)/(current_rate);
    //    fprintf(stderr);
    current_rate += farm_rate;
  }
  t_total += (cookie_goal)/(current_rate);

  fprintf(stdout, "Case #%d: %.7lf\n", c, t_total);
}


int main() {
  int T;
  int i;
  scanf("%d", &T);

  for(i=1;i<=T;i++){
    Run(i);
  }
  return 0;
}
