/*Author : Vineet Kumar */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int E,R,n,ans;
VI q;
void dfs(int p,int e,int v)
{
	//printf("%d %d %d\n",p,e,v);
	if(p>=n)
	{
		ans = max(ans,v);
		return;
	}
	for(int i=e;i>=0;i--)
		dfs(p+1,min(e-i+R,E),v+q[p]*i);
	return;
}
int main()
{
	int i,j,t,test = 1;
	for(si(t);t--;)
	{
		printf("Case #%d: ",test++);
		q.clear();
		ans = 0;
		si(E);
		si(R);
		si(n);
		rep(i,n)
		{
			si(j);
			q.pb(j);
		}
		dfs(0,E,0);
		pil(ans);
	}
	return 0;
}

