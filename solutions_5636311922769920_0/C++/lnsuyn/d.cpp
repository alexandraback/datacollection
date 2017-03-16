#include <stdio.h>

int main(void)
{
	int tt ,ii;
	int k ,c ,s;
	int i ,j;
	long long ans ,temp;
	int z;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d %d %d" ,&k ,&c ,&s);
		if (c*s<k)
		{
			printf("Case #%d: IMPOSSIBLE\n" ,ii);
		}
		else
		{
			printf("Case #%d:" ,ii);			
			z=0;
			for (i=1 ; i<=s ; i++)
			{
				ans=0;
				temp=1;
				for (j=1 ; j<=c ; j++)
				{
					ans+=z*temp;
					temp*=k;
					z++;
					if (z==k)
					{
						break;	
					}
				}
				ans++;
				printf(" %I64d" ,ans);
				if (i*c>=k)
				{
					printf("\n");
					break;	
				}
			}	
		}
	}
	
	return 0;
}
