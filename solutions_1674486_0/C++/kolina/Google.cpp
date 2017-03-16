#include <vector>
#include <iostream>

using namespace std;

bool b;
vector <vector <int> > g;
vector <bool> used;

void dfs(int i)
{
	used[i]=true;
	for (int j=0; j<(int)g[i].size(); ++j)
	{
		if (used[g[i][j]])
			b=true;
		else
			dfs(g[i][j]);
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >>t;
	for (int i=0; i<t; ++i)
	{
		cout <<"Case #" <<i+1 <<": ";
		int n;
		cin >>n;
		vector <int> count(n,0);
		g.clear();
		g.resize(n);
		for (int j=0; j<n; ++j)
		{
			int x;
			cin >>x;
			for (int k=0; k<x; ++k)
			{
				int y;
				cin >>y;
				g[j].push_back(y-1);
				count[y-1]++;
			}
		}
		bool c=false;
		used.clear();
		used.resize(n,false);
		for (int j=0; j<n; ++j)
			if (!count[j])
			{
				b=false;
				dfs(j);
				if (b)
				{
					cout <<"Yes";
					c=true;
					break;
				}
				used.clear();
				used.resize(n,false);
			}
		if (!c)
			cout <<"No";
		cout <<endl;
	}
	return 0;
}