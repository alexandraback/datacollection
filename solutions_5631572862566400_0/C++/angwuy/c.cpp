#include <cstdio>
#include <cstring>

const int MAXN = 2550;

struct Tedge{
	int p, next;
};

int n;
int a[MAXN];
int f[MAXN];
Tedge edge[MAXN];
int dep[MAXN];
int dis[MAXN][MAXN], l[MAXN][MAXN];
int ans;

void calc(int v)
{
	memset(dep, 0xff, sizeof(dep));
	int cur = f[v];
	int last = v;
	int d = 1;
	dep[v] = 0;
	while (dep[cur] < 0)
	{
		dep[cur] = 0;
		++d;
		dis[v][cur] = d;
		l[v][cur] = last;
		last = cur;
		cur = f[cur];
	}
	if (cur == v && d - 1 > ans) ans = d;
}

void find(int v)
{
	int bd = -1;
	for (int i = 1; i <= n; ++i)
	if (dis[i][v] > bd && l[i][v] == f[v])
		bd = dis[i][v];
	if (bd < 0) return;
	int sum = bd;
	bd = -1;
	for (int i = 1; i <= n; ++i)
	if (dis[i][v] > bd && l[i][v] != f[v])
		bd = dis[i][v];
	if (bd > 0)
		sum += bd - 1;
	if (sum > ans) ans = sum;
}

bool chk(int l, int r)
{
	for (int i = l; i <= r; ++i)
	if (f[a[i]] != a[i - 1] && f[a[i]] != a[i + 1])
		return false;
	return true;
}

void dfs(int d)
{
	/*for (int i = 1; i < d; ++i)
		printf("%d ", a[i]);
	printf("\n");*/
	if (d > n) return;
	for (int i = 1; i <= n; ++i)
	if (dep[i] == 0)
	{
		dep[i] = 1;
		a[d] = i;
		a[0] = i;
		a[d + 1] = a[1];
		if (chk(1, d) && d > ans) ans = d;
		if (chk(2, d - 1))
			dfs(d + 1);
		dep[i] = 0;
	}
}

void solve()
{
	scanf("%d", &n);
	int len = 0;
	memset(a, 0xff,sizeof(a));
	for (int i = 1; i <= n; ++i)
	{
		int j;
		scanf("%d", &j);
		edge[++len].p = j;
		edge[len].next = a[i];
		a[i] = len;
		edge[++len].p = i;
		edge[len].next = a[j];
		a[j] = len;
		f[i] = j;
	}
	
	if (n <= 10)
	{
		memset(dep, 0, sizeof(dep));
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			dep[i] = 1;
			a[1] = i;
			dfs(2);
			dep[i] = 0;
		}
		printf("%d\n",ans);
		return;
	}
	
	memset(dis, 0xff, sizeof(dis));
	memset(l, 0xff, sizeof(l));
	
	ans = 0;
	for (int i = 1; i <= n; ++i)
		calc(i);
	for (int i = 1; i <= n; ++i)
		find(i);
	
	printf("%d\n",ans);
}



int main()
{
	freopen("c.in", "r", stdin);
	int tt;
	scanf("%d\n", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}