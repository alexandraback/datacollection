#include<cstdio>
#include<cstring>

using namespace std;

int adj[1001][1001];

int main()
{
  int count,i,j,k,l,M,N,T;
  scanf("%d",&T);
  for(i=1;i<=T;i++)
    {
      memset(adj,0,sizeof(int)*1001*1001);
      scanf("%d",&N);
      for(j=0;j<N;j++)
	{
	  scanf("%d",&count);
	  for(k=0;k<count;k++)
	    {
	      scanf("%d",&M);
	      adj[j][M-1]=1;
	    }
	}
      for(l=0;l<N;l++)
	for(j=0;j<N;j++)
	  for(k=0;k<N;k++)
	    adj[j][k]=adj[j][k]+adj[j][l]*adj[l][k];
      printf("Case #%d: ",i);
      bool found=false;
      for(j=0;!found && j<N;j++)
	for(k=0;!found && k<N;k++)
	  if(adj[j][k]>=2)
	    found=true;
      if(found)
	printf("Yes\n");
      else
	printf("No\n");
    }
  return 0;
}
