#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<int> dat[105];
pair<int, int> nth[105];
bool used[105];

int org[55][55];
int emp;

bool tryit()
{
	for (int i = 0; i < N; i++)
	{
		if (nth[i].first == -1) return false;
		for (int j = 0; j < N; j++)
		{
			org[i][j] = dat[nth[i].first][j];
			if (i > 0 && org[i - 1][j] >= org[i][j])
				return false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (nth[i].second == -1) continue;
		for (int j = 0; j < N; j++)
		{
			if (org[j][i] != dat[nth[i].second][j]) return false;
		}
	}
	return true;
}

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\B-small-attempt2.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\B-small.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 105; i++) dat[i].clear();
		printf("Case #%d: ", tt);

		scanf("%d", &N);
		for (int i = 0; i < 2 * N - 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				dat[i].push_back(tmp);
			}
		}

		emp = -1;

		for (int i = 0; i < N; i++)
		{
			vector<int> mins;
			for (int j = 0; j < 2 * N - 1; j++)
			{
				if (used[j]) continue;
				if (mins.empty()) mins.push_back(j);
				else if (dat[mins[0]][i] < dat[j][i]) continue;
				else
				{
					if (dat[mins[0]][i] > dat[j][i]) mins.clear();
					mins.push_back(j);
				}
			}

			if (mins.size() == 1)
			{
				nth[i] = { mins[0], -1 };
				emp = i;
				used[mins[0]] = true;
			}
			else
			{
				nth[i] = { mins[0], mins[1] };
				used[mins[0]] = used[mins[1]] = true;
			}
		}

		int foo;
		for (int i = 0; i < (1 << N); i++)
		{
			foo = i;
			for (int j = 0; j < N; j++)
			{
				if (i & (1 << j))
				{
					swap(nth[j].first, nth[j].second);
				}
			}

			if (tryit()) break;

			for (int j = 0; j < N; j++)
			{
				if (i & (1 << j))
				{
					swap(nth[j].first, nth[j].second);
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			printf("%d ", org[i][emp]);
		}
		printf("\n");
	}
}