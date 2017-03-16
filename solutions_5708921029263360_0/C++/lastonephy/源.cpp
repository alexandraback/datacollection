#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

struct NODE
{
	int x[3];
};

int num[3], k;
vector<struct NODE> ans[3][4][4][4], stac;
int vis[4 * 4 * 4];
int cou[3][4][4][4];

void deal(int j, int p, int s, int cnt)
{
	int flag = 0;
	for (int x1 = 1; x1 <= j; x1++)
	{
		for (int x2 = 1; x2 <= p; x2++)
		{
			if (vis[x1 + x2 * 4] == cnt) continue;
			for (int x3 = 1; x3 <= s; x3++)
			{
				if (vis[x1 + x3 * 4 * 4] == cnt) continue;
				if (vis[x2 * 4 + x3 * 4 * 4] == cnt) continue;
				int sta = x1 + x2 * 4 + x3 * 4 * 4;
				if (vis[sta]) continue;
				vis[sta] ++;
				vis[x1 + x2 * 4]++;
				vis[x1 + x3 * 4 * 4]++;
				vis[x2 * 4 + x3 * 4 * 4]++;
				struct NODE newd;
				newd.x[0] = x1;
				newd.x[1] = x2;
				newd.x[2] = x3;
				stac.push_back(newd);
				flag = 1;
				deal(j, p, s, cnt);
				if (ans[cnt][j][p][s].size() == cou[cnt][j][p][s])return;
				stac.pop_back();
				vis[sta]--;
				vis[x1 + x2 * 4]--;
				vis[x1 + x3 * 4 * 4]--;
				vis[x2 * 4 + x3 * 4 * 4]--;
			}
		}
	}
	if (!flag)
	{
		int size = stac.size();
		int size1 = ans[cnt][j][p][s].size();
		if (size1 < size)
		{
			ans[cnt][j][p][s].clear();
			for (int i = 0; i < size; i++)
			{
				ans[cnt][j][p][s].push_back(stac[i]);
			}
		}
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	memset(cou, -1, sizeof(cou));
	cou[2][2][3][3] = 12;
	cou[2][3][3][3] = 17;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i; j <= 3; j++)
		{
			for (int r = j; r <= 3; r++)
			{
				for (int s = 1; s < 3; s++)
				{
					deal(i, j, r, s);
					memset(vis, 0, sizeof(vis));
					stac.clear();
				}
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		printf("Case #%d: ", ii);
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &num[i]);
		}
		scanf("%d", &k);
		if (k >= 3)
		{
			printf("%d\n", num[0] * num[1] * num[2]);
			for (int i = 1; i <= num[0]; i++)
			{
				for (int j = 1; j <= num[1]; j++)
				{
					for (int r = 1; r <= num[2]; r++)
					{
						printf("%d %d %d\n", i, j, r);
					}
				}
			}
			continue;
		}
		int size = ans[k][num[0]][num[1]][num[2]].size();
		printf("%d\n", size);
		for (int i = 0; i < size; i++)
		{
			printf("%d %d %d\n", ans[k][num[0]][num[1]][num[2]][i].x[0], ans[k][num[0]][num[1]][num[2]][i].x[1], ans[k][num[0]][num[1]][num[2]][i].x[2]);
		}
	}
	return 0;
}