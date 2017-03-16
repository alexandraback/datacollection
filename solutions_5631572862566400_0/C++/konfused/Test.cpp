#include <cstdio>
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int i = 1; i <= T; ++i)
	{
		int N;
		scanf("%d", &N);
		
		int F[1001];
		for(int j = 1; j <= N; ++j)
			scanf("%d", &F[j]);

		bool visited[1001];
		for(int j = 1; j <= N; ++j)
			visited[j] = false;
		
		int max = 0;
		for(int j = 1; j <= N; ++j)
		{
			if(!visited[j])
			{
				visited[j] = true;

				bool fromCurr[1001];
				for(int k = 1; k <= N; ++k)
					fromCurr[k] = false;
				fromCurr[j] = true;
				int start = j, end = j, curr = F[start], size = 1;
				while(curr != start && !visited[curr])
				{
					visited[curr] = true;
					fromCurr[curr] = true;
					if(visited[F[curr]])
					{
						end = curr;
						++size;
						break;
					}
					curr = F[curr];
					++size;
				}

				if(curr != start)
				{
					for(int k = 1; k <= N; ++k)
						if(!fromCurr[k] && (F[k]==start || F[k]==curr))
						{
							++size;
							break;
						}
				}

				if(size > max)
					max = size;
			}
		}
		
		printf("Case #%d: %d\n", i, max);
	}
	
	return 0;
}
