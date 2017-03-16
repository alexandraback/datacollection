#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;
double min(double a,double b)
{
    return a<b?a:b;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.txt","w",stdout);
    int T,i,j,A,B;
    double p[100000];
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        scanf("%d%d",&A,&B);
        for(j=0;j<A;j++) scanf("%lf",&p[j]);
        double ans;
        double ct;
        double temp=p[0];
        ans=min(temp*(A-1+B)+(1-temp)*(A-1+2*B+1),B+2);
        for(j=1;j<A;j++) {
            ct=temp*p[j]*(A-j-1+B-j)+(1-temp*p[j])*(A-j-1+B-j+B+1);
            temp*=p[j];
            if(ct<ans) ans=ct;
        }
        printf("Case #%d: %.6lf\n",i,ans);
    }
    return 0;
}
