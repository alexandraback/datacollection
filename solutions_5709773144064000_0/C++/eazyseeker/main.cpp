#include <cstdio>

using namespace std;

int t;
double farmCost, farmBoost, goal;
double cookies;
double rate;
double time;
double timeToFarm;
double timeToGoalBoosted;
double timeToGoal;

double timeTo(double currentCookies, double currentRate, double currentGoal)
{
    return ((currentGoal - currentCookies) / currentRate);
}
int main()
{
    freopen("cc.in", "r", stdin);
    freopen("cc.out", "w", stdout);

    int i;

    scanf("%d", &t);

    for (i = 1; i <= t; i++)
    {
        scanf("%lf%lf%lf", &farmCost, &farmBoost, &goal);

        cookies = 0;
        time = 0;
        rate = 2;

        while ( (timeToFarm=timeTo(cookies, rate, farmCost)) + (timeToGoalBoosted=timeTo(0, rate+farmBoost, goal)) < (timeToGoal=timeTo(cookies, rate, goal)))
        {
            time += timeToFarm;
            rate += farmBoost;
            cookies = 0;
        }

        time += timeToGoal;

        printf("Case #%d: %lf\n", i, time);

    }
    return 0;
}
