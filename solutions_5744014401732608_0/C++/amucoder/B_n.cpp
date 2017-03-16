#include<cstdio>

int main()
{
int i,j,k,t,T,n,m;
int a[52][52];
scanf("%d",&T);

for(t=1;t<=T;t++)
	{
	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j] = 0;

	a[1][n] = 1;
	m--;

	k = n-1;

	
	while(m>0)
		{	
		if(k == 1 ) break;
		a[1][k] = 1; a[k][n] = 1;
		m--;

		for(j=k+1;j<n;j++)
			{
			if(m>= (1<<(n-j-1)))
				{
				a[k][j] = 1;
				m-= (1<<(n-j-1));
				}
			
			}
		k--;

		}
	if(m>0)
		printf("Case #%d: IMPOSSIBLE\n",t);
	else	
		{
		printf("Case #%d: POSSIBLE\n",t);
		for(i=1;i<=n;i++)
			{
			for(j=1;j<=n;j++)
				printf("%d",a[i][j]);
			printf("\n");
			}
		}

	}

return 0;
}
