#if 0==0

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	//#define SMALL 1

	#ifdef SMALL
		freopen("B-small.in", "r", stdin);
		freopen("B-small.out", "w", stdout);
	#else
		freopen("B-large.in", "r", stdin);
		freopen("B-large.out", "w", stdout);
	#endif


	int d[2501];

	int i_numCases;
	scanf("%d", &i_numCases);
	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{		
		int n;
		scanf("%d", &n);

		int k;
		for (int i = 0 ; i < 2501 ; i++) d[i] = 0;

		for (int i = 0 ; i < 2 * n - 1 ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				scanf("%d", &k);
				d[k]++;
			}
		}

		printf("Case #%d:", i_case);

		for (int i = 0 ; i < 2501 ; i++)
			if (d[i] % 2 == 1) printf(" %d", i);
		printf("\n");
	}


	return 0;
}

#endif