#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int R,N,M,K;
int sets[10];
int ans[10];
int flag ;
void dfs(int step)
{
  if(step==N)
    {
      int i;
      for(i=0;i<K;i++)
	{
	  int x= sets[i];
	  if(x==1) continue;
	  for(int j=0;j<N;j++)
	    {
	      if(x%ans[j]==0)
		x/=ans[j];
	    }
	  if(x!=1)
	    break;
	}
      if(i==K)
	flag = 1;
      return;
    }
  for(int i=2;i<=M;i++)
    {
      if( flag) return;
      ans[step] = i;
      dfs(step+1);
    }
}

int main()
{  
  int T,ncase=1;
  scanf("%d",&T);
  while(ncase<=T)
    {
      printf("Case #%d:\n",ncase++);
      scanf("%d%d%d%d",&R,&N,&M,&K);
      for(int i=0;i<R;i++)
	{
	  for(int j=0;j<K;j++)
	    {
	      scanf("%d",&sets[j]);
	    }
	  flag = 0;
	  dfs(0);
	  for(int i=0;i<N;i++)
	    printf("%d",ans[i]);
	  printf("\n");
	}
	
      
    }
  return 0;
}
