#include <iostream>
using namespace std;

int a[105][105], row[105], column[105];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: ", t + 1);
		int n, m;
		scanf("%d%d" ,&n, &m);

		memset(row, 0, sizeof row);
		memset(column, 0, sizeof column);


		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j] );
				row[i] = max(row[i], a[i][j] );
				column[j] = max(column[j], a[i][j] );
			}
		bool good = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != min(row[i], column[j] ) )
					good = false;
			}
		if (good)
			printf("YES");
		else
			printf("NO");



		printf("\n");
	}



	return 0;
}