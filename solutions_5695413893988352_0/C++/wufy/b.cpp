#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int f[2][3];
int ans[2];
int n;

void make(int *f)
{
	char st[10];
	scanf("%s", st);
	n = strlen(st);
	for (int i = 0; i < n; i++)
	{
		if (st[i] == '?')
			f[n - i - 1] = -1;
		else
			f[n - i - 1] = st[i] - '0';
	}
}

void input()
{
	make(f[0]);
	make(f[1]);
}

bool ok(int * f, int a)
{
	int g[3];

	for (int i = 0; i < n; i++)
	{
		g[i] = a % 10;
		a /= 10;
	}

	for (int i = 0; i < n; i++)
	{
		if (f[i] == -1)
			continue;
		if (g[i] != f[i])
			return false;
	}
	return true;
}

void work()
{
	ans[0] = 10000;
	ans[1] = 20000;
	int temp = 1000;
	if (n == 2)
		temp = 100;
	if (n == 1)
		temp = 10;
	for (int i = 0; i < temp; i++)
	{
		if (!ok(f[0], i))
			continue;
		for (int j = 0; j < temp; j++)
		{
			if (!ok(f[1], j))
				continue;
			int diff = abs(i - j);
			if (diff < abs(ans[0] - ans[1]))
			{
				ans[0] = i;
				ans[1] = j;
				continue;
			}
			if (diff > abs(ans[0] - ans[1]))
			{
				continue;
			}
			if (i < ans[0] || j < ans[1])
			{
				ans[0] = i;
				ans[1] = j;
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		input();
		work();
		if (n == 3)
			printf("%03d %03d\n", ans[0], ans[1]);
		else if (n == 2)
			printf("%02d %02d\n", ans[0], ans[1]);
		else
			printf("%d %d\n", ans[0], ans[1]);
	}
	return 0;
}
