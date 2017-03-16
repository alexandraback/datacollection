#include<stdio.h>

int main()
{
	int t;
	int T;
	int b;
	long long m, s;
	int a[60][60], i, j;
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d %lld", &b, &m);
		s=1;
		for(i=1; i<=b-2; ++i) 
		s*=2;
		if(m>s) 
		{ 
		printf("Case #%d: IMPOSSIBLE\n", t); 
		continue;
		}
		printf("Case #%d: POSSIBLE\n", t);
		for(i=1; i<=b; ++i)
		{
			for(j=1; j<=i; ++j) a[i][j]=0;
			for(j=i+1; j<b; ++j) a[i][j]=1;
		}
		if(m==s)
		{
			for(i=1; i<b; ++i) a[i][b]=1;
		}
		else
		{
			a[1][b]=0;
			for(i=2; i<b; ++i)
			{
				a[i][b]=(m%2);
				m/=2;
			}
		}
		for(i=1; i<=b; ++i)
		{
			for(j=1; j<=b; ++j)
			{
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
}