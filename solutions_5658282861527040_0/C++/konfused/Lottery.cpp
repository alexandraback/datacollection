// Lottery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("log.txt", "w", stderr);
	
	int nTestCases;
	scanf("%d", &nTestCases);
	
	for(int i = 0; i < nTestCases; i++)
	{
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);

		int count = 0;
		for(int j = 0; j < A; j++)
		{
			for(int k = 0; k < B; k++ )
			{
				if((j&k) < K)
					count++;
			}
		}

		printf("Case #%d: %d\n",i+1,count);
	}

	return 0;
}

