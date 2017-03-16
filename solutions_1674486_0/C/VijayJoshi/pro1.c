// Problem 1
#include<stdio.h>
#define MAX 1001
typedef long long unsigned int LLU;
typedef long long int LL;
void solve();

int visited[MAX]={0},G[MAX][MAX]={0},N;
int DFS(int x)
{
 int i=0;
 static ans=0;
 if(visited[x]) return 1;
 visited[x]=1;
 for(i=1;i<=N;i++)
  {
   if(G[x][i]) 
     {
      ans=DFS(i);
      if(ans==1) return 1;
     } 
  }
  return 0;
}
int main(void)
{
    int T,t;
//    freopen("sample_input_1.txt","r",stdin);
//    freopen("sample_output_1.txt","w",stdout);

    freopen("s_input.in","r",stdin);
    freopen("s_output.txt","w",stdout);
/*    freopen("b_input.in","r",stdin);
    freopen("b_output.txt","w",stdout);
*/
    scanf("%d",&T);
    for(t=1;t<=T;t++)
     {
       printf("Case #%d: ",t);
       solve();
       printf("\n");
     }
    return 0;
}
void solve()
{
  int M,i,j;
  scanf("%d",&N);
  memset(G,0,sizeof G);
  for(i=1;i<=N;i++)
   {
    scanf("%d",&M);
    while(M--)
    {
     scanf("%d",&j);
     G[i][j]=1;
    }
   }
  for(i=1;i<=N;i++) 
   {
    memset(visited,0,sizeof visited);
    if(DFS(i))
     {
      printf("Yes");
      return;
     } 
   } 
   printf("No"); 
}
