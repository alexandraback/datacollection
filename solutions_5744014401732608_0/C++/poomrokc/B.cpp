#include <stdio.h>
int tab[10][10],n,k,mic[10],found;
int run(int now)
{
	if(mic[now]!=-1)
		return mic[now];
	if(now==n)
		return 1;
	int sum=0;
	for(int i=1;i<=n;i++)
		if(tab[now][i]==1)
			sum+=run(i);
	mic[now]=sum;
	return sum;
}
void gentab(int r,int c)
{
	if(found==1)
		return;
	//printf("%d %d\n",r,c);
	if(r==n+1)
	{
		for(int i=1;i<=n;i++)
			mic[i]=-1;
		if(run(1)==k)
		{
			printf("POSSIBLE\n");
			found=1;
			for(int i2=1;i2<=n;i2++)
			{
				for(int i3=1;i3<=n;i3++)
					printf("%d",tab[i2][i3]);
				printf("\n");
			}
		}
		return;
	}
	if(c>r)
	{
		tab[r][c]=1;
		if(c!=n)
			gentab(r,c+1);
		else
			gentab(r+1,1);
	}
	tab[r][c]=0;
	if(c!=n)
		gentab(r,c+1);
	else
		gentab(r+1,1);
}
void doe()
{
	found=0;
	scanf("%d %d",&n,&k);
	gentab(1,1);
	if(found==0)
		printf("IMPOSSIBLE\n");
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		printf("Case #%d: ",i),doe();
	return 0;
}
