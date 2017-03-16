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
const ll INF = 2e18+10;

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

ll dp[30][3];
pair<ll,ll> d[30][3];
string s,r;
int _n;
pair<ll,ll> calc(int n,int eq){
	if(n==_n) return mp(0,0);
	if(dp[n][eq]!=-1) return d[n][eq];
	dp[n][eq]=0;
	d[n][eq]=mp(INF,INF);
	ll dif = INF;
	if(eq!=0) dif=-INF;
	int la=(s[n]=='?')?0:s[n]-'0',ra=(s[n]=='?')?9:s[n]-'0';
	int lb=(r[n]=='?')?0:r[n]-'0',rb=(r[n]=='?')?9:r[n]-'0';
	ll c=1;
	REP(i,_n-n-1) c*=10;
	REPP(i,la,ra+1) REPP(j,lb,rb+1){
		if(eq==1||eq==2) {
			pll z=calc(n+1,eq);
			ll mn=z.X-z.Y;
			mn+=(i-j)*c;
			if(eq==2) mn*=-1;
			if(mn>dif) dif=mn,d[n][eq]=mp(i*c+z.X,j*c+z.Y);
			else if(mn==dif){
				d[n][eq]=min(d[n][eq],mp(i*c+z.X,j*c+z.Y));
			}
		}else{
			pll z;
			if(i>j) z=calc(n+1,2);
			else if(j>i) z=calc(n+1,1);
			else z=calc(n+1,0);
			ll mn=z.X-z.Y;
			mn+=(i-j)*c;
			if(mn<0) mn*=-1;
			if(mn<dif) dif=mn,d[n][eq]=mp(i*c+z.X,j*c+z.Y);
			else if(mn==dif){
				d[n][eq]=min(d[n][eq],mp(i*c+z.X,j*c+z.Y));
			}
		}
	}
	return d[n][eq];
}
int main(){
	int t; scanf("%d",&t);
	REP(aa,t){
		cin>>s>>r;
		int n=s.size();_n=n;
		FILL(dp,-1);
		pair<ll,ll > ans= calc(0,0);
		printf("Case #%d: ",aa+1);
		REP(i,n) s[n-1-i] = ans.X%10+'0',ans.X/=10;
		REP(i,n) r[n-1-i] = ans.Y%10+'0',ans.Y/=10;	
		cout<<s<<" "<<r<<endl;	
	}
  return 0;	
}
	
