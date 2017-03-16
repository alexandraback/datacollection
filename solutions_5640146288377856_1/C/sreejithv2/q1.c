#include<stdio.h>


void main()
{
	
	int T;
	scanf("%d",&T);
	int cases=0;
	while(T--)
	{
		int ar[20][20]={0};
		int R,C,W;
		scanf("%d",&R);
		scanf("%d",&C);
		scanf("%d",&W);
		int i;
		int j;
		int count=0;
		for(i=0;i<R;i++)
			for(j=W-1;j<C;j+=W)
				{
					ar[i][j]=1;
					count++;
				}
			
			if(C%W!=0)
			count++;
			
			count+=W-1;
			cases++;
		printf("Case #%d: %d\n",cases,count);
	}
}


