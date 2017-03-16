#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#define oo 1000000
#define MAXN 100000005
using namespace std;  
int dis[MAXN];  
int rev(int x)
{
      int s[8];
      int n=0,i,t,ans;
      while (x) s[++n]=x%10,x/=10;
      for (t=1,i=n,ans=0;i>=1;i--,t*=10) ans+=s[i]*t;
      return ans;  
}
int dfs(int h,int N)
{
      int p,ans=0;   
      if (h>N) return 0;
      p=h+1;
      if (dis[p]>dis[h]+1) 
      {
           dis[p]=dis[h]+1;
           dfs(p,N);
       } 
       p=rev(h);
       if (dis[p]>dis[h]+1) 
       {
            dis[p]=dis[h]+1;
            dfs(p,N);
       } 
       return ans;
}
int main()
{    
      int T,cases,N;     
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
             scanf("%d",&N);   
             printf("Case #%d: %d\n",cases,dfs(1,N));
      }
      return 0;
}
