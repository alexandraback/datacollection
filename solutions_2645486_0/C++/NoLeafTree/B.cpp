
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int E,R,N;
int arr[20];
int maxVal;

void dfs(int step,int eng,int val)
{
 
  if(val>maxVal) 
    maxVal = val;
  if(step==N)
    return;
    
  if(eng>E)
    { 
      eng=E;
    }
  for(int i=0;i<=eng;i++)
    {
      dfs(step+1,eng-i+R,val+arr[step]*i);
      //  if(val+arr[step]*i >12)
      //	printf("xxx i=%d,val=%d,step=%d\n",i,val,step);
    }
}

int main()
{  
  int T,ncase= 1;
  scanf("%d",&T);
  while(ncase<=T)
    {
      scanf("%d%d%d",&E,&R,&N);
      for(int i=0;i<N;i++)
	{
	  scanf("%d",&arr[i]);
	}
      maxVal =0;
      dfs(0,E,0);
      printf("Case #%d: %d\n",ncase++,maxVal);
    }
  return 0;
}
