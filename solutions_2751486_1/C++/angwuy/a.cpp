#include <cstdio>
#include <cstring>

const int MAXN = 1000010;

bool chk[200];
int n, m;
int a[MAXN];
int b[MAXN];
char s[MAXN];

void init()
{
	scanf("%s %d\n",s + 1, &m);
	n = strlen(s + 1);
	memset(a, 0, sizeof(a));
	memset(chk, 0, sizeof(chk));
	chk['a'] = chk['e'] = chk['i'] = chk['o'] = chk['u'] = true;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; ++i)
	if (!chk[s[i]]) a[i] = 1;
	for (int i = 1; i <= n; ++i)
	if (a[i]) a[i] += a[i - 1];
	for (int i = 1; i <= n; ++i)
	if (a[i] >= m) b[i] = 1;
	a[n + 1] = n + 1;
	for (int i = n; i >= 1; --i)
	if (b[i]) a[i] = i;
	else a[i] = a[i + 1];
	a[0] = a[1];
	
}

int find(int k)
{
	int l = 1, r = n, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void solve()
{
	int ans = 0;
	int t;
	for (int i = 1; i <= n; ++i)
	if (i + m - 1 <= n)
	{
		t = a[i + m - 1];
		if (t <= n) ans += n - t + 1;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}