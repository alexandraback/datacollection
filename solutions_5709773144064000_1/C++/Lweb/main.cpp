#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        double C,F,X;
        scanf("%lf%lf%lf",&C,&F,&X);
        double ans=1e18;
        double tt=0,rat=2;
        while(1)
        {
            if(tt>ans) break;
            ans=min(ans,tt+X/rat);
            double t=C/rat;
            tt+=t;
            rat+=F;
        }
        printf("Case #%d: %.7f\n",ca,ans);
    }
    return 0;
}

