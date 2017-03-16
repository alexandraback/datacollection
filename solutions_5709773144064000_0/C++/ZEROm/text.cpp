#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        double c,f,x,ans,res;
        scanf("%lf%lf%lf",&c,&f,&x);
        ans=x/2.0;
        res=0;
        for(int i=1;i<=100000;++i)
        {
            res+=c/(2.0+(i-1)*f);
            if(res+x/(2.0+i*f)<ans)ans=res+x/(2.0+i*f);
        }
        printf("Case #%d: %.7f\n",++Case,ans);
    }
    return 0;
}
