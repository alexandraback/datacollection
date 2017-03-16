#include <cstdio>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

#define F first
#define S second
#define mp make_pair

int n;
pair<int, int> star[1000];
int vis[1000];

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d: ", q);
		scanf("%d", &n);
		
		memset(vis, 0, sizeof vis);
		
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &star[i].F, &star[i].S);
		}
		
		int res = 0, s = 0, t = n;
		bool g = 1;
		
		while (g)
		{
			g = 0;
			for (int i = 0; i < n; ++i)
			{
				if (vis[i] == 2) continue;
				if (star[i].S <= s)
				{
					if (vis[i] == 0) s += 2;
					else s += 1;
					++res;
					g = 1;
					vis[i] = 2;
					--t;
				}
			}
			if (g) continue;
			int best = -1;
			for (int i = 0; i < n; ++i)
			{
				if (vis[i] >= 1) continue;
				if (star[i].F <= s)
				{
					if (best == -1 || star[i].S > star[best].S) best = i;
				}
			}
			if (best != -1)
			{
				g = 1;
				vis[best] = 1;
				s += 1;
				++res;
			}
		}
		
		if (t) printf("Too Bad\n");
		else printf("%d\n", res);
	}
	
	return 0;
}

