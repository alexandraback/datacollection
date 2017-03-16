#include <stdio.h>

char s[2010];
int main(void)
{
	int t ,ii;
	int n ,i;
	int k;
	int sum;
	int ans;
	
	scanf("%d" ,&t);
	for (ii=1 ; ii<=t ; ii++)
	{
		scanf("%d" ,&n);
		n++;
		scanf("%s" ,s+1);
		ans=0;
		sum=0;
		for (i=1 ; i<=n ; i++)
		{
			k=s[i]-'0';
			sum+=k;
			if (i-sum>ans)
			{
				ans=i-sum;
			}
		}
		printf("Case #%d: %d\n" ,ii ,ans);
	}
	
	return 0;
}
