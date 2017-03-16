#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int map[1005][1005];
int stack[1005],d[1005];
bool vis[1005];

bool dfs(int x)
{
 		  if(vis[x])return true;
 		  vis[x]=true;
 		  for(int i=1;i<=map[x][0];i++)
 		  if(dfs(map[x][i]))return true;
			return false; 
}
int main()
{
      freopen("a.in","r",stdin);
      freopen("a.out","w",stdout);
      int T,t,n,m;
      scanf("%d",&T);
      for(int cas=1;cas<=T;cas++)
      {
			 	   scanf("%d",&n);
			 	   printf("Case #%d: ",cas);
			 	   memset(d,0,sizeof(d));
					 for(int i=1;i<=n;i++)			
					 {
					 	   scanf("%d",&map[i][0]);
							 for(int j=1;j<=map[i][0];j++)			 
							 {
		 				     scanf("%d",&map[i][j]);
		 				     d[map[i][j]]++;
	             }
 					 }
 					 int top=0;
 					 for(int i=1;i<=n;i++)if(d[i]==0){stack[++top]=i;d[i]=-1;}
 			
 					 bool flag=false;
 					 int v;
 					 while(top&&!flag)
 					 {
					 		  v=stack[top--];
					 		  memset(vis,0,sizeof(vis));
						    flag=dfs(v);
					 		  
					 		  for(int j=1;j<=map[v][0];j++)
					 		  {
								     d[map[v][j]]--;
										 if(d[map[v][j]]==0){stack[++top]=map[v][j]; d[map[v][j]]=-1;}				
										
						    }
					 }
 					 if(flag)puts("Yes");
 					 else puts("No");
     }
      
      
      


      return 0;
}
