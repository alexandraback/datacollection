#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    int T;
    double c, f, x;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%lf %lf %lf", &c, &f, &x);
        double res = 0, t = 0, speed = 2.0;
        while (x/speed > x/(speed + f) + c/speed)
        {
            t += c/speed;
            speed += f;
        }
        t += x/speed;
        printf("Case #%d: %.7lf\n", cas, t);
    }
    return 0;
}
