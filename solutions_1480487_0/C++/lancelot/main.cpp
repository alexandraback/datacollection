#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
double num[1223];
int n;
int mk[12312];

double sum;
double cal(double t)
{
    double res=0;
    for(int i=0;i<n;i++)
    {
        if(t-num[i]>0)
        res+=t-num[i];
    }
    return res;
}
int main()
{
    freopen("A-small-attempt4.in","r",stdin);
    freopen("as.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int C=1; C<=T; C++)
    {
        memset(mk,0,sizeof(mk));
        sum=0;
        scanf("%d",&n);
        double mx=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&num[i]);
            sum+=num[i];
            mx=max(mx,num[i]);
        }
        mx*=n;
        mx-=sum;
        int t=1;
        while(mx>0)
        {
            mx-=sum;
            t++;
        }
        t=2;
        //printf("%d\n",t);
        printf("Case #%d: ",C);
        int h=n;
        for(int i=0; i<n; i++)
        {
            if(2*sum/n<=num[i])
            {
                h--;
                mk[i]=1;

            }
        }
        double low =0,high=2*sum/n;
        double mid=(low+high)/2;
        for(int i=0;i<=200;i++)
        {
            if(cal(mid)>sum)
            high=mid;
            else low=mid;
            mid=(low+high)/2;
        }
        for(int i=0; i<n; i++)
        {
            printf("%lf%c",mid>num[i]?(mid-num[i])/(sum)*100:0,i==n-1?'\n':' ');
            //else printf("%lf%c",(num[i])/(sum)*100,i==n-1?'\n':' ');
        }
    }
    return 0;
}
