#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;



bool g[10];
string ans = "";
string code[10];
int u[10];
vector<bool> f[10];
vector<pair<int,int> > a[10];
int n,m;


bool T = false;

int check(int v)
{
	int p = -1;
	for(int i = 0; i<n;i++)
		if (g[u[i]]==false)
		{
			p = u[i];
			break;
		}
	if (p==-1) return -1;

	for(int e = 0;e<n;e++)
	{
		for(int i = 0; i < a[v].size(); i++)
		{
			if (a[v][i].first==p && a[v][i].second == 1)
			{
				g[p]=true;
				p = check(p);
				if (p==-1) return -1; else
					break;
			}
		}
	}
	return p;
}

void check_code()
{
	string s="";
	for(int i = 0;i<n;i++)
		s+=code[u[i]];
	if (ans=="") ans=s; else
	{
		for(int i = 0;i<ans.length();i++)
		{
			if (ans[i]==s[i]) continue;
			if (ans[i]< s[i]) return;
			ans = s;
			return;
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;

	for(int q = 1;q <=t;q++)
	{
		cin >> n >> m;
		for(int i=0;i<10;i++)
		{
			f[i].clear();
			a[i].clear();
			g[i] = false;
		}
		ans="";
		
		for(int i=0;i<n;i++)
		{

			cin >> code[i];
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			x--;
			y--;
			a[x].push_back(make_pair(y,1));
			f[x].push_back(false);
			a[y].push_back(make_pair(x,1));
			f[y].push_back(false);
		}
		
		for(int i=0;i<n;i++)
			u[i] = i;
		do{
			g[u[0]]=true;
			if (check(u[0])==-1)
				check_code();
			for(int j=0;j<n;j++)
				g[j] = false;
		}while(next_permutation(u,u+n));
		cout <<"Case #" << q << ": " << ans << endl;

	}
return 0;
}