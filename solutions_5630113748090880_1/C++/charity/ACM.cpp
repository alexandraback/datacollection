#include <bits/stdc++.h>
using namespace std;
#define maxh 2501
#define maxn 50

int p[maxh], ret[maxn];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t, tn = 1, n, i, k, h, x;
	scanf("%d\n", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(p, 0, sizeof(p));
		k = 2*n - 1;
		for(i = 0; i < k; i++)
			for(h = 0; h < n; h++)
			{
				scanf("%d", &x);
				p[x]++;
			}
		k = 0;
		for(i = 0; i < maxh; i++)
			if(p[i]&1) ret[k++] = i;
		sort(ret, ret + k);
		printf("Case #%d:", tn++);
		for(i = 0; i < k; i++)
			printf(" %d", ret[i]);
		printf("\n");
	}
	return 0;
}
