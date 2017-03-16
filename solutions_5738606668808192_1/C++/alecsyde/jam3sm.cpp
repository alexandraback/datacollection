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
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 1e6+10;
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

bool isprime[500];
vector<int>primes;
int a[40];
int g[40];
string comp(){
	string s="";
	for(int i=31;i>=0;i--) s.pb(a[i]+'0');
		return  s;
}
int check(int p){
	ll x=0,y=0,t=1;
	REP(i,16) {x+=t*a[i],y+=t*a[i+16]; t*=p;}
	int l=0;
	assert(x>=0&&y>=0&&t>=0);
	//cout<< comp();
	while(primes[l]<100){
		ll z=(x%primes[l])+(t%primes[l])*(y%primes[l]);
		if(z%primes[l]==0) return primes[l];
		l++;
	}
	return -1;
}
int main(){
	printf("Case #1:\n");
	REPP(i,2,500){
		if(isprime[i]==0){
			primes.pb(i);
			for(int j=i+i;j<500;j+=i) isprime[j]=1;
		}
	}
	vector<pair<string,vector<int> > > ans;
	REP(i,1<<30){
		int f=0;
		a[0]=a[31]=1;
		REP(j,30) a[j+1]=(i>>j)&1;

		REPP(j,2,11) {
			int x=check(j); if(x==-1) {f=1;break;}
			g[j]=x;
		}
		if(f==0){
			vector<int> c;
			REPP(j,2,11) c.pb(g[j]);
			ans.pb(mp(comp(),c));
			string l=comp();
			cout<<l<<" ";
			REP(j,c.size()) printf("%d ",c[j]); printf("\n");
		}
		if(ans.size()==500) break;
	}
	REP(i,ans.size()){
		;

	}
  return 0;
}
	