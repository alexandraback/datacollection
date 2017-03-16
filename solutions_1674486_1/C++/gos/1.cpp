#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, T, tmp, tmp2;
int w[1005][1005];
int size[1005];
int flag[1005];
int vis[1005];
bool ans;
bool dfs(int k)
{
	if(vis[k])
		return true;
	vis[k] = 1;
	for(int i = 0; i < size[k]; i++)
	{
		int idx = w[k][i];
		if(dfs(idx))
			return true;
	}
	return false;
}
int main()
{
	freopen("e:\\A-large.in", "r", stdin);
	freopen("e:\\A-large.out", "w", stdout);
	cin >> T;
	for(int Tidx = 1; Tidx <= T; Tidx++)
	{
		cin >> N;
		memset(flag, 0, sizeof(flag));
		memset(size, 0, sizeof(flag));
		memset(w, 0, sizeof(w));
		for(int i = 1; i <= N; i++)
		{
			cin >> size[i];
			for(int j = 0; j < size[i]; j++)
			{
				cin >> w[i][j];
				flag[w[i][j]]++;
			}
		}
		ans = false;
		for(int i = 1; i <= N; i++)
		{
			if(flag[i])
				continue;
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
			{
				ans = true;
				break;
			}
		}
		cout << "Case #" << Tidx << ": ";
		if(ans)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}