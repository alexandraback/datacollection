#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Edge
{
	int availableFrom;
	int slowerFrom;
	int u;
	int v;
	Edge(int _u, int _v, int _a, int _s) : availableFrom(_a), slowerFrom(_s), u(_u), v(_v) {}
	Edge() : availableFrom(0), slowerFrom(0), u(0), v(0) {}
};

struct Node
{
	int n;
	int d;
	Node() : n(0), d(0) {}
	Node(int _n, int _d) : n(_n), d(_d) {}
};

struct mycomparison
{
  bool operator() (const Node& lhs, const Node& rhs) const
  {
    return ((lhs.d > rhs.d) || ((lhs.d == rhs.d) && (lhs.n > rhs.n)));
  }
};

const int INF = -1;

const int delta[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

int main()
{
	ifstream fin("b2.txt");
	ofstream fout("b2_sol.txt");

	int t;
	fin >> t;
	int f[100][100];
	int c[100][100];
	for ( int tt = 1; tt <= t; ++tt )
	{
		int h,n,m;
		fin >> h >> n >> m;
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j )
			{
				fin >> c[i][j];
			}
		}
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j )
			{
				fin >> f[i][j];
			}
		}

		vector< vector<Edge> > e(n*m);
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j ) if ( c[i][j] - f[i][j] >= 50 )
			{
				for ( int k = 0; k < 4; ++k )
				{
					int x = i + delta[k][0];
					int y = j + delta[k][1];
					if ( (x >= 0) && (x < n) && (y >= 0) && (y < m) &&
						(c[x][y] - f[x][y] >= 50) && (c[x][y] - f[i][j] >= 50) && (c[i][j] - f[x][y] >= 50) )
					{
						Edge ne(i*m+j, x*m+y, 0, 0);
						if ( h > (c[x][y] - 50) ) ne.availableFrom = h - (c[x][y] - 50);
						if ( h > (f[i][j] + 19) ) ne.slowerFrom = h - (f[i][j] + 19);
						e[i*m+j].push_back(ne);
					}
				}
			}
		}

		vector<int> dist(n*m, INF);
		priority_queue<Node, vector<Node>, mycomparison> prique;
		{
			vector<bool> visited(n*m, false);
			stack<int> verem;
			visited[0] = true;
			dist[0] = 0;
			prique.push(Node(0,0));
			verem.push(0);
			while ( !verem.empty() )
			{
				int u = verem.top();
				verem.pop();
				for ( unsigned i = 0; i < e[u].size(); ++i )
				{
					if ( e[u][i].availableFrom == 0 && !visited[e[u][i].v] )
					{
						visited[e[u][i].v] = true;
						dist[e[u][i].v] = 0;
						prique.push(Node(e[u][i].v,0));
						verem.push(e[u][i].v);
					}
				}
			}
		}

		vector<bool> visited(n*m, false);
		int goal = n*m-1;
		while ( !prique.empty() && !visited[goal] )
		{
			int u = prique.top().n;
			int tm = prique.top().d;
			prique.pop();
			if ( visited[u] ) continue;
			visited[u] = true;
			for ( unsigned i = 0; i < e[u].size(); ++i ) if ( !visited[e[u][i].v] )
			{
				int baseline = (tm > e[u][i].availableFrom ? tm : e[u][i].availableFrom);
				int newtm = baseline + (baseline < e[u][i].slowerFrom ? 10 : 100);
				if ( (dist[e[u][i].v] == INF) || (dist[e[u][i].v] > newtm) )
				{
					dist[e[u][i].v] = newtm;
					prique.push(Node(e[u][i].v, newtm));
				}
			}
		}

		fout <<"Case #" << tt << ": " << (((double)dist[goal]) / 10.0) << "\n";
	}

	fin.close();
	fout.close();
}