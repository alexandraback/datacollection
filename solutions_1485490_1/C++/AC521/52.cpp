#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
const int A = 110;
long long ANS[A][A], dp[A][A], dir[A][A], sh[A][A];
struct ll{
	long long id, len;
}numa[A], numb[A];
void init()
{
	memset(ANS, 0, sizeof(ANS));
	memset(dp, 0, sizeof(dp));
	memset(sh, 0, sizeof(sh));
	memset(dir, 0, sizeof(dir));
}

int main()
{
	int t, N,M,L,i,j,k;
	scanf("%d", &L);
	for(t = 1;t <= L;  t++)
	{
		init();
		scanf("%d%d", &N, &M);
		for(i = 1;i <= N; i++)
			scanf("%lld%lld", &numa[i].len, &numa[i].id);
		for(i = 1;i <= M; ++ i)
			scanf("%lld%lld", &numb[i].len, &numb[i].id);
		for(i = 1;i <= N; ++ i)
		{
			for(j = 1;j <= M; ++ j)
			{
				ANS[numa[i].id][j] = ANS[numa[i].id][j - 1];
				if(numa[i].id == numb[j].id)
				{
					ANS[numa[i].id][j] += numb[j].len;
				}
			}
		}
		for(i = 1;i <= N; ++ i)
		{
			for(j = 1;j <= M; ++ j)
			{
				dp[i][j] = dp[i - 1][j];
				dir[i][j] = dir[i - 1][j];
				sh[i][j] = sh[i - 1][j];
				for(k = 1;k <= j; ++ k)
				{
					long long dd = 0, temp = ANS[numa[i].id][j] - ANS[numa[i].id][k - 1];
					if(dir[i - 1][k - 1] == numa[i].id)
					{
						temp += sh[i - 1][k - 1];
					}
					if(temp > numa[i].len)
					{
						dd = temp - numa[i].len;
					}
					temp = dp[i - 1][k - 1] + min(temp, numa[i].len);
					if(temp > dp[i][j])
					{
						dp[i][j] = temp;
						sh[i][j] = dd;
						dir[i][j] = numa[i].id;

					}
				}
			}
		}
		printf("Case #%d: %lld\n", t, dp[N][M]);
	}
}