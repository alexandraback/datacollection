#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    long long rr,t;
    for(int ci=1;ci<=cas;ci++)
    {
       scanf("%lld%lld",&rr,&t);
       long long l=1;
       long long r=t;
       long long mid=(l+r)/2;
       while(l+1<r)
       {
           //cout << l << ' ' << r << endl;
           if((2*rr+2*mid-1)*mid>t) r=mid-1;
           else l=mid;
           mid=(l+r)/2;
       }
       if((2*rr+2*(l+1)-1)*(l+1)<=t)l++;
       printf("Case #%d: %lld\n",ci,l);
    }
}
