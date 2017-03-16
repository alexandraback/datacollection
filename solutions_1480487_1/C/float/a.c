#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b)
{
	if( *((double*)b) > *((double*)a) )
		return 1;
	return -1;
}

int main()
{
	int t, cas, n, i;
	double cont[210], sum, avg, x, subsum, backup[210];
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		scanf("%d", &n);
		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%lf", &cont[i]);
			backup[i] = cont[i];
			sum += cont[i];
		}
		qsort(cont, n, sizeof(double), cmp);
		subsum = 0;
		for(i=0; i<n; i++)
		{
			if(cont[i] <= (2*sum-subsum)/(n-i))
			{
				x = i;
				avg = (2*sum-subsum)/(n-i);
				break;
			}
			subsum += cont[i];
		}
		printf("Case #%d:", cas);
		for(i=0; i<n; i++)
		{
			if( backup[i] > avg )
				printf(" 0");
			else
				printf(" %lf", (avg - backup[i])*100/sum);
		}
		printf("\n");
	}
	return 0;
}
