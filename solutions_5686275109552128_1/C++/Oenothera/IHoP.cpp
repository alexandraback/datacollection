#include <stdio.h>

int T;
int D;
int P[2000];

int main() {

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,p;
	int i, sum;
	int i_max;
	int min;

	scanf("%d",&T);

	for( t = 1; t <= T; t ++ )
	{
		min = 21474836;
		i_max = 0;

		scanf("%d",&D);
		for(p = 0; p < D; p ++ )
		{
			scanf("%d",&P[p]);
			i_max = i_max > P[p] ? i_max : P[p];
		}

		for( i = 1; i <= i_max; i++ )
		{
			sum = i;
			for( p = 0; p < D; p ++ )
			{
				sum += P[p]/i;
				if(P[p] % i == 0)
					sum--;
			}
			min = min < sum ? min : sum;
		}

		printf("Case #%d: %d\n",t,min);
	}

	return 0;
}
