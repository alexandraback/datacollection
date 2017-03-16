#include <stdio.h>

char ans[1010];
int main(void)
{
	int tt ,ii;
	int n ,m ,i ,j ,j2;
	int g;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d %d" ,&n ,&m);
		for (i=0 ; i<n ; i++)
		{
			ans[i]='0';
		}
		ans[0]='1';
		ans[n-1]='1';
		ans[n]=0;
		printf("Case #%d:\n" ,ii);
		for (j=1 ; j<=m ; j++)
		{
			printf("%s" ,ans);
			for (j2=3 ; j2<=11 ; j2++)
			{
				printf(" %d" ,j2);
			}
			printf("\n");
			while (1)
			{
				for (i=n-1 ; i>=0 ; i--)
				{
					if (ans[i]=='0')	
					{
						ans[i]='1';
						break;
					}
					else
					{
						ans[i]='0';
					}
				}
				for (i=n-2 ; i>=0 ; i--)
				{
					if (ans[i]=='0')	
					{
						ans[i]='1';
						break;
					}
					else
					{
						ans[i]='0';
					}
				}			
				if (ans[n-1]=='1')
				{
					g=0;
					for (i=n-1 ; i>=0 ; i--)
					{
						if (ans[i]=='1')
						{
							g++;
						}
					}
					if (g%2==0)
					{
						break;	
					}
				}
			}
		}
	}
	
	return 0;
}
