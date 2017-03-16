#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long 
#define oo 1000000000
using namespace std;  
int E,R,N,v[12],ans;
void dfs(int e,int t,int m)
{ 
      if (t>N)
      {
            if (m>ans) ans=m;
            return;
      }
      int i;  
      for (i=0;i<=e;i++) 
         dfs(min(E,e-i+R),t+1,m+i*v[t]); 
      return;
}
int main()
{
      freopen("B-small-attempt4.in","r",stdin);
      freopen("output.txt","w",stdout);
      int T,t,i;
      scanf("%d",&T);
      for (t=1;t<=T;t++)
      {   
            scanf("%d%d%d",&E,&R,&N);
            for (i=1;i<=N;i++) scanf("%d",&v[i]);
            ans=0; 
            dfs(E,1,0);
            printf("Case #%d: %d\n",t,ans); 
      }
      return 0;
}
