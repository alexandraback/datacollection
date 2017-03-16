#include <cstdio>
#include <algorithm>

int ns[100];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);
		for (int i=0; i<n; ++i)
			scanf("%d", ns+i);

		std::sort(ns, ns+n);

		int cnt = 0;
		for (int i=n-1; i>=0; --i)
		{
			if (ns[i]<p)
				break;

			int a = (ns[i]-p)>>1;
			if (p-a<=1)
				cnt++;
			else if (p-a==2 && s>0)
			{
				cnt++;
				s--;
			}
		}

		printf("Case #%d: %d\n", c, cnt);
	}
}