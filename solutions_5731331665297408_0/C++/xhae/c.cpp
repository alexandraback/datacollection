#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string postal[50];
vector <int> edge[50];
int n, m;

bool isVisited[50];
string ans;

void dfs(int u)
{
	isVisited[u] = true;
	ans += postal[u];
	while(true)
	{
		int next = -1;
		string minPost;
		for(int v: edge[u])
		{
			if(isVisited[v]) continue;
			if(next == -1)
			{
				next = v;
				minPost = postal[v];
			}
			else if (postal[v] < minPost) { minPost = postal[v]; next = v; }
		}

		if(next == -1) break;
		dfs(next);
	}
}

int main(void)
{
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++) edge[i].clear();
		for(int i = 0; i < n; i++) cin >> postal[i];
		for(int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		memset(isVisited, 0, sizeof(isVisited));
		int s = 0;
		string minPost = postal[0];
		for(int i = 1; i < n; i++) 
			if(postal[i] < minPost)
			{
				minPost = postal[i];
				s = i;
			}

		ans = "";
		dfs(s);

		cout << "Case #" << kase << ": " << ans << endl;
	}

	return 0;
}
