#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int T;
double a, c, f, x, sec;

void solve()
{
    while(1.*(x-c)/a > 1.*x/(a+f))
    {
        sec += 1.*c/a;
        a += f;
    }
    sec += 1.*x/a;
    printf("%.7lf\n", sec);
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        scanf("%lf%lf%lf", &c, &f, &x);
        a = 2;
        sec = 0;
        solve();
    }
    return 0;
}
