#include <iostream>
using namespace std;

int curans[105][105];
int v[105];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);
		int ans = 0;
		
		for (int i = 0; i < n; i++)
		{
			memset(curans[i + 1], 0, sizeof curans[i + 1] );
			scanf("%d", &v[i] );
			for (int a = 0; a <= e; a++)
			{
				for (int j = 0; j <= a; j++)
				{
					int x = j * v[i];
					curans[i + 1][min(e, a - j + r) ] = max(curans[i + 1][min(e, a - j + r) ], curans[i][a] + x);
					ans = max(ans, curans[i + 1][min(e, a - j + r) ] );
				}
			}
		}
		printf("Case #%d: %d\n", t + 1, ans);
	}
}