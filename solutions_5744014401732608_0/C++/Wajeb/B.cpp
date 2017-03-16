#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > adjList;
int findWays(vector<vector<int> > v);
int solve(int src, int dest, string vis);

int main()
{
	map<pair<int, int>, vector<vector<int> > > mp;
	for(int b = 2; b <= 6; b++)
	{
		int tot;
		if(b == 2) tot = 1;
		if(b == 3) tot = 3;
		if(b == 4) tot = 6;
		if(b == 5) tot = 10;
		if(b == 6) tot = 15;

		vector<int> last;
		for(int i = 0; i < b; i++) last.push_back(0);

		int upto = 1 << tot;
		for(int x = 1; x < upto; x++)
		{
			vector<vector<int> > grid;

			int y = x;
			for(int i = 0; i < b - 1; i++)
			{
				vector<int> row;
				for(int j = 0; j < i + 1; j++) row.push_back(0);
				for(int j = i + 1; j < b; j++)
				{
					row.push_back(y & 1);
					y = y >> 1;
				}
				grid.push_back(row);
			}
			grid.push_back(last);

			int ways = findWays(grid);
			if(ways <= 20 && ways > 0) mp[make_pair(b, ways)] = grid;
		}
	}

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{

		int B, M;
		cin >> B >> M;

		string res;
		string possible = "POSSIBLE";
		string impossible = "IMPOSSIBLE";

		if(mp.count(make_pair(B, M)) > 0) res = possible;
		else res = impossible;

		cout << "Case #" << t << ": " << res << endl;
		if(res == possible)
		{
			for(int i = 0; i < B; i++)
			{
				for(int j = 0; j < B; j++)
				{
					cout << mp[make_pair(B, M)][i][j];
				}
				cout << endl;
			}
		}
	}

	return 0;
}

int findWays(vector<vector<int> > v)
{
	adjList.clear();
	for(int i = 0; i < v.size(); i++)
	{
		vector<int> neighbors;
		for(int j = 0; j < v.size(); j++)
		{
			if(v[i][j] == 1) neighbors.push_back(j);
		}
		adjList.push_back(neighbors);
	}

	return solve(0, v.size() - 1, "000000");
}

int solve(int src, int dest, string vis)
{
	if(src == dest) return 1;
	if(vis[src] == '1') return 50;

	vis[src] = '1';

	int res = 0;
	for(int i = 0; i < adjList[src].size(); i++)
	{
		res += solve(adjList[src][i], dest, vis);
	}

	return res;
}