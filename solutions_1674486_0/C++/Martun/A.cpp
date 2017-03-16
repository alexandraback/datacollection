#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int n;
bool d[1010];
//int ind[1010];

vector< vector<int> > graph;
bool g[1010][1010];

bool Answer_is_YES;
bool oper_less(const int& a, const int& b)
{
	if (g[a][b])
		return true;
	return false;
}
void read()
{
	int i, m, j;
	cin >> n;
	graph.clear();
	graph.resize(n);
	memset( g, false, sizeof(g) );
	for (i = 0; i < n; ++i)
	{
		cin >> m;
		graph[i].resize(m);
		for (j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
			--graph[i][j];
			g[i][graph[i][j]] = true;
		}
	}
}
void rec(int i1)
{
	int i;
	for (i = 0; i < graph[i1].size(); ++i)
	{
		if (d[graph[i1][i]] == false)
		{
			d[graph[i1][i]] = true;
			rec(graph[i1][i]);
		}
		else
		{
			Answer_is_YES = true;
			break;
		}
	}
}

void solve()
{
	Answer_is_YES = false;
	int i, j, k;

	/// Topologically sort the vertices.
	//sort(ind, ind + n, oper_less);
	
	for (i = n - 1; i >= 0; --i)
	{
		memset(d, false, sizeof(d));
		rec(i);
		if (Answer_is_YES)
		{
			std::cout << "Yes\n";
			return ;
		}
	}
	std::cout << "No\n";
} 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	int i;
	for (i = 1; i <= t; ++i)
	{
		read();
		std::cout << "Case #" << i << ": ";
		solve();
	}
}