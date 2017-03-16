#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
int vis[MAX],q[MAX*MAX];
int a[MAX][MAX];
int main()
{
   int cases,cnt;
   int i,n,j;
   int node,root;
   for(scanf("%d",&cases),cnt=1;cnt<=cases;cnt++){
      printf("Case #%d: ",cnt);
      scanf("%d",&n);
      for(i=1;i<=n;i++){
         scanf("%d",&a[i][0]);
         for(j=a[i][0];j;j--)
            scanf("%d",&a[i][j]);
      }
      int out=0,qptr,eptr;
      for(root=1;root<=n;root++){
         qptr=0,eptr=1;
         q[0]=root;
         memset(vis,0,sizeof(vis));
         while(qptr<eptr){
            node=q[qptr++];
            if(vis[node]){
               out=printf("Yes\n");
               break;
            }
            else vis[node]++;
            for(i=a[node][0];i;i--)
               q[eptr++]=a[node][i];
         }
         if(out) break;
      }
      if(!out) printf("No\n");
   }
   return 0;
}
