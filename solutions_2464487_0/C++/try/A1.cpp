#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int c,t;
    long long r,s,low,hig,mid;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%I64d %I64d",&r,&s);
        low=0;
        hig=min(s/r,(long long)sqrt(s+0.5));
        while(low<hig)
        {
            mid=(low+hig+1)/2;
            if(2*r*mid+2*mid*mid-mid<=s)
            {
                low=mid;
            }
            else
            {
                hig=mid-1;
            }
        }
        printf("Case #%d: %I64d\n",c+1,low);
    }
    return 0;
}
