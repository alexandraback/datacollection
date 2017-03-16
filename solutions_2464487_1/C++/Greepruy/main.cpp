#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const long double epx=0.000001;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    long double rr,t;
    for(int ci=1;ci<=cas;ci++)
    {
       //scanf("%lf%lf",&rr,&t);
       cin >> rr >> t;
       long double l=1;
       long double r=t;
       long double mid=(l+r)/2;
       while(l+epx<r)
       {
           //cout << l << ' ' << r << endl;
           if((2*rr+2*mid-1)*mid>t) r=mid;
           else l=mid;
           mid=(l+r)/2;
       }
       //cout << l << endl;
       long long ans=floor(l);
       while((2*rr+2*(ans+1)-1)*(ans+1)>=0 && (2*rr+2*(ans+1)-1)*(ans+1)<=t) ans++;
       printf("Case #%d: %lld\n",ci,ans);
    }
}
