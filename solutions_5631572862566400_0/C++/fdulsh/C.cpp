#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1010;

int n,ans,Tmax,top;
int stk[maxn],A[maxn],ft[maxn],g[maxn],vis[maxn],val[maxn],In[maxn];

void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&ft[i]);
     for(int i=1;i<=n;i++) g[i]=vis[i]=val[i]=In[i]=0;
}

void work()
{
     int Time=0,total=0;
     for(int i=1;i<=n;i++)
         if(!vis[i])
         {
            Time++; int k=i;
            for(;!vis[k];k=ft[k]) vis[k]=Time;
            if(vis[k]!=Time) continue;
            Time++; total++;
            for(;vis[k]!=Time;k=ft[k]) vis[k]=Time,val[k]=total;
         }
         
     for(int i=1;i<=n;i++) In[ft[i]]++;
     top=0;
     for(int i=1;i<=n;i++) if(In[i]==0) stk[++top]=i;
     while(top)
     {
           int k=stk[top]; top--;
           g[ft[k]]=max(g[ft[k]],g[k]+1); In[ft[k]]--;
           if(In[ft[k]]==0) stk[++top]=ft[k];
     }
     
     ans=0; int Tans=0;
     for(int i=1;i<=n;i++)
         if(val[i])
         {
            int cnt=1; A[1]=i; val[i]=0;
            for(int k=ft[i];k!=i;k=ft[k]) A[++cnt]=k,val[k]=0;
            if(cnt==2) Tans+=cnt+g[A[1]]+g[A[2]];
               else ans=max(ans,cnt);
         }
     ans=max(ans,Tans);
     printf("%d\n",ans);
}

int main()
{
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
    int TT;
    scanf("%d",&TT);
    for(int i=1;i<=TT;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
