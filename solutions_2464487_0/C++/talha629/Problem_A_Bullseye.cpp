#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    long long a,b,r,t,x,c;
    int T=1,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&r,&t);
        c=1;
        a=r*r;
        r++;
        b=r*r;
        t-=(b-a);
        while(t>0)
        {
            a=b;
            r++;
            b=r*r;

            a=b;
            r++;
            b=r*r;
            t-=(b-a);
            if(t>=0)
                c++;


        }
        printf("Case #%d: %lld\n",T++,c);
    }
    return 0;
}
