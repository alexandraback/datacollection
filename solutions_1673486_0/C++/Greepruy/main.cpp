#include <iostream>
#include <stdio.h>
using namespace std;
int a,b;
double data[101000];
double p[101000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    //cout << cas << endl;
    int ci;
    int a,b;
    int i;
    double ans;
    for(ci=1;ci<=cas;ci++)
    {
       scanf("%d%d",&a,&b);
       ans=b+2;//3
       data[0]=1;
       for(i=1;i<=a;i++)
       {
           scanf("%lf",&p[i]);
           //cout << p[i] << ' ' << i << endl;
           //cout << data[i] << endl;
           data[i]=p[i]*data[i-1];
           //allright*=p[i];
       }
       //mayrong=1-allright;
       //ans=min(ans,(b-a+1)*allright+(b-a+1+b+1)*mayrong);
       for(i=a;i>=0;i--)
       {
           ans=min(ans,data[i]*(b-i+1+a-i)+(1-data[i])*(b-i+1+a-i+b+1));
       }
       printf("Case #%d: %.6lf\n",ci,ans);
    }
    return 0;
}
