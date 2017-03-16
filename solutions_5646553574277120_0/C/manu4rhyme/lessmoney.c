#include <stdio.h>

int arr[6];
int present[110];

int main()
{
	int T,i,k,j,sum,c,z;
	int C,D,V;
	scanf("%d",&T);
	for(z = 1; z <= T; ++z)
	{
		scanf("%d", &C);
		scanf("%d", &D);
		scanf("%d", &V);

		for(i = 0; i < D; ++i)
			scanf("%d", &arr[i]);

		for(i = 0; i < 110; ++i)
			present[i] = 0;

		for(i = 0; i < 32; ++i)
		{
			j = i;
			k = 0;
			sum = 0;
			while(j)
			{
				if(j & 1) sum += arr[k];

				++k;
				j >>= 1;
			}

			if(sum <= V) present[sum] = 1;
		}

		c = 0;
		for(i = 1; i <= V; ++i)
			if(present[i]) ++c ;

		printf("Case #%d: %d\n", z,V-c);
	}

	return 0;
}