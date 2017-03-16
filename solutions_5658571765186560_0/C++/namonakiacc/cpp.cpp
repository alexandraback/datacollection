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
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pii,ll> ppl;
typedef pair<ll,pii> plp;
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
#define INF (1<<29)
#define INFL (1LL<<61)
#define fi first
#define se second
#define MOD 1000000009
#define EPS 1e-9
#define MIN(x,a) x=min(x,a)
#define MAX(x,a) x=max(x,a)
#define madd(x,a) x=(x+a)%MOD
#define msub(x,a) x=(x+MOD-a)%MOD
#define OUTPUT(x) rep(i,x.size())printf("%d%c",x[i],i+1==x.size()?'\n':' ');

int T,X,R,C;
int x[6],y[6];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool f[20][20];

bool check(int xx,int yy)
{
	rep(i,R)rep(j,C)f[i][j]=false;
	rep(i,X)
	{
		int tx=xx+x[i],ty=yy+y[i];
		if(tx<0||tx>=R||ty<0||ty>=C)return false;
		f[tx][ty]=true;
	}
	int fx=xx,fy=yy;
	rep(i,R)rep(j,C)if(!f[i][j])
	{
		int cc=0;
		queue<pii> q;
		q.push(mp(i,j));
		f[i][j]=true;
		while(!q.empty())
		{
			cc++;
			xx=q.front().fi,yy=q.front().se;q.pop();
			rep(dd,4)
			{
				int nx=xx+dx[dd],ny=yy+dy[dd];
				if(0<=nx&&nx<R&&0<=ny&&ny<C&&!f[nx][ny])
				{
					f[nx][ny]=true;
					q.push(mp(nx,ny));
				}
			}
		}
		if(cc%X)return false;
	}
	return true;
}
vector<vector<pii> > las;

bool lap(vector<pii> v)
{
	SORT(v);
	int ssx=v[0].fi,ssy=v[0].se;
	rep(i,v.size())v[i].fi-=ssx,v[i].se-=ssy;
	
	for(int i=0;i<las.size();i++)if(las[i]==v)return true;
	rep(cc,3)
	{
		rep(i,v.size())
		{
			int tx=v[i].fi,ty=v[i].se;
			v[i].fi=-ty;
			v[i].se=tx;
		}
		SORT(v);
		ssx=v[0].fi,ssy=v[0].se;
		rep(i,v.size())v[i].fi-=ssx,v[i].se-=ssy;
		rep(i,las.size())if(las[i]==v)return true;
	}
	las.pb(v);
	return false;
}
int tmpx[6],tmpy[6];
bool solve(int cc)
{
	if(cc==X)
	{
		vector<pii> qq;
		rep(i,cc)qq.pb(mp(x[i],y[i]));
		if(lap(qq))return true;
		bool res=false;
		rep(i,R)rep(j,C)res|=check(i,j);
		rep(i,cc)tmpx[i]=x[i],tmpy[i]=y[i];
		rep(__,3)
		{
			bool rr=false;
			rep(i,cc)
			{
				int tx=x[i],ty=y[i];
				x[i]=ty,y[i]=-tx;
			}
			repn(i,-8,R+8)repn(j,-9,C+9)res|=check(i,j);
		}
		rep(i,cc)x[i]=tmpx[i],y[i]=tmpy[i];
		return res;
	}
	vector<pii> kh;
	rep(i,cc)rep(dd,4)
	{
		int nx=x[i]+dx[dd],ny=y[i]+dy[dd];
		if(nx<0||nx==0&&ny<=0)continue;
		bool can=true;
		rep(j,kh.size())if(mp(nx,ny)==kh[j])can=false;
		rep(j,cc)if(x[j]==nx&&y[j]==ny)can=false;
		if(!can)continue;
		kh.pb(mp(nx,ny));
	}
	bool res=true;
	rep(i,kh.size())
	{
		x[cc]=kh[i].fi,y[cc]=kh[i].se;
		res&=solve(cc+1);
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	repn(__,1,T+1)
	{
		scanf("%d%d%d",&X,&R,&C);
		printf("Case #%d: ",__);
		las.clear();
		if(X>6)
		{
			puts("RICHARD");
			continue;
		}
		x[0]=0,y[0]=0;
		bool ans=solve(1);
		if(ans)puts("GABRIEL");
		else puts("RICHARD");
	}
}