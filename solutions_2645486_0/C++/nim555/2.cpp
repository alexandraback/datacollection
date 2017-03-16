#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
int main()
{
int t;
scanf("%d",&t);
for(int cas=1;cas<=t;cas++)
        {
        int e,r,n;
        scanf("%d %d %d",&e,&r,&n);
        
        int a[n];
        int dp[e+1][n];
        for(int i=0;i<=e;i++)
        for(int j=0;j<n;j++)
                dp[i][j]=0;
                
        for(int i=0;i<n;i++)
                {
                 scanf("%d",&a[i]);
                }
        //long long int k=ma/(r*10);
        
        for(int i=0;i<=e;i++)
                {
                 dp[i][n-1]=i*a[n-1];
                }
        
        for(int i=n-2;i>=0;i--)
                {
                 for(int j=0;j<=e;j++)
                         {int large=0;
                          for(int k=j;k>=0;k--)
                                  {
                                   int dummy=k*a[i];
                                   int ne;
                                   
                                   ne=j-k+r;
                                   if(ne>e)
                                   ne=e;
                                   if(large<dummy+dp[ne][i+1])
                                                              large=dummy+dp[ne][i+1];
                                  }
                         dp[j][i]=large;
                         }
                }
        
       int answer=0;
       for(int i=0;i<=e;i++)
       {
        if(answer<dp[i][0])
                           answer=dp[i][0];
       }
                
        printf("Case #%d: %d\n",cas,answer);
        
        }
}
