#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i, x) for(int i = 0; i < (x); i++)
#define SZ(x) (int)x.size()
const int MAXN = 2000 + 10;

int n;
vector<int> adj[MAXN];
int cnt[MAXN];
int tar;

int dfs(int x)
{
	int &ret = cnt[x];
	if(ret != -1)
		return ret;
	ret = (x == tar);
	FOR(i, SZ(adj[x]))
	{
		int v = adj[x][i];
		ret += dfs(v);
	}
	return ret;
}

int main() 
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		memset(adj, 0, sizeof adj);
		cin >> n;
		FOR(i, n)
		{
			adj[i].clear();
			int m;
			cin >> m;
			FOR(j, m)
			{
				int d;
				cin >> d;
				d--;
				adj[i].push_back(d);
			}
		}

		cout << "Case #" << T + 1 << ": ";
		bool has = false;
		FOR(i, n)
		{
			tar = i;
			memset(cnt, -1, sizeof cnt);
			FOR(j, n)
				if(dfs(j) > 1)
					has = true;
		}
		cout << (has ? "Yes" : "No") << endl;
	}

	return 0;
}
