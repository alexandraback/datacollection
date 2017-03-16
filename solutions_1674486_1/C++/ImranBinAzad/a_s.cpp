#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

vector <int> v[1010];
bool vis[1010];

bool call(int i)
{
	//cout<<" "<<i;
	vis[i]= 1;
	int sz= v[i].size(),j,k,ans= 0;
	
	for (j=0; j<sz;++j)
	{
		k= v[i][j];
		if(vis[k]) {return 1;}
		ans= call(k);
		if (ans) return 1;
	}
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,x;
	scanf("%d",&t);
	
	for (x=1; x<=t; ++x)
	{
		int n,i,in[1010]={0},out[1010]={0};
		scanf("%d",&n);
		
		for (i=1; i<=n; ++i)
		{
			v[i].clear();
			int j,k;
			scanf("%d",&j);
			while (j--)
			{
				scanf("%d",&k);
				v[i].pb(k);
				in[k]++;
				out[i]++;
			}
		}
		bool f= 0;
		
		
		for (i=1; i<=n;++i)
		{
			mem(vis,0);
			int ans= call(i);
			if (ans){f=1;break;}
		}
		
		printf("Case #%d: ",x);
		if (f)puts("Yes");
		else puts("No");
	}
	
	return 0;	
}
