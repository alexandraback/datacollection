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
#define MAXN 1000005
using namespace std;  
int dis[MAXN];
queue<int> Q;
bool inQ[MAXN];
int rev(int x)
{
      int s[8];
      int n=0,i,t,ans;
      while (x) s[++n]=x%10,x/=10;
      for (t=1,i=n,ans=0;i>=1;i--,t*=10) ans+=s[i]*t;
      return ans;  
}
void preWork()
{
      int h,p; 
      memset(dis,0x7f,sizeof(dis));
      memset(inQ,false,sizeof(inQ));
      while (Q.size()) Q.pop();
      dis[1]=1,Q.push(1);
      while (Q.size()) 
      {
             h=Q.front(),Q.pop(),inQ[h]=false;
             if (h>oo) continue;
             p=h+1;
             if (dis[p]>dis[h]+1) 
             {
                   dis[p]=dis[h]+1;
                   if (!inQ[p]) inQ[p]=true,Q.push(p);
             } 
             p=rev(h);
             if (dis[p]>dis[h]+1) 
             {
                   dis[p]=dis[h]+1;
                   if (!inQ[p]) inQ[p]=true,Q.push(p);
             }
      }
}
int main()
{    
      int T,cases,N;
      freopen("A-small-attempt0.in","r",stdin);
      freopen("output.txt","w",stdout);   
      preWork(); 
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
             scanf("%d",&N);   
             printf("Case #%d: %d\n",cases,dis[N]);
      }
      return 0;
}
