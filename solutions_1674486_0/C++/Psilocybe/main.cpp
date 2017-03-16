#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int MAXN = 1001;

bool ispath[MAXN][MAXN];

int n;

vector<int> g[MAXN];

int use[MAXN];

bool dfs(int v)
{
	if(use[v])
		return true;
	use[v] = 1;
	for(int i=0;i<g[v].size();i++)
		if(dfs(g[v][i]))
			return true;
	return false;
}



int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	cin>>T;
	for(int test=0;test<T;test++)
	{
		cin>>n;

		for(int i=0;i<n;i++)
			g[i].clear();

		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				int v;
				cin>>v;
				g[v-1].push_back(i);
			}
		}
		string ans = "No";

		for(int i=0;i<n;i++)
		{
			memset(use,0,sizeof(use));
			if(dfs(i))
				ans = "Yes";
		}

		cout<<"Case #"<<test+1<<": "<<ans<<endl;
	}

		
	return 0;
}