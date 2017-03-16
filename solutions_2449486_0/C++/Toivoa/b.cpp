#include <iostream>
#include <cstdio>

using namespace std;

int t;
int n, m;
int a[100][100];
int cases;

bool solve()
{
	/*
	for (int l = 100; l > 0; --l)
	{
	*/
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
	/*
				if (a[i][j] != l)
					continue;
	*/
				bool b1 = true, b2 = true;
				for (int k = 0; k < m; ++k)
				{
					if (a[i][j] < a[i][k])
					{
						b1 = false;
						break;
					}
				}
				for (int k = 0; k < n; ++k)
				{
					if (a[i][j] < a[k][j])
					{
						b2 = false;
						break;
					}
				}

				if (b1 == false && b2 == false)
					return false;
			}
		}
	/*
	}
	*/
	return true;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}

		printf("Case #%d: ", ++cases);
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
}