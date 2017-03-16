#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        long long i,n,p;
        double a[100001],ans,t1,t3,t4,tp[100001];
        scanf("%lld%lld",&p,&n);
        tp[0]=1;
        for(i=1;i<=p;i++)
        {
            scanf("%lf",&a[i]);
            tp[i]=tp[i-1]*a[i];
        }
        t1=tp[p]*(n-p+1)+(1-tp[p])*(n-p+1+n+1);
        t4=n+2;
        ans=min(t1,t4);
        for(i=1;i<p;i++)
        {
            t3=tp[i]*(n-i+(p-i)+1)+(1-tp[i])*(n-i+1+n+1+(p-i));
            ans=min(ans,t3);
        }
        printf("Case #%d: %.6lf\n",t,ans);
    }
    return 0;
}
