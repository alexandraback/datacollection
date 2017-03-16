#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;
int T,cas=0;
double C,X,F;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&C,&F,&X);
        double ans=1e10,sum=0;
        for(int i=0;i<100000;i++)
        {
            ans=min(ans,sum+X/(2+F*i));
            sum+=C/(2+F*i);
        }
        printf("Case #%d: %.7f\n",++cas,ans);
    }
}
