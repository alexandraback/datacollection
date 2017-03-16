/*
 ============================================================================
 Name        : test.c
 Author      : cl
 Version     : fuck
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(x,y) ((x)<(y)?(x):(y))
int cmp(const void *x,const void *y)
{
	return *(int *)x>*(int*)y?1:-1;
}
int main()
{
	int a[105],A,N,T,cas=1;
	/*freopen("out","w",stdout);*/
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&A,&N);
		int i;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",cas++);
		if(A==1)
		{
			printf("%d\n",N);
			continue;
		}
		qsort(a,N,sizeof a[0],cmp);
		int ans=101,j,tmp,ta;
		for(i=0;i<=N;i++)
		{
			tmp=i;ta=A;
			for(j=0;j<N-i;j++)
			{
				while(ta<=a[j])
				{
					ta+=ta-1;
					tmp++;
				}
				ta+=a[j];
			}
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
