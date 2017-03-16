#include<bits/stdc++.h>

using namespace std;

int T, K, C, S;
int a[110];

int main()
{
	freopen("D.in","r",stdin);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d%d",&K, &C, &S);
		printf("Case #%d:", tt);
		int need=(K-1)/C+1;
		if (S<need)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for(int i=0;i<K;i+=C)
		{
			long long sum=0;
			long long mul=1;
			for(int j=0;j<C;j++)
			{
				sum += min(i+j, K-1)*mul;
				mul *= K;
			}
			printf(" %lld", sum + 1);
		}
		printf("\n");
	}
	return 0;
}

