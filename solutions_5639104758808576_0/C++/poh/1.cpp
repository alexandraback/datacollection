#include<stdio.h>
int p[1005];
int main()
{
	FILE *fp=freopen("out.txt","w",stdout);
	int i,j,n,x,count,ans=0;
	char a[1005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ans=0;
		scanf("%d %s",&x,a);
		for(p[0]=a[0]-48,j=1;j<=x;j++)
			p[j]=a[j]-48;
		for(j=0,count=0;j<=x;j++)
		{
			if(count<j)
			{
				ans+=j-count;
				count+=j-count;
			}
			count+=p[j];
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}

