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

int a[10];
int p=0;
void check(int x){
	while(x>0){
		int y=x%10;
		if(a[y]==0) p++;
		a[y]=1;
		x/=10;
	}
}
int main(){
	int t; scanf("%d",&t);
	REP(i,t){
		int n; scanf("%d",&n);
		p=0;
		FILL(a,0);
		printf("Case #%d: ",i+1);
		if(n==0){ printf("INSOMNIA\n");}else{
			int l=n;
			check(l);
			while(p<10)  {
				l+=n;
				check(l);
			}
			printf("%d\n",l);
		}
	}
  return 0;
}
	