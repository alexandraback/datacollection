#include<stdio.h>
#include<stdlib.h>

#define MIN(x,y)  ((X) < (Y) ?  (X) : (Y))

int min(int x, int y)
{
	return (x<y)?x:y;
}
int comp (const void * elem1, const void * elem2) {
    int x = *((int*)elem1);
    int y = *((int*)elem2);
    return x - y;
}

int  func(unsigned int * arr ,int i ,int n, unsigned int am)
{
	int sum = 0;
	for( ; i<n ; ++i)
	{
		if(am > arr[i])
		{
			am += arr[i];
		}
		else if(am == 1)
		{
			sum ++ ;
		}
		else
		{
			sum += min( func(arr,i,n,am + am -1) + 1 , func(arr,i+1,n,am) + 1);
			break;
		}
	}
	return sum;
}

int main()
{
	int T,iT,n,i,sum;
	unsigned int am,arr[105];
	while(scanf("%d",&T)!=EOF)
	{
		for(iT = 1;iT <= T ; ++iT)
		{
			sum = 0;
			scanf("%d %d",&am,&n);
			for(i = 0;i < n ;++i)
			{
				scanf("%d",&arr[i]);
			}
			qsort (arr, n, sizeof(unsigned int), comp);
			
			printf("Case #%d: %d\n",iT,func(arr,0,n,am));
		}
	}
	return 0;
}
