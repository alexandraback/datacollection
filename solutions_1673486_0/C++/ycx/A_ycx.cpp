#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int n, m, t;
double a[300000];

int main()
{
//    freopen("A-small-attempt1.in", "r", stdin);
//    freopen("output.txt", "w", stdout);
  
    int i;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%d%d", &n, &m);
        int j;
        for (j = 0;j < n;j++)
            scanf("%lf", a + j);
        double p;
        double ans = m + 2;
        for (j = 0;j <= n;j++)
        {
            if (j == 0)
                p = 1;
            else
                p *= a[j-1];
            double res = p*(n+m-2*j+1) +(1-p)*(n+2*m-2*j+2);
            ans = min(ans, res);
        }
        printf("Case #%d: %.6f\n", i, ans);
    }
}


