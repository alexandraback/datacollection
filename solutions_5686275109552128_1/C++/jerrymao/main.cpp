#include <bits/stdc++.h>
using namespace std;

int p[1005];
int d;
int t;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d", &d);
		for (int i = 0;i < d;i++)
			scanf("%d", p+i);
		sort(p, p+d);
		int ans = 2147483647;
		for (int i = 1;i <= p[d-1];i++)
		{
			int alt = i;
			for (int j = 0;j < d;j++) if (p[j] > i)
			{
				if (p[j]%i) alt += p[j]/i;
				else alt += p[j]/i-1;
			}
			if (alt < ans)
				ans = alt;
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
