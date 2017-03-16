#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


bool used[1146];
vector<int> v[1146];


bool dfs(int e)
{
	used[e] = true;
	bool result = true;
	for(int i = 0; i < v[e].size(); i++)
		if(!used[v[e][i]])
			result &= dfs(v[e][i]);
		else
			result = false;
	return result;
}


void solve(int tc)
{
	printf("Case #%d: ", tc + 1);
	int n;
	scanf("%d", &n);
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		m += x;
		for(int j = 0; j < x; j++)
		{
			int a;
			scanf("%d", &a);
			a--;
			v[i].push_back(a);
		}
	}
	memset(used, false, sizeof(used));
	bool good = true;
	for(int i = 0; i < n; i++)
	{
		memset(used, false, sizeof(used));
		if(!dfs(i))
			good = false;
	}

	if(good)
		printf("No\n");
	else
		printf("Yes\n");
	for(int i = 0; i < n; i++)
		v[i].clear();
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		solve(i);
	}
}