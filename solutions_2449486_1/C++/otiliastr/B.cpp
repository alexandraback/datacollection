#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define NMAX 102
int a[NMAX][NMAX];

string solve(int n, int m)
{
	int maxlin[NMAX],maxcol[NMAX];
	memset(maxlin,0,sizeof(maxlin));
	memset(maxcol,0,sizeof(maxcol));
	
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<m; ++j)
		{
			maxlin[i] = max(maxlin[i],a[i][j]); 
			maxcol[j] = max(maxcol[j],a[i][j]); 
		}
		
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<m; ++j)
			if (a[i][j]<maxlin[i] && a[i][j]<maxcol[j])
				return "NO";
	return "YES";
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin>>a[i][j];
		cout<<"Case #"<<t<<": "<<solve(n,m)<<"\n";
	}
	return 0;
}
