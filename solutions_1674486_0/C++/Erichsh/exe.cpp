#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <string>
using namespace std;

int m[2000][2000];int n;	

bool f()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (k != i && k != j)
				{
					if (m[i][j] && (m[i][k] && m[k][j]))	return 1;
					m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
				}
	return 0;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;		scanf("%d", &tc);
	for (int T = 1; T <= tc; T++)
	{
		printf("Case #%d: ", T);
		
		memset(m, 0, sizeof(m));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;	scanf("%d", &x);
			while (x--)
			{
				int v; scanf("%d", &v);		m[i][v] = 1;
			}
		}
		if (f())	printf("Yes\n");
		else		printf("No\n");

	}
}