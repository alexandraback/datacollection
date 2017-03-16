#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<double> p(a);
        for(double& v : p)
        {
            scanf("%lf", &v);
        }
        
        double prod = accumulate(p.begin(), p.end(), 1.0, std::multiplies<double>());
        double ret = b+2;
        for(int d=0;d<=a;++d)
        {
            int ntype = d + (b - (a - d));
            ret = min(ret, (ntype+1) + (b+1)*(1-prod));
            if (d < a)
            {
                prod /= p[a-d-1];
            }
        }
        
        printf("Case #%d: %.6lf\n", lp, ret);
    }
    return 0;
}