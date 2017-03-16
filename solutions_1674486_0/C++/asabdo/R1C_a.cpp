#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<iterator>
#include<complex>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif
using namespace std;

int N;
vector< vector<int> > v;
bool vis[1005];
bool dfs(int I)
{
	for(int i=0;i<v[I].size();i++)
	{
		int j = v[I][i];
		if( vis[j] )
			return true;
		vis[j] = 1;
		if( dfs(j) )
			return true;
	}
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("aout.txt","wt",stdout);
#endif
	int TC=1;
	scanf("%d",&TC);
	int m,x;
	for(int tc=1;tc<=TC;tc++)
	{
		cerr<<tc<<endl;
		scanf("%d",&N);
		v.clear();
		v.resize(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				v[i].push_back(x-1);
			}
		}
		bool ok = 0;
		for(int i=0;i<N;i++)
		{
			memset(vis,0,sizeof(vis));
			if( dfs(i) )
			{
				ok = 1;
				break;
			}
		}
		printf("Case #%d: %s\n",tc,(ok?"Yes":"No"));
	}
	return 0;
}