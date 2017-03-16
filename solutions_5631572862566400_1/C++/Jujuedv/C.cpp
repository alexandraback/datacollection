#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sing(int v, vector<vector<int>> &bby, vector<int> &vis)
{
	if(vis[v] != -1)
		return vis[v];
	vis[v] = 1;
	for(auto w : bby[v])
		vis[v] = max(vis[v], sing(w, bby, vis) + 1);

	return vis[v];
}

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		vector<int> bffs(N);
		for(auto &b : bffs)
		{	
			cin >> b;
			--b;
		}

		vector<vector<int>> bby(N);
		for(int i = 0; i < N; ++i)
			bby[bffs[i]].push_back(i);

		int best = 0, singular = 0;
		vector<bool> skip(N);
		for(int i = 0; i < N; ++i)
		{
			if(skip[i])
				continue;

			int count = 1;
			int c = bffs[i];
			while(c != i && count < 2 * N)
			{
				++count;
				c = bffs[c];
			}
			if(count == 2)
			{
				c = bffs[i];
				vector<int> vis(N, -1);
				vis[c] = 0;
				singular += sing(i, bby, vis);
				vis[i] = 0;
				vis[c] = -1;
				singular += sing(c, bby, vis);
				skip[i] = skip[c] = true;
			}
			else if(c == i)
			{
				best = max(best, count);
			}
		}
		best = max(best, singular);
		cout << "Case #" << t << ": " << best << endl;
	}
}
