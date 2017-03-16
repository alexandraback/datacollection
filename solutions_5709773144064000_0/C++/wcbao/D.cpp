#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#define mm 1000005
using namespace std;
typedef long long LL;
typedef pair<int,int > P;
const int mod = 1000003;

int main()
{
   freopen("BUAA.in","r",stdin);
   freopen("B.out","w",stdout);
    int T,c = 0;
    double C,F,X;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d: ",++c);
        scanf("%lf%lf%lf",&C,&F,&X);
        double t = 0.0, rate = 2.0;
        double R = X*F/C-F;
        while(R>rate){
            t += C/rate;rate += F;
        }
        t += X/rate;
        printf("%.7lf\n",t);
    }
    return 0;
}
