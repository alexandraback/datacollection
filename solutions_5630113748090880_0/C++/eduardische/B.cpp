#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAXN 105

using namespace std;

static vector<int> data[MAXN];

static int chosen[MAXN];
static char b[MAXN];

int N;

char DFS (int point, int cur)
{
	if (cur == N)
	{
		int skipped = -1;
		int col = 0;
		for (int i = 0; i < 2*N-1; i++)
		{
			if (!b[i])
			{
				while (1)
				{
					char isOK = 1;
					for (int j = 0; j < N; j++)
					{
						if (data[i][j] != data[chosen[j]][col])
						{
							isOK = 0;
							break;
						}
					}
					if (!isOK)
					{
						if (skipped != -1) return 0;
						skipped = col;
						col++;
					}
					else
					{
						col++;
						break;
					}
				}
			}
		}
		if (skipped == -1) skipped = N-1;
		for (int j = 0; j < N; j++)
		{
			printf(" %d",data[chosen[j]][skipped]);
		}
		return 1;
	}
	else if (point == 2*N-1)
	{
		return 0;
	}
	else
	{
		if (DFS(point+1, cur)) return 1;
		chosen[cur] = point;
		b[point] = 1;
		if (DFS(point+1, cur+1)) return 1;
		b[point] = 0;
		return 0;
	}
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		scanf("%d",&N);
		int i, j;
		for (i = 0; i < 2*N-1; i++)
		{
			data[i].clear();
			for (j = 0; j < N; j++)
			{
				int temp;
				scanf("%d",&temp);
				data[i].push_back(temp);
			}
		}

		sort(data, data+(2*N-1));

		memset(b,0,sizeof(b));
		printf("Case #%d:", iT+1);
		DFS(0,0);
		printf("\n");
	}
	return 0;
}
