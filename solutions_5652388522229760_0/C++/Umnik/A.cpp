#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool used[11];

void add(int x)
{
	while(x > 0)
	{
		used[x % 10] = 1;
		x /= 10;
	}
	return;
}

bool check()
{
	for (int i = 0; i < 10; i++)
		if (!used[i])
			return false;
	return true;
}

void solve(int x)
{
	if (x == 0)
	{
		printf("INSOMNIA\n");
		return;
	}
	for (int i = 0; i < 10; i++)
		used[i] = false;
	int y = 0;
	while(true)
	{
		y += x;
		add(y);
		if (check())
		{
			printf("%d\n", y);
			return;
		}
	}
	throw;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		int n;
		scanf("%d", &n);
		solve(n);
	}

	return 0;
}