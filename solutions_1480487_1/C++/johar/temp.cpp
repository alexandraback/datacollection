#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#include<string>

using namespace std;
int a[222];
int main()
{
    int t,T,n,i,j;
    freopen("A-large.in","r",stdin);
   freopen("output.txt","w",stdout);   
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        int s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }            
        double lo=0.0, hi=1.0,mid;
        printf("Case #%d: ",t);
        for(i=0;i<n;i++)
        {
            lo=0.0, hi=1.0;
            for(j=0;j<200;j++)
            {
                mid=(lo+hi)/2.0;
//                cout<<mid<<endl;
                double x=a[i]+mid*s;
                double tot=mid;
                for(int k=0;k<n;k++)
                {
                    if(k==i) continue;
                    tot+=max(0.0,(x-a[k])/s);
                }
                if(tot+1e-8>1.0)
                    hi=mid;
                else lo=mid;
            }
            printf("%lf ",100.0*mid);
        }
        cout<<endl;
    }
//system("pause");
    return 0;
}
