#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>
#define stream istringstream
#define rep(i,n) for(i64 i=0; i<(i64)n; i++)
#define repv(i,n) for(i64 i=n-1; i>=0; i--)
#define repl(i,n) for(i64 i=1; i<=(i64)n; i++)
#define replv(i,n) for(i64 i=n; i>=1; i--)
#define FOR(i,a,b) for(i64 i=(i64)a;i<=(i64)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (i64)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<i64,i64>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) pri64f("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1LL<<(pos)))
#define off(n,pos)  n & ~(1LL<<pos)
#define ison(n,pos) (bool)(n & (1LL<<(pos)))
string toBin(i64 n){ string s; repv(i,40)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%lld: ",++ks);

using namespace std;

string A,B,K;
i64 dp[40][3][3][3];
i64 call(i64 i,i64 f1,i64 f2,i64 f3)
{
	//cout<<f1<<" "<<f2<<" "<<f3<<endl;
	if(i==-1)
	{
		
		return (f1==1 and f2==1 and f3==1);
	}
	if(dp[i][f1][f2][f3]!=-1) return dp[i][f1][f2][f3];
	i64 ans=0;
	rep(b1,2)
	{
		rep(b2,2)//if(!b1 and !b2)
		{
			i64 ob1=A[i]-'0';
			i64 ob2=B[i]-'0';
			i64 ob3=K[i]-'0';
			i64 b3=b1 & b2;
			i64 nf1=f1,nf2=f2,nf3=f3;
			if(f1==0 and b1>ob1) continue;
			if(f2==0 and b2>ob2) continue;
			if(f3==0 and b3>ob3) continue;
			//cout<<b1<<" "<<b2<<" "<<b3<<" "<<ob1<<" "<<ob2<<" "<<ob3<<endl;
			if(b1<ob1) nf1=1;
			if(b2<ob2) nf2=1;
			if(b3<ob3) nf3=1;
			
			ans+=call(i-1,nf1,nf2,nf3);
		}
	}
	
	return dp[i][f1][f2][f3]=ans;
	
	
	
	
	
	
}
int main() {
	//	string inp[1111];
	//cout<<toBin((1LL<<35LL)-1)<<endl;
		READ("in");
		WRITE("Blarge");
		//cout<<toBin((1LL<<32LL)-1)<<endl;
		i64 t,ks=0;
		cin>>t;
		while(t--)
		{
			mem(dp,-1);
			i64 a,b,k;
			cin>>a>>b>>k;
			A=toBin(a);
			B=toBin(b);
			K=toBin(k);
				reverse(all(A));	reverse(all(B));	reverse(all(K));
				//cout<<sz(A)<<endl;
			//cout<<B[2]<<endl;
		
			//cout<<A<<" "<<B<<" "<<K<<endl;
			//pks;
			i64 ans=call(32,0,0,0);
			pks;
			cout<<ans<<endl;
		}
		
	
	return 0;
}


