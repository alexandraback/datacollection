#include <stdio.h>
#include <algorithm>
using namespace std;

int n, s, p, q, T;

int go()
{
	int a = q/3, b = q%3;
	if (a+(b>0) >= p) return 1;
	if (2==b && a+2>=p && s>0)
	{
		--s;
		return 1;
	}
	if (!b && a && a+1>=p && s>0)
	{
		--s;
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d ", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d%d%d", &n, &s, &p);
		int m = 0;
		while (n--)
		{
			scanf("%d", &q);
			m += go();
		}
		printf("Case #%d: ", t+1);
		printf("%d\n", m);
	}
	return 0;
}
