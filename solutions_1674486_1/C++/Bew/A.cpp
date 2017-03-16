#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int T,now;
int n;
int no[1011],NO=0;
int in[1011];
int mem[1011];
vector<int> V[1011];
int ans;
int rec(int x)
{
  int i,j,k;
  if(ans==1)return 0;
  if(mem[x]==now)
   {
     ans=1;
     return 0;
   }
  mem[x]=now;
  for(i=0;i<V[x].size();i++)
   {
     rec(V[x][i]);
   }
  return 0;
} 
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i,j,k;
    int p,q,r;
    scanf("%d",&T);
    for(int ii=0;ii<T;ii++)
     {
       scanf("%d",&n);
       for(i=0;i<=n;i++)in[i]=0;
       for(i=1;i<=n;i++)
        {
          V[i].clear();
        }
       for(i=1;i<=n;i++)
        {
          scanf("%d",&k);
          for(j=0;j<k;j++)
           {
             scanf("%d",&p);
             V[i].push_back(p);
             in[p]++;
           }
        } 
       NO=0;
       for(i=1;i<=n;i++)
        {
          if(in[i]==0)
           {
             no[NO]=i;
             NO++;
           }
        }
       for(i=0;i<=n;i++)mem[i]=0;
       now=1;
       ans=0;
       for(i=0;i<NO;i++)
        {
          rec(no[i]);
          now++;
        }
       printf("Case #%d: ",ii+1);
       if(ans==1)printf("Yes");
       else printf("No");
       if(ii<T-1)printf("\n");
     }
    
    scanf(" ");
    return 0;
}
