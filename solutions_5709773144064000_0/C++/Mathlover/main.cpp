#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        double c,f,x;
        scanf("%lf%lf%lf",&c,&f,&x);
        if(x<=c)
        {
            printf("Case #%d: %.7lf\n",++ca,x/2);
            continue;
        }
        double q=(-2*c+f*x)/(f*c);
        double ans=0;
        int qq=(int)q;
        for(int i=0;i<qq;++i)
            ans+=c/(2+i*f);
        ans+=x/(2+qq*f);
        printf("Case #%d: %.7lf\n",++ca,ans);
    }
}
