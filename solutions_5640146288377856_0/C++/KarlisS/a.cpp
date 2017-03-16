#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int r, int c, int w)
{
    if (w == c) return w;
    if (w == 1)
    {
        return (c+5)/3;
    }
    return (c+((w+2)*(w+2)-2-2*w))/(w+2);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int nt=1; nt<=t; nt++)
    {
        int r, c, w;
        scanf("%d %d %d", &r, &c, &w);
        printf("Case #%d: ", nt);
        printf("%d\n", solve(r, c, w));
    }
    return 0;
}
