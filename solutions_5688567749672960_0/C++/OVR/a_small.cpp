#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool flag[1000009];
queue< pair<int, int> > q;

int reverseNumber(int x)
{
	int result = 0;

	while (x > 0)
	{
		result = 10 * result + x % 10;
		x /= 10;
	}

	return result;
}

void consider(int x, int y)
{
	if (flag[x])
	{
		return;
	}

	flag[x] = true;
	q.push(make_pair(x, y));
}

int solve(int n)
{
	while (!q.empty())
	{
		q.pop();
	}

	for (int i = 1; i <= n; i++)
	{
		flag[i] = false;
	}

	pair<int, int> x = make_pair(1, 1);

	while (x.first != n)
	{
		consider(x.first + 1, x.second + 1);
		consider(reverseNumber(x.first), x.second + 1);

		x = q.front();
		q.pop();
	}

	return x.second;
}

int main()
{
	int testCount;

	scanf("%d", &testCount);

	for (int test = 1; test <= testCount; test++)
	{
		int n;

		scanf("%d", &n);
		printf("Case #%d: %d\n", test, solve(n));
	}

	return 0;
}