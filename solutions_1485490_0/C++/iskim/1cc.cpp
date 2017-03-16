#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M;
pair<long long, int> box[105], toy[105];

long long visited[105][105];


long long ans(int b, int t)
{
	if (b == N) return 0;
	if (t == M) return 0;

	if (box[b].second != toy[t].second)
	{
		return max(ans(b+1, t), ans(b, t+1));
	}
	else
	{
		if (box[b].first > toy[t].first)
		{
			long long tmp = box[b].first;
			box[b].first -= toy[t].first;
			long long ret = ans(b, t+1);
			box[b].first = tmp;
			return ret + toy[t].first;
		}
		else if ( box[b].first < toy[t].first)
		{long long tmp = toy[t].first;
			toy[t].first -= box[b].first;
			long long ret = ans(b+1, t);
			toy[t].first = tmp;
			return ret + box[b].first;
		}
		else
		{
			return box[b].first + ans(b+1, t+1);
		}
	}
}

int main()
{
	int TT;
	scanf("%d",&TT);
	for (int tt = 1; tt <= TT; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%d%d",&N,&M);

		for (int i = 0; i < N; i++)
		{
			scanf("%lld%d", &box[i].first, &box[i].second);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%lld%d", &toy[i].first, &toy[i].second);
		}

		printf("%lld\n", ans(0, 0));
	}
	return 0;
}