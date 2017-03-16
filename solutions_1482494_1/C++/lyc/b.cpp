#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node
{
	int a, b;
} x[1010];
int t, n;
bool b[1010];

bool cmp(Node p, Node q)
{
	return p.b < q.b;
}

int calc()
{
	sort(x + 1, x + n + 1, cmp);
	int s = 0, ret = 0;
	memset(b, true, sizeof(b));
	for (int i = 1; i <= n; i++)
	{
		while (s < x[i].b)
		{
			int z = 0;
			for (int j = 1; j <= n; j++)
				if (b[j])
					if (x[j].a <= s)
						z = j;
			if (z == 0) return -1;
			ret++;
			s++;
			b[z] = false;
		}
		ret++;
		if (b[i])
		{
			s += 2;
			b[i] = false;
		}
		else s++;
	}
	return ret;
}

int main()
{
	scanf("%d", &t);
	int ca = 0;
	while (t--)
	{
		ca++;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &x[i].a, &x[i].b);
		int k = calc();
		printf("Case #%d: ", ca);
		if (k == -1)
			puts("Too Bad");
		else printf("%d\n", k);
	}
	return 0;
}
