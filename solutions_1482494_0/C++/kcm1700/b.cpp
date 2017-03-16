#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int v[1024];
pair<int, int> dat[1024];

int main()
{
	int T;
	scanf("%d", &T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d",&dat[i].first, &dat[i].second);
			v[i] = 0;
		}

		int ans = 0;
		int stars = 0;
		for(;;)
		{
			bool compl = true;
			for(int i = 0; i < n; i ++)  if(v[i] != 2) compl = false;
			if(compl) break;

			int vmin = -1;

			for(int i = 0; i < n; i ++)
			{
				if(v[i] < 2 && dat[i].second <= stars)
				{
					vmin = i;
				}
			}

			if(vmin != -1)
			{
				ans ++;
				stars += 2 - v[vmin];
				v[vmin] = 2;
				continue;
			}

			int maxv = -1;
			for(int i = 0; i < n; i ++)
			{
				if(v[i] < 1 && dat[i].first <= stars && maxv < dat[i].second)
				{
					maxv = dat[i].second;
					vmin = i;
				}
			}

			if(vmin != -1)
			{
				ans ++;
				stars += 1 - v[vmin];
				v[vmin] = 1;
				continue;
			}
			else
			{
				ans = -1;
				break;
			}
		}

		printf("Case #%d: ", testcase);
		if(ans == -1)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}