#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

char g[1005][1005];

int main(int argc, char* argv[])
{
	freopen("in.txt","r", stdin);
	freopen("out.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	for(int cas = 0; cas < T; ++cas)
	{
		memset(g, 0, sizeof(g));
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		{
			int M;
			scanf("%d", &M);
			for(int j = 0; j < M; ++j)
			{
				int k;
				scanf("%d", &k);
				g[i+1][k] = 1;
			}
		}

		bool res = false;
		int comp = 0;
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <=N; ++j)
			{
				if( i == j )
					continue;

				char visited[1005];
				memset(visited, 0,sizeof(visited));
				queue<int> q;
				q.push(i);
				while(!q.empty())
				{
					int n = q.front(); q.pop();
					if( n == j )
					{
						if(visited[n])
						{
							res = true;
							break;
						}
					
					}
					if(visited[n])
						continue;
					visited[n] = 1;
					for(int k = 1; k <= N; ++k)
					{
						if(g[n][k] == 1)
						{
							q.push(k);
						}
					}
				}
				if(res)
					break;
			}
			if(res)
				break;
		}
		if(res)
		{
			printf("Case #%d: Yes\n", (cas+1));
		}
		else
		{
			printf("Case #%d: No\n", (cas+1));
		}
	}
	return 0;
}