#include <cstdio>

using namespace std;

int main()
{
	int cnt[2501];
	int t,T,i,j,n,in;

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		for(i=1;i<=2500;i++)
			cnt[i]=0;

		scanf("%d",&n);
		for(i=0;i<2*n*n-n;i++)
		{
			scanf("%d",&in);
			cnt[in]++;
		}

		printf("Case #%d:",t);
		for(i=1;i<=2500;i++)
			if(cnt[i]%2)
				printf(" %d",i);
		printf("\n");
	}

	return 0;
}
