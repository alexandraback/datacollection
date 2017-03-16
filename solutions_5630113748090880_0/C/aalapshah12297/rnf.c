#include <stdio.h>

int main()
{
	int t, i, j, n, current;
	char count[2501]={};
	scanf("%d\n", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%d\n", &n);

		for(j=0;j<2501;j++)
			count[j]=0;
		for(j=0;j<n*(2*n-1);j++)
		{
			scanf("%d", &current);
			count[current]=(count[current]+1)%2;
		}

		printf("Case #%d: ", i);

		for(j=1;j<=2500;j++)
			if(count[j])
				printf("%d ", j);

		printf("\n");
	}

	return 0;
}
