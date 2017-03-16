#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1100000;

int n, cur;
int a[MAXN];

int min(int a, int b) { return a < b ? a : b;}

void init()
{
	scanf("%d %d", &cur, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
}

void solve()
{
	if (cur == 1)
	{
		printf("%d\n", n);
		return;
	}
	int ANS = 100;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (cur > a[i]) cur += a[i];
		else
		{
			ANS = min(ANS, ans + n - i + 1);
			while (cur <= a[i])
			{
				++ans;
				cur += cur -1;
			}
			cur += a[i];
		}
		if (cur > MAXN) cur = MAXN;
	}
	ANS = min(ANS, ans);
	printf("%d\n", ANS);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
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
