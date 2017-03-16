#include <stdio.h>

void problem(void);

int main(int argc, char *argv[])
{
    int total, t;
    scanf("%d", &total);
    for (t = 0; t < total; ++t)
    {
        printf("Case #%d: ", t+1);
        problem();
    }
    return 0;
}

/*
 *int stay(int c, int x, int speed, int f)
 *{
 *    double t1 = (x - c) / speed;
 *    double t2 = x / (speed + f);
 *    return t1 < t2;
 *}
 */

void problem(void)
{
    double c, f, x;
    double speed = 2;
    double time, new_time, t = 0;
    scanf("%lf", &c);
    scanf("%lf", &f);
    scanf("%lf", &x);

    time = x / speed;
    while (1) {
        t += c / speed;
        if (t > time)
            break;
        speed += f;
        new_time = x / speed + t;
        if (new_time < time)
        {
            time = new_time;
        }
    }
    printf("%.7lf\n", time);
}
