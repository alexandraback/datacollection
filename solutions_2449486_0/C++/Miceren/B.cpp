#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200;
const int inf = 20000000;

int N, M;
int mat[MAXN][MAXN];
int col[MAXN], row[MAXN];

int calc()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &mat[i][j]);
	for(int i = 1; i <= N; i++)
	{
		row[i] = -1;
		for(int j = 1; j <= M; j++)
			row[i] = max(row[i], mat[i][j]);
	}
	for(int i = 1; i <= M; i++)
	{
		col[i] = -1;
		for(int j = 1; j <= N; j++)
			col[i] = max(col[i], mat[j][i]);
	}
	for(int i = 1; i <= N; i++)	
		for(int j = 1; j <= M; j++)
			if (mat[i][j] < col[j] && mat[i][j] < row[i])
				return 0;
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		if (calc())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
