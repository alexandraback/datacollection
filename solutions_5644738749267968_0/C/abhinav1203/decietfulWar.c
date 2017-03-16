#include<stdio.h>
#include<stdlib.h>
double naomi[1005],ken[1005];
int compare(const void *a,const void *b)
{
  if(*(double*)a<*(double*)b)return -1;
  return 1;
}
int bSearch(double arr[],double key,int lo,int hi)
{
  int mid;
  while(lo<hi)
    {
      mid=(lo+hi)>>1;
      if(arr[mid]<key)lo=mid+1;
      else hi=mid-1;
    }
  if(arr[lo]<key)return lo+1;
  return lo;
}
int main()
{
  int T,N,i,minKen,maxKen,deceitfulScore,warScore,x,test=1;
  scanf("%d",&T);
  while(T--)
    {
      scanf("%d",&N);
      for(i=0;i<N;i++)
	scanf("%lf",&naomi[i]);
      for(i=0;i<N;i++)
	scanf("%lf",&ken[i]);
      qsort(naomi,N,sizeof(double),&compare);
      qsort(ken,N,sizeof(double),&compare);
      minKen=0;maxKen=N-1;
      deceitfulScore=0;
      for(i=0;i<N;i++)
	{
	  if(naomi[i]<ken[minKen])
	    {
	      maxKen--;
	    }
	  else
	    {
	      minKen++;
	      deceitfulScore++;
	    }
	}
      warScore=N;minKen=0;
      for(i=0;i<N;i++)
	{
	  x=bSearch(ken,naomi[i],minKen,N-1);
	  if(x>=0 && x<N)
	    warScore--;
	  minKen=x+1;
	}
      printf("Case #%d: %d %d\n",test++,deceitfulScore,warScore);
    }
  return 0;
}
