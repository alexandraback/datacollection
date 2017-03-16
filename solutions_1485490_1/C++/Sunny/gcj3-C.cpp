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

//typedef long  LL;
typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int btype[105],atype[105];
LL   bcnt[105],acnt[105];
int n,m;
LL memo[105][105];

LL solve(int a,int b)
{
	int i,j;
	LL ta=0,tb=0,ret=0;

	if(a==n || b==m) return 0;
	if(memo[a][b]!=-1) return memo[a][b];

	if(atype[a]!= btype[b])
	{
		for(i=a;i<n;i++)
			for(j=b;j<m;j++)
				if(atype[i]==btype[j])
					ret=MAX(ret,solve(i,j));
		return memo[a][b]=ret;
	}
	
	int type= atype[a];

	for(i=a;i<n;i++)
	{
		if(atype[i]==type) ta+=acnt[i];
		tb=0;

		for(j=b;j<m;j++)
		{
			if(btype[j]==type) tb+=bcnt[j];

			ret=MAX(ret,MIN(ta,tb)  + solve(i+1,j+1) );
		}
	}
//	printf("%d %d %d\n",a,b,ret);

	return memo[a][b]=ret;
}

int main()
{
	int i,j,k,tests,cs=0;


	freopen("E:\\C-large.in","r",stdin);
	freopen("E:\\C-large.out","w",stdout);
	scanf("%d",&tests);

	while(tests--)
	{
		scanf("%d%d",&n,&m);

		for(i=0;i<n;i++)
		{
			scanf("%I64d %d",&acnt[i],&atype[i]);
		}

		for(i=0;i<m;i++)
		{
			scanf("%I64d %d",&bcnt[i],&btype[i]);
		}

		MEM(memo,-1);
		LL ans=solve(0,0);
		printf("Case #%d: %I64d\n",++cs,ans);
		
	}



	return 0;
} 


