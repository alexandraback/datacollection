#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int t, count0, n, m, index;
string s[55];
int v[55][55];
vector<int> g;
bool used[55];
string ans;

int check(int x)
{
	if (index==n)
		return -1;
	bool ok=true;
	while(ok)
	{
		ok=false;
		if (v[x][g[index]-1]==1)
		{
			++index;
			ok=true;
			if (check(g[index-1]-1)==-1)
				return -1;
		}
	}
	return 0;
}
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++count0<<": ";
		cin>>n>>m;
		ans="";
		getline(cin, s[0]);
		for(int i=0; i<n; ++i)
			getline(cin, s[i]);
		memset(v, 0, sizeof(v));
		for(int i=0; i<m; ++i)
		{
			int x, y;
			cin>>x>>y; --x; --y;
			v[x][y]=v[y][x]=1;
		}
		int kol=1;
		g.clear();
		for(int i=0;i<n;++i)
		{
			g.push_back(i+1);
			kol*=i+1;
		}
		while(kol--)
		{
			int x=0;
			bool ok=true;/*
			for(int i=1; i<n; ++i)
			{
				while(x>=0 && v[g[x]-1][g[i]-1]==0)
					--x;
				if (x==-1)
					ok=false;
			}*/
			index=1;
			if (check(g[0]-1)==-1)
			{
				string cur="";
				for(int i=0; i<n; ++i)
					cur=cur+s[g[i]-1];
				if (ans=="" || ans>cur)
					ans=cur;
			}
			next_permutation(g.begin(), g.end());
		}
		cout<<ans<<endl;
	}
	return 0;
}