#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define MP make_pair
#define PB push_back

const int V = 2100;

int n, m;
double D;
double t[V], x[V];

const double eps = 1e-8;

double solveEqu(double A,double B,double C) {
    return -B + sqrt(B*B - 4*A*C);
}
void solve(double limit)
{
    if (n == 1) {
        printf("%.8f\n",sqrt(2*D / limit));
        return;
    }
    double Snow = 0, Vnow = 0, Tnow = 0;
    bool Over = false;
    for (int i=0;i<n-1 && !Over;i++)
    {
        if (x[0] > D) break;
        if (x[i+1] > D) {
            double otherV = (x[i+1] - x[i]) / (t[i+1] - t[i]);
            x[i+1] = D;
            t[i+1] = t[i] + (D - x[i]) / otherV;
            Over = true;
        }
        double deltaT = t[i+1] - t[i];
        double deltaS = x[i+1] - Snow;
        
        double V1 = deltaS * 2 / deltaT - Vnow;
        double a = (V1 - Vnow) / deltaT;
        
        if (a < limit) {
            Vnow = V1;
            Snow = x[i+1];
        }else
        {
            Snow = Snow + Vnow * deltaT + 0.5 * limit * deltaT * deltaT;
            Vnow = Vnow + deltaT * limit;
        }
        Tnow = t[i+1];
    }
    if (fabs(Snow-D) < eps) {
        printf("%.8f\n",Tnow);
    }else
    {
        double leftT = solveEqu(0.5 * limit, Vnow, -(D-Snow));
        printf("%.8f\n",Tnow + leftT);
    }
}
double limit[2000];
int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%lf%d%d",&D, &n, &m);
        for (int i=0;i<n;i++) scanf("%lf%lf",&t[i],&x[i]);
        
        
        if (n > 1)
        {
            double deltaV = (x[n-1] - x[n-2]) / (t[n-1] - t[n-2]);
            if (x[n-1] > D) {
                x[n-1] = D;
                t[n-1] = t[n-2] + (D - x[n-2]) / deltaV;
            }
        }
        
        
        for (int i=0;i<m;i++) 
        {
            scanf("%lf",&limit[i]);
        }
        printf("Case #%d:\n",cas);
        for (int i=0;i<m;i++)
            solve(limit[i]);
    }
}

