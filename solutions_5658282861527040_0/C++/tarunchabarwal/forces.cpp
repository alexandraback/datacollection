#include<cstdio>
int main()
{
	int cases, a, b, k, i, j;
	
	int ii, jj;
	int count;
	scanf("%d", &cases);
	for(i=1;i<=cases;i++)
	{
		scanf("%d %d %d", &a, &b, &k);
		count = 0;
				
		for(ii=0;ii<a;ii++)
		{
			for(jj=0;jj<b;jj++)
			{
				if((ii&jj) < k)count++;
			}
		}		
		printf("Case #%d: %d\n", i, count);
	}
	return 0;
}