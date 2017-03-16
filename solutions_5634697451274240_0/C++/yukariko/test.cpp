#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		char a[101];
		scanf("%s", a);

		int len = strlen(a);

		int n = 0;
		for(int i=0; a[i]; i++)
			n = n * 2 + (a[i] == '-');

		bool visit[1024] = {};
		queue<int> bfs;

		visit[n] = true;
		bfs.push(n);

		int ans = -1;
		while(!bfs.empty())
		{
			ans++;
			int size = bfs.size();
			while(size--)
			{
				int here = bfs.front();
				bfs.pop();

				if(here == 0)
				{
					bfs = queue<int>();
					break;
				}

				for(int i=0; i < len; i++)
					a[i] = (here >> (len - i - 1)) % 2;

				for(int i=1; i <= len; i++)
				{
					reverse(a, a + i);
					for(int j=0; j < i; j++)
						a[j] = !a[j];

					int there = 0;
					for(int j=0; j < len; j++)
						there = there * 2 + a[j];
					
					for(int j=0; j < i; j++)
						a[j] = !a[j];
					reverse(a, a + i);

					if(visit[there])
						continue;
					visit[there] = true;
					bfs.push(there);
				}
			}
		}

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}