#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1005;
double bM[maxn], bK[maxn];
bool vis[maxn];

int main()
{
	int T, N, score;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%lf", &bM[i]);
		for(int i = 0; i < N; i++) scanf("%lf", &bK[i]);
		sort(bM, bM + N);
		sort(bK, bK + N);
		//for(int i = 0; i < N; i++) printf("%lf ", bM[i]);
		//printf("\n");
		//for(int i = 0; i < N; i++) printf("%lf ", bK[i]);
		//printf("\n");
		int minK = 0, maxK = N-1;
		score = 0;
		for(int i = 0; i < N; i++)
		{
			if(bM[i] > bK[minK])
			{
				score++;
				minK++;
			}
			else maxK--;
		}
		printf("Case #%d: %d ", k, score);
		score = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < N; i++)
		{
			bool ok = true;
			for(int j = 0; j < N; j++)
			{
				if(!vis[j] && bK[j] > bM[i])
				{
					vis[j] = true;
					ok = false;
					break;
				}
			}
			if(ok) score++;
		}
		printf("%d\n", score);
	}
	return 0;
}
