using namespace std;
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>
#include<limits.h>
#include<float.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<list>
#include<utility>
#include<iterator>
#include<iomanip>
#include<limits>

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define rep2(i,a,b) for(int i=a; i<=b; i++)

#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define REV(a) reverse(all(a))
#define countbit(x) __builtin_popcount(x)
#define _min3(a,b,c) _min(a,_min(b,c))
#define _max3(a,b,c) _max(a,_max(b,c))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2*acos(0))
#define mem(a,b) memset(a,b,sizeof a)
#define in(a,x,y) (a>=x && a<=y)
#define eq(a,b) (_abs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define INF (1<<28)
#define MOD   1000000007
#define eps 1e-9

#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define line puts("")

inline int LEN(string a) {return a.length();}
inline int LEN(char a[]) {return strlen(a);}

typedef long long i64;
typedef unsigned long long ui64;

typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<string> vst;
typedef pair<int,int> pii;
typedef pair<i64,i64> pi64;
typedef pair<string,int> psi;
typedef vector<pii> vii;

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (a > b ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _sq(T x) { return x * x; }
template< class T > inline T _sqrt(T x) { return (T) sqrt( (double) x); }
template< class T > inline T _pow(T x,T y) {T z=1; repl(i,y){z*=x;} return z; }
template< class T > inline T _gcd(T a,T b) {a=_abs(a);b=_abs(b); if(!b) return a; return _gcd(b,a%b);}
template< class T > inline T _lcm(T a,T b) {a=_abs(a);b=_abs(b); return (a/_gcd(a,b))*b;}
template< class T > inline T _isvowel(T s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
template< class T > inline T _isupper(T s) {if(s>='A' and s<='Z') return 1; return 0;}

template< class T > inline T _extended(T a,T b,T &x,T &y) {a=_abs(a);b=_abs(b); T g,x1,y1; if(!b) {x=1;y=0;g=a; return g;} g=_extended(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}
template< class T > inline T _bigmod(T n,T m) {T ans=1,mult=n%MOD; while(m){ if(m & 1) ans=(ans*mult)%MOD; m>>=1; mult=(mult*mult)%MOD; } ans%=MOD; return ans;}
template< class T > inline T _modinv(T x) {return _bigmod(x,(T) (MOD-2))%MOD;}

template< class T > inline T getbit(T x,T i) { T t=1;return (x&(t<<i)); }
template< class T > inline T setbit(T x,T i) { T t=1;return (x|(t<<i)); }
template< class T > inline T resetbit(T x,T i) { T t=1;return (x&(~(t<<i))); }

template< class T > inline T fastIn(){register char c=0;register T a=0;while(c<33)c=getchar();while(c>33){a=(a*10)+(c-'0');c=getchar();}return a;}
//template< class T > inline T In(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -In<T>();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

#define mx 100020
int dx[]={0,+1,0,-1};
int dy[]={-1,0,+1,0};
string tostr(i64 n){ostringstream os;os<<n;return os.str();}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	#endif
	int t,kas=0;
	sdi(t);
	while(t--){
		int n,m;
		sdi(n);sdi(m);
		int a[100][100];
		rep(i,n)rep(j,m)sdi(a[i][j]);
		int f=0;
		rep(i,n){
			rep(j,m){
				if(a[i][j]==1){
					set<int>s1,s2;
					rep(k,m) s1.insert(a[i][k]);
					rep(k,n) s2.insert(a[k][j]);
					if(s1.size()==2 and s2.size()==2){
						f=1;
						break;
					}
				}
			}
			if(f==1) break;
		}
		if(f==1) printf("Case #%d: NO\n", ++kas);
		else printf("Case #%d: YES\n", ++kas);
	}
	
	return 0;
}
