#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
    
    int t;
    scanf("%d",&t);
    
    for(int i=1;i<=t;i++)
    {    
            long long int a;
            int n;
            scanf("%lld%d",&a,&n);
            long long int v[n];
            for(int j=0;j<n;j++)
                scanf("%lld",&v[j]);
            sort(v,v+n);
            // o wala mtlb add more
            // 1 wala mtlb remove more
            int sol=n;
            int c=0;
            long long int su=a;
            for(int j=0;j<n;j++)
            {
                    if(v[j]<su)
                        su+=v[j];
                    else{
                           sol=min(c+n-j,sol);
                           if(su!=1)
                           {
                                   while(v[j]>=su)
                                   {
                                                 c++;
                                                 su+=su-1;
                                   }
                                   su+=v[j];
                           }
                           else c=n;
                           
                    }
            }
            sol=min(sol,c);
            printf("Case #%d: %d\n",i,sol);
    
    }
    return 0;
    
}
