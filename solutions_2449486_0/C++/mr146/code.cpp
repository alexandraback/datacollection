#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;


vector<pair<int, pair<int, int> > > v;
int a[146][146];
int hcol[146], hrow[146];


bool solve()
{
	v.clear();
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			v.push_back(make_pair(a[i][j], make_pair(i, j)));
		}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	memset(hcol, -1, sizeof(hcol));
	memset(hrow, -1, sizeof(hrow));
	for(int i = 0; i < v.size(); i++)
	{
		int val = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;
		if(hcol[x] > val && hrow[y] > val)
			return false;
		if(hcol[x] == -1)
			hcol[x] = val;
		if(hrow[y] == -1)
			hrow[y] = val;
	}
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		printf("Case #%d: %s\n", i + 1, solve() ? "YES" : "NO");
}