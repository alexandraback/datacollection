#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("bs.in", "r" ,stdin);
	freopen("bs.out", "w",stdout);
	int casen;
	scanf("%d",&casen);
	for(int C = 1;C<= casen;C++)
	{
		int A,B,K;
		int res = 0;
		scanf("%d %d %d ", &A,&B,&K);
		for(int i = 0;i<A;i++)
			for(int j = 0;j<B;j++)
			{
				int tmp =i & j;
				if(tmp <K)
					res++;
			}

		printf("Case #%d: %d\n",C, res);
	}

	return 0;
}