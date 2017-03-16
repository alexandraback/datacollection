#include <stdio.h>

int a[2010];
int main(void)
{
	int t ,ii;
	int n ,i ,j;
	int aa;
	int ans;
	int k;
	
	scanf("%d" ,&t);
	for (ii=1 ; ii<=t ; ii++)
	{
		for (j=1 ; j<=1000 ; j++)
		{
			a[j]=0;	
		}
		scanf("%d" ,&n);
		for (j=1 ; j<=n ; j++)
		{
			scanf("%d" ,&aa);
			a[aa]++;
		}
		ans=2000000000;
		for (i=1 ; i<=1000 ; i++)
		{
			k=0;
			for (j=i+1 ; j<=1000 ; j++)
			{
				k+=((j-1)/i)*a[j];	
			}
			if (i+k<ans)
			{
				ans=i+k;	
			}
		}
		printf("Case #%d: %d\n" ,ii ,ans);
	}
	
	return 0;
}
