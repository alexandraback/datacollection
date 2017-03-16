#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main()
{
	int T, N;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		// N = T;
		if (N == 0)
		{
			printf("Case #%d: INSOMNIA\n", t);
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		bool done = false;
		int M = 0;
		while (!done)
		{
			M += N;
			int t = M;
			while (t)
			{
				cnt[t % 10]++;
				t /= 10;
			}
			done = true;
			for (int i = 0; i < 10; i++)
				done = done && cnt[i];
		}
		printf("Case #%d: %d\n", t, M);
	}

	return 0;
}