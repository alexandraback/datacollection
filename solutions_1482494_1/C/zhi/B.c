#include <stdio.h>
#define MAX_N 1000

int main()
{
	int i,j,T,N,A[MAX_N],B[MAX_N];
	int step,star,index,max_B,used[MAX_N],flag;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(j=0;j<N;j++)
			scanf("%d%d",&A[j],&B[j]);

		/* initialization */
		step=0;
		star=0;
		for(j=0;j<N;j++)
			used[j]=0;

		while(star<2*N)
		{
			flag=0;
			for(j=0;j<N;j++)
				if(used[j]!=2&&B[j]<=star)
				{
					star+=(2-used[j]);
					used[j]=2;
					step++;
					flag=1;
				}
			if(flag==1)
				continue;

			max_B=-1;
			for(j=0;j<N;j++)
				if(used[j]==0&&A[j]<=star&&B[j]>max_B)
				{
					index=j;
					flag=1;
					max_B=B[j];
				}
			if(flag==1)
			{
				star+=1;
				used[index]=1;
				step++;
			}
			else
				break;
		}

		if(star==2*N)
			printf("Case #%d: %d\n",i+1,step);
		else
			printf("Case #%d: Too Bad\n",i+1);
	}
	return 0;
}
