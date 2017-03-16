#include<stdio.h>
#include<stdlib.h>
typedef struct _newStruct
{
  int val,idx;
}newStruct;
newStruct sum[2000000];
int a[25];
int compare(const void *a,const void *b)
{
  if((*(newStruct*)a).val<(*(newStruct*)b).val)
    return -1;
  return 1;
}
int main()
{
  int t,test=1,n,i,j;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
	scanf("%d",&a[i]);
      for(i=1;i<=(1<<n);i++)
	{
	  sum[i-1].val=0;
	  sum[i-1].idx=i;
	  for(j=0;j<n;j++)
	    {
	      if(i&(1<<j))
		sum[i-1].val+=a[j];
	    }
	}
      qsort(sum,(1<<n),sizeof(newStruct),&compare);
      for(i=1;i<(1<<n);i++)
	{
	  if(sum[i].val==sum[i-1].val)
	    break;
	}
      printf("Case #%d:\n",test);
      if(i>=(1<<n))
	printf("Impossible\n");
      else
	{
	  for(j=0;j<n;j++)
	    if(sum[i-1].idx & (1<<j))
	      printf("%d ",a[j]);
	  printf("\n");
	  for(j=0;j<n;j++)
	    if(sum[i].idx & (1<<j))
	      printf("%d ",a[j]);
	  printf("\n");
	}
      test++;
    }
  return 0;
}
