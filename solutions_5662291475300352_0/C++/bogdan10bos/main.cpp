#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

#define eps 0.001

using namespace std;
int n, t, cs, x, y, z, m, mn, nr, a, b;
double sp1, sp2, sp3;


bool intersect(int poz1, double sp1, int poz2, double sp2)
{
    if(poz1 > poz2)
    {
        double m = (double)(360 - poz1) / sp1;

        double m1 = (double)(360 - poz2) / sp2;
        double m2 = (double) (720 - poz2) / sp2;

        if(m1 < m && m < m2)
            return false;
        return true;
    }
    else
    {
        double m = (double)(360 - poz1) / sp1;

        double m1 = (double)(360 - poz2) / sp2;

        if(m < m1)
            return false;
        return true;
    }
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        scanf("%d", &n);
        if(n == 1)
        {
            scanf("%d%d%d", &x, &mn, &nr);
            if(nr == 1)
            {
                printf("0\n");
                continue;
            }
            y = x;
            sp1 = (double) mn / (double) 360;
            sp2 = (double) (mn + 1) / (double) 360;
        }
        else
        {
            scanf("%d%d%d", &x, &mn, &nr);
            sp1 = (double) mn / (double) 360;

            scanf("%d%d%d", &y, &mn, &nr);
            sp2 = (double) mn / (double) 360;
        }


        if(x < y)
        {
            if(intersect(y, sp2, x, sp1))
                a = intersect(y - 1, sp2, y, sp1);
            a = intersect(x - 1, sp1, y, sp2);
        }
        else
        {
            if(intersect(x, sp1, y, sp2))
                a = intersect(x - 1, sp1, x, sp2);
            a = intersect(y - 1, sp2, x, sp1);
        }

        if(a)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
