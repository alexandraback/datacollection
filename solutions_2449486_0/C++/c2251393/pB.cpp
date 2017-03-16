#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 110

using namespace std;

int n, m, stramax[MAXN], crosmax[MAXN];
vector< pair<int, int> > pos[MAXN];

int main()
{
	int t, cnt = 0;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		printf("Case #%d: ", ++cnt);
		for(int i = 1; i <= 100; i++)
			pos[i].clear();
		
		for(int i = 1; i <= n; i++)
		{
			crosmax[i] = 0;
			for(int j = 1; j <= m; j++)
			{
				stramax[j] = 0;
				int c;
				scanf("%d", &c);
				pos[c].push_back(make_pair(i, j));
			}
		}
		bool flag = 1;
		for(int val = 100; val > 0; val--)
			if(pos[val].size())
			{
				for(int i = 0; i < pos[val].size(); i++)
				{
					int x = pos[val][i].first, y = pos[val][i].second;
					if(crosmax[x] > val && stramax[y] > val)
						flag = 0;
					crosmax[x] = max(val, crosmax[x]);
					stramax[y] = max(val, stramax[y]);
				}
			}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
}
