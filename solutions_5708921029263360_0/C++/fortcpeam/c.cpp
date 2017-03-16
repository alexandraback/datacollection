#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 1005;

struct Tr{
	int x, y, z;
} a[N];

int tmp[N];
int best[N];
int b[N], c[N], d[N];
int n, j, p, s, K;

int main()
{
	srand(time(0));
	freopen("c4.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		scanf("%d%d%d%d", &j, &p, &s, &K);
		n = 0;
		for (int i = 1; i <= j; i ++)
			for (int j = 1; j <= p; j ++)
				for (int k = 1; k <= s; k ++)
					a[n ++] = (Tr){i, j, k};
		int ans = 0;
		for (int w = 0; w < 100000; w ++)
		{
			//rand
			for (int t = 0; t < n*2; t ++){
				int u = rand() % n, v = rand() % n;
				Tr q = a[u]; a[u] = a[v]; a[v] = q;
			}
			//solve
			memset(c, 0, sizeof(c));
			memset(d, 0, sizeof(d));
			memset(b, 0, sizeof(b));
			int cnt = 0;
			for (int i = 0; i < n; i ++)
			{
				int u = a[i].x*p+a[i].y;
				int v = a[i].x*s+a[i].z;
				int w = a[i].y*s+a[i].z;
				if (b[u] == K || c[v] == K || d[w] == K)
					continue;
				tmp[cnt ++] = i;
				b[u] ++; c[v] ++; d[w] ++;
			}
			if (cnt > ans){
				ans = cnt;
				for (int i = 0; i < cnt; i ++)
					best[i] = tmp[i];
			}
		}
		printf("Case #%d: %d\n", t, ans);
		for (int i = 0; i < ans; i ++)
			printf("%d %d %d\n", a[best[i]].x, a[best[i]].y, a[best[i]].z);
	}
	return 0;
}
