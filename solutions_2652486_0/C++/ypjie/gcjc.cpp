#include <stdio.h>
#include <string.h>
using namespace std;

const int M = 1<<10;
const int N = 3 +10;

bool flag[M];

int len;
int m;
int n;
int nowtd;
int tdnum;
int a[N];
int b[N];
int ans[N];

void ri()
{
	int i;
	
	memset(flag, false, sizeof(flag));
	for (i = 0; i < len; i++) scanf("%d", &b[i]);
}

bool judge()
{
	int i;
	int j;
	int k;
	int tt;
	
	memset(flag, false, sizeof(flag));
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) for (k = 0; k < 2; k++)
	{
		tt = 1;
		if (i) tt *= a[0];
		if (j) tt *= a[1];
		if (k) tt *= a[2];
		flag[tt] = true;
	}
	for (i = 0; i < len; i++) if (!flag[b[i]]) return false;
	return true;
}

void dfs(int deep)
{
	int i;
	
	if (deep == n)
	{
		if (judge())
			for (i = 0; i < n; i++) ans[i] = a[i];
			judge();
		return;
	}
	for (i = 2; i <= m; i++)
	{
		a[deep] = i;
		dfs(deep + 1);
	}
}

void print()
{
	int i;
	
	for (i = 0; i < n; i++) printf("%d", ans[i]);
	printf("\n");
}

int main()
{
	scanf("%d", &nowtd);
	printf("Case #1:\n");
	scanf("%d%d%d%d", &tdnum, &n, &m, &len);
	for (nowtd = 1; nowtd <= tdnum; nowtd++)
	{
		ri();
		dfs(0);
		print();
	}
	return 0;
}
