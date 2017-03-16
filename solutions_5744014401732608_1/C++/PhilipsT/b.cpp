#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 55;

bool Lk[MAXN][MAXN];
int N;

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++)
	{
		scanf("%d", &N);
		printf("Case #%d:", i);
		long long B;
		scanf("%lld", &B);
		memset(Lk,0,sizeof Lk);
		bool Fal = 0;
		int cnt = 1;
		for(int i = 1;i < N;i ++)
			for(int j = i + 1;j < N;j ++) Lk[i][j] = 1;
		for(int j = N - 1;j;j --)
		{
			long long c = 1;
			if (j > 1) c = (1ll << (j - 2));
			if (B >= c) B -= c,Lk[j][N] = 1;
		}
		if (B) printf(" IMPOSSIBLE\n"); else
		{
			printf(" POSSIBLE\n");
			for(int j = 1;j <= N;j ++)
			{
				for(int k = 1;k <= N;k ++)
					printf("%d", Lk[j][k]);
				printf("\n");
			}
		}
	}
}
