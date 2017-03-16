
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m, k;
int last;
bool map[1024][1024];

int Dx[] = { 1, -1, 0, 0 }, Dy[] = { 0, 0, 1, -1 }, Deltas = 4;

int run(int status)
{
	{
		int i = 0, j = 0;
		for (int s = 1; s < last; s <<= 1)
		{
			map[i][j] = status & s;

			j++;
			if (j >= m)
			{
				j = 0;
				i++;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//printf("%c", map[i][j] ? '*' : '.');
			if (map[i][j])
			{
				bool flag = false;
				for (int delta = 0; delta < Deltas; delta++)
				{
					int p = Dx[delta] + i, q = Dy[delta] + j;
					if ((0 <= p && p < n && 0 <= q && q < m) == false)
					{
						flag = true;
						break;
					}
					if (!map[p][q])
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					count++;
				}
			}
		}
		//printf("\n");
	}
	//printf("%d\n", count);
	return count;
}

int testCase()
{
	cin >> n >> m >> k;

	int answer = INT_MAX;
	last = 1 << (n * m);

	for (int status = 0; status < last; status++)
	{
		int count = 0;
		int m;
		for (m = 1; m < last; m <<= 1)
		{
			if (status & m)
			{
				count++;
				if (count > k)
				{
					break;
				}
			}
		}
		if (m < last || count != k)
		{
			continue;
		}

		int current = run(status);
		answer = min(answer, current);
	}
	return answer;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %d\n", i, testCase());
	}

	return 0;
}