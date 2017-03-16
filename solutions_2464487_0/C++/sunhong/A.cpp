#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef __int64 LL;
const double PI=acos(-1.0);

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_output_small.txt","w",stdout);
    int T;
    double r,t;
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%lf%lf",&r,&t);
        LL low=0;
        LL high=(LL)floor(t/(2.0*r+1));
        LL result=0;
        while (low<=high)
        {
            LL mid=low+(high-low)/2;
            double v=mid*(2.0*r+2.0*mid-1.0);
            if (v<=t)
            {
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        printf("Case #%d: %I64d\n",cases,result);
    }
    return 0;
}
