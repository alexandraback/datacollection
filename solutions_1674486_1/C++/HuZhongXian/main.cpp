#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <queue>
using namespace std;

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "A-large.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int par[1001][12];
	int son[1001];
	int cnt[1001];
	int T, N, M;
	fscanf(input, "%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		memset(son, 0, sizeof(son));
		fscanf(input, "%d", &N);
		for (int j = 1; j <= N; ++j)
		{
			fscanf(input, "%d", &par[j][0]);
			for (int k = 1; k <= par[j][0]; ++k)
			{
				fscanf(input, "%d", &par[j][k]);
				++son[par[j][k]];
			}
		}
		bool no = true;
		for (int j = 1; no && j <= N; ++j)
			if (son[j] == 0)
			{
				memset(cnt, 0, sizeof(cnt));
				queue <int> q;
				q.push(j);
				while (no && !q.empty())
				{
					int t = q.front();
					q.pop();
					for (int k = 1; k <= par[t][0]; ++k)
					{
						++cnt[par[t][k]];
						if (cnt[par[t][k]] > 1)
						{
							no = false;
							break;
						}
						q.push(par[t][k]);
					}
				}
			}
		fprintf(output, "Case #%d: %s\n", i, no ? "No" : "Yes");
	}

	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}