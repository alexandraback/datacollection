//TAG : 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include <climits>
using namespace std;

#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,n) for (int (i)=0,_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b) for (int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset((x),0,sizeof(x));
#define CLEARA(x) memset(&(x),0,sizeof(x));
#define FILL(x,v) memset((x),(v),sizeof(x));
#define FILLA(x,v) memset(&(x),(v),sizeof(x));

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
//const double pi = acos(-1.0);
#define EPS 1e-9

#define LL long long
#define ULL unsigned long long

#ifdef _MSC_VER
#include <intrin.h>
int ctz(unsigned v){
	unsigned long index;
	_BitScanForward(&index,v);
	return index;
}
#define strtoll	_strtoi64
int __popcnt64(unsigned long long v)
{
	return __popcnt((unsigned)(v>>32))+__popcnt((unsigned)(v&UINT_MAX));
}
#else
#define ctz(x) __builtin_ctz(x)
#define __popcnt	__builtin_popcount 
#define __popcnt64	__builtin_popcountll
#endif

int ctzll(ULL n){
	unsigned v=n;//(uint)(n & UINT_MAX);
	return v?ctz(v):(ctz(n>>32)+32);
}

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		int ans=1;
		LL P,Q;
		char dummy;
		cin>>P>>dummy>>Q;
		LL g=gcd(P,Q);
		if(g>1)P/=g,Q/=g;
		if(__popcnt64(Q)>1){
			printf("Case #%d: impossible\n",t);
		}else{
			while(P>=2){
				P>>=1;
				Q>>=1;
			}
			printf("Case #%d: %d\n",t,ctzll(Q));
		}
	}
	return 0;
}