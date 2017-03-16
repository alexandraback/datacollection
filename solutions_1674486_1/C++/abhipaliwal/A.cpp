#include<cstdio>

int a[1010][1010];
int b[1010];
int n;

int traverse(int t)
{
//	printf("%d\n",t);
	int i;
	for(i=0;i<n;i++)
	{
		if(a[t][i]==1)
		{
//			printf("%d->%d\n",t,i);
			if(b[i]==1)
				return 1;
			b[i]=1;
			if(traverse(i)==1)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int t;

	scanf("%d",&t);
	int it=1;
	while(it!=t+1)
	{
		
		scanf("%d",&n);
		
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=0;
		for(i=0;i<n;i++)
		{
			int y,p;
			scanf("%d",&y);
			for(j=0;j<y;j++)
			{
				scanf("%d",&p);
				a[i][p-1]=1;
			}
		}
/*		printf("Matrix\n");
	for(i=0;i<n;i++)
{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
}
*/
		int flag=0;
		for(i=0;i<n;i++)
		{
//			puts("T");
			for(j=0;j<n;j++)
				b[j]=0;
			if(traverse(i)==1)
			{	
				printf("Case #%d: Yes\n",it);
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Case #%d: No\n",it);
		it++;
	}
	scanf("%d",&t);

	return 0;
}