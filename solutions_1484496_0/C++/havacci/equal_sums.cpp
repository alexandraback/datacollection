#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

int v[20];
int sums[2000000];
int idxs[2000000];

void
printans(int sum, int i)
{
	int x, j = idxs[sum];
	for(x = 0; x < 20; ++x)
		if(i & (1 << x)) printf("%d ", v[x]);
	printf("\n");
	for(x=0; x<20;++x)
		if(j & (1 << x)) printf("%d ", v[x]);
	printf("\n");
}

int
main()
{
	int t, n, i, j, sum, ca=0;
	bool done;

	scanf("%d", &t);
	while(t--)
	{
		memset(sums, 0, sizeof(sums));
		memset(idxs, 0, sizeof(idxs));
		scanf("%d", &n);
		for(i=0;i<n;++i)
			scanf("%d", &v[i]);

		done = false;
		for(i = 0; i < (1 << n); ++i)
		{
			sum = 0;
			for(j = 0; j < n; ++j)
				if(i & (1 << j)) sum += v[j];
			if(sums[sum])
			{
				printf("Case #%d:\n", ++ca);
				printans(sum, i);
				done = true;
				break;
			}
			++sums[sum];
			idxs[sum] = i;
		}

		if(!done) printf("Case #%d:\nImpossible\n", ++ca);
	}

	return 0;
}

