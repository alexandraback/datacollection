#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int cnt = 1;
	for(; cnt <= t; cnt++)
	{
		int n;
		scanf("%d", &n);
		vector<int> v[1002];
		bool visit[1002];
		int in[1002];
		int i, j, k, inherit;
		memset(in, 0, sizeof(in));
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			for(j = 0; j < k; j++)
			{
				scanf("%d", &inherit);
				v[i].push_back(inherit);
				in[inherit]++;
			}
		}
		int ans = 1;
		for(i = 1; i <= n && ans; i++)
		{
			if(in[i] == 0)
			{
				queue<int> q;
                memset(visit, false, sizeof(visit));
				q.push(i);
				visit[i] = true;
				while(!q.empty() && ans)
				{
					k = q.front();
					for(j = 0; j < v[k].size(); j++)
					{
                         if(visit[v[k][j]] == true)
						 {
							 ans = 0;
							 break;
						 }
						 visit[v[k][j]] = true;
						 q.push(v[k][j]);
					}
					q.pop();
				}
			}
		}
		printf("Case #%d: ", cnt);
		if(ans == 0)
		{
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}







