#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> w[1001];
int in[1001], used[1001];

bool dfs(int x)
{
	bool res = false;
	for (int i = 0; i < w[x].size(); i++)
	  if (used[w[x][i]] == 0)
	  {
		  used[w[x][i]] = 1;
		  res = res | dfs(w[x][i]);
	  }
	  else
	    return true;
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int o = 0; o < t; o++)
	{
		cout<<"Case #" << o + 1 <<": ";
		int n, m;
		cin >> n;
		
		for (int i = 1; i <= n; i++)
		{
			in[i] = 0;
			w[i].clear();
			cin >> m;
			w[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				cin >> w[i][j];
				in[w[i][j]]++;
			}
		}
		bool fl = false;
		for (int i = 1; i <= n; i++)
		  if (in[i] == 0)
		  {
			  for (int j = 1; j<=n; j++)
				  used[j] = 0;
			  used[i]=1;
			  fl = fl | dfs(i);
		  }
		if (fl)
			cout << "Yes"<< endl;
		else
			cout <<"No" << endl;
	}
	return 0;
}