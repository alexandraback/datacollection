#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

bool test(int h,int w,int grid,int i,int j,int& vis)
{
	if(i<0 || h<=i || j<0 || w<=j) return false;
	if((grid>>i*w+j&1) || (vis>>i*w+j&1)) return true;
	if(i==0 || i==h-1 || j==0 || j==w-1) return false;
	vis^=1<<i*w+j;
	bool res=true;
	rep(k,4) res&=test(h,w,grid,i+"\xff\x1\0\0"[k],j+"\0\0\xff\x1"[k],vis);
	vis^=1<<i*w+j;
	return res;
}
int visit(int h,int w,int grid,int i,int j,int& vis)
{
	if(i<0 || h<=i || j<0 || w<=j || (vis>>i*w+j&1)) return 0;
	vis|=1<<i*w+j;
	if(grid>>i*w+j&1) return 1;
	int res=1;
	rep(k,4) res+=visit(h,w,grid,i+"\xff\x1\0\0"[k],j+"\0\0\xff\x1"[k],vis);
	return res;
}

int calc(int h,int w,int grid)
{
	int vis=0,res=0;
	rep(i,h) rep(j,w){
		if(vis>>i*w+j&1) continue;
		if(test(h,w,grid,i,j,vis)) res+=visit(h,w,grid,i,j,vis);
	}
	return res;
}

void solve_naive(int h,int w,int k)
{
	int res=INF;
	rep(b,1<<h*w)
		if(calc(h,w,b)>=k)
			res=min(res,__builtin_popcount(b));
	cout<<res<<endl;
}

void solve()
{
	int h,w,k; cin>>h>>w>>k;
	solve_naive(h,w,k);
}

int main()
{
	int T; scanf("%d",&T);
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
