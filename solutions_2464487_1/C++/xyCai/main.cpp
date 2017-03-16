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
//    freopen("A-large.in","r",stdin);
//    freopen("A-large2.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cases=1;cases<=t;++cases)
    {
        scanf("%lld%lld",&r,&paint_t);
        long long left_x = 0;
        long long right_x = 2e18;

        while(left_x < right_x)
        {
            long long mid = (left_x+right_x+1)>>1;
            if (2*r+(2*mid-1) <= paint_t*1.0/mid)
                left_x = mid;
            else
                right_x = mid-1;
        }
        printf ("Case #%d: %lld\n",cases,left_x);
    }
    return 0;
}
