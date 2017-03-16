#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

int table[1000005];

void init()
{
	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	table[1] = 1;

	while (!Q.empty())
	{
		pair<int, int> now = Q.front(); Q.pop();
		if (now.first + 1 <= 1000000 && table[now.first + 1] == 0)
		{
			Q.push({ now.first + 1, now.second + 1 });
			table[now.first + 1] = now.second + 1;
		}
		int rev = 0, asc = now.first;
		while (asc)
		{
			rev = rev * 10 + (asc % 10);
			asc /= 10;
		}
		if (rev <= 1000000 && table[rev] == 0)
		{
			Q.push({ rev, now.second + 1 });
			table[rev] = now.second + 1;
		}
	}
	return;
}

int main()
{
	init();

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", cn, table[n]);
	}
}