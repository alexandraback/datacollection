#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int arr[10000];
int dist[10000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		int e, r, n;
		scanf("%d %d %d", &e, &r, &n);

		for (int i=0; i<n; ++i)
			scanf("%d", &arr[i]);

		for (int i=0; i<n; ++i)
		{
			dist[i] = 0;
			for (int j=i+1; j<n; ++j)
			{
				if (arr[i] < arr[j])
				{
					dist[i] = j - i;
					break;
				}
			}
		}

		long long ans = 0;
		int ce = e;
		for (int i=0; i<n; ++i)
		{
			int use = 0;
			if (dist[i] == 0)
				use = ce;
			else
				use = std::max(0, ce - std::max(e - dist[i]*r, 0));

			ans += (long long)use * arr[i];
			ce -= use;
			ce = std::min(ce + r, e);
		}

		printf("Case #%d: %lld\n", c, ans);
	}
	
	return 0;
}