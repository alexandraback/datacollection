#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for(itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 2e3+10;
const ll INF = 1e18;

//#define DEBUG
ll power(ll x,ll y){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}
#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

int arr[N]; 
int u[N],in[N],lvl[N],mx[N],l[N];
vector<int> G[N];
int dfs(int v){
	int a=1;
	REP(i,G[v].size()) if(mx[G[v][i]]!=1){
		a=max(dfs(G[v][i])+1,a);
	}
	return a;
}
int main(){
	int t; scanf("%d",&t);
	REP(aa,t){
		int n;
		scanf("%d",&n);
		REP(i,n) G[i].clear();
		REP(i,n) scanf("%d",&arr[i]),arr[i]--,G[arr[i]].pb(i);
		FILL(u,0); FILL(mx,0); FILL(l,0);
		FILL(lvl,0);
		int ans=0;
		REP(i,n) if(u[i]==0){
			FILL(in,0);
			int x=i,z=0;
			while(u[x]!=1){
				lvl[x]=z++;
				in[x]=1;
				u[x]=1;
				x=arr[x];

			}
			if(in[x]==1){
				ans=max(ans,z-lvl[x]);
				int y=x;
				mx[x]=1; x=arr[x];
				while(x!=y){
					mx[x]=1; x=arr[x];
				}
			}
		}
		int sum=0;
		REP(i,n) if(mx[i]==1){
			l[i]=dfs(i);
			
		}
		REP(i,n) if(arr[arr[i]]==i) sum+=l[i];
		printf("Case #%d: %d\n",aa+1,max(ans,sum));
	}
  return 0;
}
	