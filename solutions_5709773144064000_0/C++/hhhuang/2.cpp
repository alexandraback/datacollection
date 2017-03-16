#include <stdio.h>
#include <string.h>

double test2(double price, double rate_inc, double goal) {
    double rate = 2.0;
    double time = 0;
    double min = -1;
    int ans;

    for (int num_farms = 0; num_farms < 100000000; ++num_farms) {
        double t = time + (goal / rate);
        if (min == -1 || min > t) {
            ans = num_farms;
            min = t;
        }
        else if (min < t) {
            break;
        }
        time += price / rate;
        rate += rate_inc;
    }
    return min;
}


double test(double price, double rate_inc, double goal, int num_farms) {
    double rate = 2.0;
    double time = 0;

    while (num_farms > 0) {
        time += price / rate;
        rate += rate_inc;
        --num_farms;
    }
    time += goal / rate;
    return time;
}

void run() {
    double c, f, x;
    double t;
    double min = -1;
    int ans;
    scanf("%lf%lf%lf", &c, &f, &x);
    min = test2(c, f, x);
    printf("%.7lf\n", min);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}
