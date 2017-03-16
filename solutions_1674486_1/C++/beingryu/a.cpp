#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > adj;
vector<int> did;
int ans;

void dfs(int pl)
{
	if (did[pl])
	{
		ans = true;
		return;
	}
	did[pl] = true;
	for (int i = 0;i < adj[pl].size();i++)
		dfs(adj[pl][i]);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		ans = false;

		int N;
		scanf("%d", &N);
		adj = vector< vector<int> >(N);
		for (int i = 0;i < N;i++)
		{
			int c;
			scanf("%d", &c);
			for (;c;c--)
			{
				int v;
				scanf("%d", &v);
				adj[i].push_back(v - 1);
			}
		}

		for (int i = 0;i < N;i++)
		{
			did = vector<int>(N);
			dfs(i);
			if (ans) break;
		}

		printf("Case #%d: %s\n", ti, ans ? "Yes" : "No");
	}
}
