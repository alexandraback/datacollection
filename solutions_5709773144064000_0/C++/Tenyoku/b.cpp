#include <cstdio>

double c, f, x;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%lf %lf %lf", &c, &f, &x);
        double ans = 0;
        double speed = 2;
        while((x-c)/speed*f > c)
        {
            ans += c/speed;
            speed += f;
        }
        ans += x/speed;
        printf("Case #%d: %.7f\n", cas, ans);
    }
    return 0;
}
