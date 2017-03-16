#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<iomanip>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-9
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) (int)a.size()
#define inf 2147483640

#define mx 100010

using namespace std;

const int debug= 0;
int E,R,N,a[mx],dp[15][15];

int call(int i,int e);

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int x,t;
	scanf("%d",&t);
	
	for (x=1;x<=t;++x)
	{
		mem(dp,-1);
		scanf("%d%d%d",&E,&R,&N);
		int i;
		for (i=1;i<=N;++i) scanf("%d",&a[i]);
		
		int ans= call(1,E);
		printf("Case #%d: %d\n",x,ans);
	}
	
	return 0;	
}

int call(int i,int en)
{
	if (i==N+1) return 0;
	
	if (dp[i][en]!=-1) return dp[i][en];
	
	int j,ans= 0;
	for (j=0;j<=en;++j)
	{
		ans= max(ans,call(i+1,min(E,en-j+R))+a[i]*j);
	}
	//cout<<i<<" "<<en<<" "<<ans<<endl;
	return dp[i][en]= ans;
}
