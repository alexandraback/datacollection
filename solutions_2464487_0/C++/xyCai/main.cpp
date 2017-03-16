#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

long long r,paint_t,ans;

int main()
{
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cases=1;cases<=t;++cases)
    {
        scanf("%lld%lld",&r,&paint_t);
        double x = -0.5+sqrt(1.0-4*(r-r*r-2.0*paint_t))/2;
        ans = (long long)x;
        ans = (ans-r+1)>>1;
        printf("Case #%d: %lld\n", cases, ans);
    }
    return 0;
}
