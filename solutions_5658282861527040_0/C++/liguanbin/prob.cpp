#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	int A,B,K;
	scanf("%d",&T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d%d%d",&A,&B,&K);
		int num = 0;
		for (int i = 0; i < A; ++i)
		{
			for (int j = 0; j < B; ++j)
			{
				//cout << i << " " << j << " " << (i&j)
				if ((i & j) < K)
				{
					num++;
				}
			}
		}
		printf("Case #%d: %d\n",t,num);
	}
	return 0;
}