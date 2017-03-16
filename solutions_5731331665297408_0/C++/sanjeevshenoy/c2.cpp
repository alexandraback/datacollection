#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <limits>
#include <cassert>
#include <sstream>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;
typedef long long ll;

const int max_n=100010;

int n,m,T;
int v[8];
int par[8];
bool b[8][8];
string s[8];

bool rec(int u, int nxt)
{
	//cout<<u<<nxt<<endl;
	if(nxt==n)
		return 1;

	bool res=0;
	if(b[u][v[nxt]])
	{
		par[v[nxt]]=u;
		res|=rec(v[nxt],nxt+1);
	}
	
	if(u!=v[0])
		res|=rec(par[u],nxt);

	return res;
}

int main()
{
	scanf("%d",&T);

	for(int z=0; z<T; z++)
	{
		memset(b,0,sizeof(b));
		//memset(visited,0,sizeof(visited));

		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			cin>>s[i];

		int x,y;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			b[x][y]=1;
			b[y][x]=1;
		}

		printf("Case #%d: ",z+1);
		
		for(int i=0; i<8; i++)
			v[i]=i;

		string res="a";
		do
		{
			// for(int i=0; i<n; i++)
			// 	cout<<v[i]<<" ";
			// cout<<"\n";
			if(rec(v[0],1))
			{
				string tmp="";
				for(int i=0; i<n; i++)
					tmp+=s[v[i]];
				res=min(res,tmp);
			}
		}
		while(next_permutation(v,v+n));

		cout<<res<<"\n";
	}

	return 0;
}