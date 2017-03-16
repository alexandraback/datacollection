#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int i,t,ans,d,p[1005],j,z,sum;
	scanf("%d",&t);
	for(i = 1; i <= t; i++)
	{
		ans = 0;
		scanf("%d",&d);
		for(j = 0; j < d; j++)
		{
			scanf("%d",&p[j]);
			if(p[j]>ans)
				ans = p[j];
		}
		z = 2;
		while( z < ans )
		{
			sum = 0;
			for(j = 0; j < d; j++)
				sum += ((p[j]-1)/z);
			sum += z;
			ans = min(ans,sum);
			z += 1;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}