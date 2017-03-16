#include <stdio.h>

int main()
{
	int T,k,i,j,n;
	int a[1005];
	freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	freopen("Result.txt", "w", stdout);

	int max=0;
	int min,minp;
	for(k = 1; k <= T; k++) 
	{

		scanf("%d", &n);
		for (i=0; i<n; i++) 
		{
			scanf("%d", a+i);
			if (a[i]>max) max=a[i];
		}

		min=max;
		for (j=1;j<=max;j++)
		{
			minp = j;
			for (i=0;i<n;i++) 
				minp+=(a[i]-1)/j;
			if (minp<min) min=minp;

		}

		printf("Case #%d: %d\n",k,min);
	}
}