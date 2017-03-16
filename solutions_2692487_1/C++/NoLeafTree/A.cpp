/*
ID: usshellub
LANG: C++
TASK: 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int motes[1000005];
int mymote;
int nums;

int comp(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}

int main()
{  
  int T,ncase=1;
  scanf("%d",&T);
  while(ncase<=T)
    {
      scanf("%d%d",&mymote,&nums);
      for(int i=0;i<nums;i++)
	{
	  scanf("%d",&motes[i]);
	}
      qsort(motes,nums,sizeof(motes[0]),comp);
      /*
      for(int i=0;i<nums;i++)
	printf(" %d",motes[i]);
      printf("\n");
      */
      int maxTimes=nums;
      int ans = 0;
      for(int i=0;i<nums;i++)
	{
	  if(motes[i]<mymote)
	    {
	      //  printf("curis %d,absorb %d\n",mymote,motes[i]);
	      mymote+=motes[i];
	    }
	  else
	    {
	      if(ans+(nums-i)<maxTimes)
		maxTimes = ans+(nums-i);
	      //eight add or minus
	      while(mymote<=motes[i]&&ans<maxTimes)
		{
		  //	  printf("doulbe\n");
		  ans += 1;
		  mymote+=(mymote-1);
		}
	      if(ans>=maxTimes)
		break;
	      mymote+=motes[i];
	    }
	}
      printf("Case #%d: %d\n",ncase++,(ans>maxTimes)?maxTimes:ans);
    }
  return 0;
}
