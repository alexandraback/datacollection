#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;

double ans[201];
int a[201];
int main()
{
 double avg,s,count,s1;
 int i,j,n,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
                     scanf("%d",&n);
                     for(j=0;j<n;j++)
                     scanf("%d",&a[j]);
                     s=2*accumulate(a,a+n,0);
                     avg=s/n;count=0,s1=0;
                     
                     //cout<<avg<<" "<<s;
                     j=0;
                      while(j<n)
                     {
                                     ans[j]=1;
                                     if(a[j]>avg)
                                     {
                                                 ans[j]=0.0;count++;
                                                 s1=s1+a[j];
                                     }
                                     avg=double((s-s1)/(n-count));              
                     j++;
                     }
                     for(j=0;j<n;j++)
                     if(a[j]>avg && ans[j]!=0)
                     {
                                 ans[j]=0.0;count++;
                                 s1=s1+a[j];
                     }
                     avg=double((s-s1)/(n-count));
                     
                     //cout<<avg;
                     for(j=0;j<n;j++)
                     if(ans[j]!=0.0)
                     ans[j]=(avg-a[j])*200/s;
                     printf("Case #%d: ",i);
                     for(j=0;j<n;j++)
                     printf("%.6lf ",ans[j]);
                     printf("\n");
    }
    return 0;
}
                     
                     
                     
                     
                     
                     
