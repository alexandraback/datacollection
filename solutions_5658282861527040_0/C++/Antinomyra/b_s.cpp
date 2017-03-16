#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int c = 1; c <= T;++c)
	{
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);
		int ans = 0;
		for(int i = 0; i<A;++i)
		{
			for(int j = 0; j<B; ++j)
			{
				if((i & j) < K)
					++ans;
			}
		}
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}