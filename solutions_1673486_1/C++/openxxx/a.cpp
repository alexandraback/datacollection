#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int T,A,B;
double p[110000];
double f[110000];

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);

    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>A>>B;
        for(int i=1;i<=A;i++)
        {
            scanf("%lf",p+i);
        }
        f[0]=1;
        for(int i=1;i<=A;i++)
        {
            f[i]=f[i-1]*p[i];
        }
        double ans=(double)(B+2);
        for(int i=0;i<=A;i++)
        {
            double tmp;
            tmp=(double)(i)+((double)(B-A+i+1))*f[A-i]+((double)(B-A+i+2+B))*(1-f[A-i]);
            ans=min(ans,tmp);
        }
        printf("Case #%d: %.9f\n",ca,ans);
    }
    return 0;
}

















