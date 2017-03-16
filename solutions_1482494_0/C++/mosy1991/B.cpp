#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
int n;
struct node
{
	int data;
	int id;
	int another;
};
node a[MAXN], b[MAXN];
bool vis[MAXN];

bool cmp(node p, node q)
{
	return (p.data < q.data || p.data == q.data && p.another > q.another);
}

int cal()
{
	sort(a, a + n, cmp);
	sort(b, b + n, cmp);
	int tmp = n;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		if (b[i].data <= sum)
		{
			if (vis[b[i].id])
				sum++;
			else
			{
				sum += 2;
				vis[b[i].id] = true;
			}
		}
		else
		{
			while ((a[j].data <= sum) && (j < n))
			{
				if (vis[a[j].id])
				{
					++j;
					continue;
				}
				++tmp;
				sum++;
				vis[a[j].id] = true;
				++j;
				if (b[i].data <= sum)
				{
					if (vis[b[i].id])
						sum++;
					else
					{
						sum += 2;
						vis[b[i].id] = true;
					}
					break;
				}				
			}
			if (b[i].data > sum)
				return -1;
		}
	}
	return tmp;
}

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cases = 0, T;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d: ", ++cases);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &a[i].data, &b[i].data);
			a[i].id = i;
			a[i].another = b[i].data;
			b[i].id = i;
			b[i].another = a[i].data;
		}
		memset(vis, false, sizeof(vis));
		int ans = cal();
		if (ans == -1)
			puts("Too Bad");
		else printf("%d\n", ans);
	}
	return 0;
}