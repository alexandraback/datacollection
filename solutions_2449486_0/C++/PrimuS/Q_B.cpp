#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int matrix[110][110];
int max_col[110];
int max_row[110];

int n, m;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-result.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		memset(matrix, 0, sizeof(matrix));
		memset(max_col, 0, sizeof(max_col));
		memset(max_row, 0, sizeof(max_row));

		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int y;
				scanf("%d", &y);
				matrix[i][j] = y;
				max_col[j] = std::max(max_col[j], y);
				max_row[i] = std::max(max_row[i], y);
			}
		}

		bool ok = true;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (matrix[i][j] < max_col[j] && matrix[i][j] < max_row[i])
					ok = false;
			}
		}
		printf("Case #%d: %s", t + 1, ok ? "YES" : "NO");


		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}