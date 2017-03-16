#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,ull> piu;
typedef pair<ull,ull> puu;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pii,ll> ppl;
typedef pair<ll,pii> plp;
typedef pair<ll,pll> plP;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
typedef pair<double,pii> pdp;
typedef pair<double,double> pdd;
typedef pair<pdd,double> pd3;
typedef vector<int> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define BS2(x,n,a) binary_search((x),(x)+(n),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<28)
#define INFL (1LL<<61)
#define fi first
#define se second
#define EPS 1e-9
#define MOD 1000000007
#define MIN(x,a) x=min(x,a)
#define MAX(x,a) x=max(x,a)
#define madd(x,a) x=(x+a)%MOD
#define msub(x,a) x=(x+MOD-a)%MOD
#define OUTPUT(x) rep(__,x.size())printf("%.6f%c",x[__],__+1==x.size()?'\n':' ')

int T,N;
vector<int> G[1000],rG[1000],vs;
int F;
int cs[1000];
bool used[1000];
int f[1000];
void dfs(int v)
{
	used[v]=true;
	rep(i,G[v].size())if(!used[G[v][i]])dfs(G[v][i]);
	vs.pb(v);
}
void rdfs(int v,int k)
{
	used[v]=true;
	rep(i,rG[v].size())if(!used[rG[v][i]])rdfs(rG[v][i],k);
	cs[k]++;
}
int sol(int v,int p)
{
	int res=2;
	rep(i,rG[v].size())if(rG[v][i]!=p)MAX(res,sol(rG[v][i],v)+1);
	return res;
}

int main()
{
	scanf("%d",&T);
	repn(_,1,T+1)
	{
		scanf("%d",&N);
		rep(i,N)G[i].clear(),rG[i].clear();
		rep(i,N)
		{
			scanf("%d",&F);
			G[i].pb(--F);
			rG[F].pb(i);
			f[i]=F;
		}
		MM(used,0);vs.clear();MM(cs,0);
		rep(i,N)if(!used[i])dfs(i);
		int k=0;
		
		MM(used,0);
		for(int i=int(vs.size())-1;i>=0;i--)if(!used[vs[i]])rdfs(vs[i],k),k++;
		int res=0;
		rep(i,1000)MAX(res,cs[i]);
		
		int ct=0;
		rep(i,N)if(f[f[i]]==i&&i<f[i])
		{
			int t1=sol(i,f[i]);
			int t2=sol(f[i],i);
			ct+=t1+t2-2;
			MAX(res,t1+t2-2);
		}
		MAX(res,ct);
		
		printf("Case #%d: %d\n",_,res);
	}
}