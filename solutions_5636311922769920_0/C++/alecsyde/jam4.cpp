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


int main(){
	int t; scanf("%d",&t);
	REP(aa,t){
		ll k,c,s; scanf("%lld%lld%lld",&k,&c,&s);
		ll p=1;
		printf("Case #%d: ",aa+1);
		REP(i,c-1)  p*=k;
		REP(i,s) printf("%lld ",p*(i+1));
		printf("\n");
	/*	if(s<(k+1)/2) printf("IMPOSSIBLE\n");
		else{
			ll x=1;
			while(x<=k){
				if(x==k){
					printf("%lld",(x-1)*p+x);
				}else{
					printf("%lld ",p*(x-1)+x+1);
				}
				x+=2;
			}
			printf("\n");
		}*/
	}
  return 0;
}
	