#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int dp[22];

int w;

int gao(int id)
{
    if(dp[id]!=-1)
        return dp[id];
    if(id<=w)
        return dp[id]=id;
    if(id<=2*w-1)
        return dp[id]=w+1;
    return dp[id]=max(1+w, gao(id-w)+1);
}
int main()
{
    int ans,T, casen=0,c,r,i;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d%d%d",&c,&r,&w);
       for(i=0;i<=r;i++)
          dp[i]=-1;
       gao(r);
       printf("Case #%d: %d\n", ++casen, c*dp[r]);
   }
   return 0;
}
