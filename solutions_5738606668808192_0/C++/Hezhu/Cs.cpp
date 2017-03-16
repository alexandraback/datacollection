#include <cstdio>

bool bit[20];
int cnt = 50;

void dfs(int pos)
{
	if (cnt == 0)
		return;
	if (pos == 15)
	{
		for (int i = 0; i < 16; ++i)
			printf("%d", bit[i]);
		puts(" 3 2 5 2 7 2 3 2 7");
		cnt--;
		return;
	}
	dfs(pos + 1);
	if (!bit[pos] && pos <= 11)
	{
		bit[pos] = bit[pos + 3] = 1;
		dfs(pos + 1);
		bit[pos] = bit[pos + 3] = 0;
	}
}

int main()
{
	freopen("cs.out", "w", stdout);
	printf("Case #1:\n");
	bit[0] = bit[15] = 1;
	dfs(1);
	return 0;
}
