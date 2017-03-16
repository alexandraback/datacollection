#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, teste;
	scanf("%d\n", &teste);

	for (int t = 0; t < teste; t++)
	{
		int bff[1100];
		bool base[1100];
		int best[1100];
		int n;
		int resp = 1;

		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			bff[i] = a - 1;
		}

		for (int i = 0; i < n; i++)
		{
			base[i] = (bff[bff[i]] == i);
			best[i] = 0;
			if (base[i] && resp < 2)
				resp = 2;
		}

		bool visited[1100];
		int vcount = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[j] = false;
			}
			visited[i] = true;
			int pos = bff[i];
			int size = 1;
			while(true)
			{
				if (pos == i)
				{
					if (resp < size)
						resp = size;
					break;
				}
				else if (base[pos])
				{
					if (!base[i])
					{
						if (best[pos] < size)
							best[pos] = size;
					}
					break;
				}
				else if (visited[pos])
				{
					break;
				}
				visited[pos] = true;
				pos = bff[pos];
				size++;
			}
		}

		int basesum = 0;
		for (int i = 0; i < n; i++)
		{
			if (base[i])
			{
				basesum += best[i] + 1;
			}
		}
		if (resp < basesum)
			resp = basesum;
		printf("Case #%d: %d\n", t + 1, resp);
	}
	return 0;
}
