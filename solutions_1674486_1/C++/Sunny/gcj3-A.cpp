#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000
#define maxn 1000000

//typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


vi edges[1005];
int memo[1005][1005];

int solve(int u,int t)
{
	int ret=0,i;

	if(u==t) return 1;
	if(memo[u][t]!=-1) return memo[u][t];

	for(i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		ret+=solve(v,t);
		ret=MIN(ret,2);
	}
	return memo[u][t]=ret;
}

int main()
{
	int i,j,k,tests,cs=0,n;


	freopen("E:\\Downloads\\A-large.in","r",stdin);
	freopen("E:\\A-large.out","w",stdout);

	scanf("%d",&tests);
	while(tests--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			edges[i].clear();
			scanf("%d",&k);
			int x;
			while(k--)
			{
				scanf("%d",&x);
				edges[i].pb(x);
			}
		}

		int ok=0;
		MEM(memo,-1);

		for(i=1;i<=n && !ok;i++)
		{
			for(j=1;j<=n && !ok;j++)
			{
				int ret=solve(i,j);
				if(ret>1) ok=1;
			}
		}

		printf("Case #%d: ",++cs);
		if(ok)
			puts("Yes");
		else
			puts("No");
	}



	return 0;
} 


