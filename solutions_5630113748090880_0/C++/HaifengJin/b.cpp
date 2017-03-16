#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_H = 2600;
const int MAX_N = 100;

int cnt[MAX_H];
int n;
int f[MAX_N];
int f_num;

void input()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
	}
}

void work()
{
	f_num = 0;
	for (int i = 1; i <= 2500; i++)
	{
		if (cnt[i] % 2 != 0)
			f[f_num++] = i;
	}
}

void output()
{
	for (int i = 0; i < f_num; i++)
	{
		printf(" %d", f[i]);
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d:", case_num);
		input();
		work();
		sort(f, f + f_num);
		output();
	}
	return 0;
}
