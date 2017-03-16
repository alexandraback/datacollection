#include <cstdio>
#include <algorithm>

using namespace std;

int F[1000];
bool incir[1000];
int loopsize[1000];
int mxlen[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &F[i]);
			--F[i];
		}
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			mxlen[i] = 0;
			int u = i;
			int cnt = 0;
			for (int j = 0; j < N; ++j)
			{
				u = F[u];
				cnt++;
				if (u == i)
					break;
			}
			if (u == i)
			{
				incir[i] = true;
				loopsize[i] = cnt;
				ans = max(ans, cnt);
			}
			else
				incir[i] = false;
		}
		for (int i = 0; i < N; ++i)
		{
			int u = i;
			int cnt = 0;
			while (!incir[u])
			{
				u = F[u];
				cnt++;
			}
			mxlen[u] = max(mxlen[u], cnt);
		}
		int cnt2 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (incir[i] && loopsize[i] == 2)
			{
				cnt2 += mxlen[i] + mxlen[F[i]] + 2;
			}
		}
		ans = max(ans, cnt2 / 2);
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
