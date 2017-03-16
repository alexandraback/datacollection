#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <numeric>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <limits>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define ll long long
#define ull unsigned long long
#define ld long double
#define MAXI numeric_limits<int>::max()
#define MAXLL numeric_limits<ll>::max()
#define MAXULL numeric_limits<ull>::max()
#define MAXLD numeric_limits<ld>::max()

#define VV vector
#define VI VV<int>
#define VL VV<ll>
#define VS VV<string>
#define PII pair<int,int>
#define PIL pair<int,ll>
#define PLL pair<ll,ll>
#define MP(x,y) make_pair(x,y)
#define SS(a) ((int)((a).size()))
#define PUB push_back
#define POF pop_front
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int COND=0;
#define DBG(x){if(COND>0){COND--;cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;cerr.flush();}}

#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(ll i=(a),_b=(b);i>=_b;--i)
#define FORA(T,it,x) for(T::iterator it=x.begin();it!=x.end();it++)
//#define FORA(i,x) for(auto i=x.begin();i!=x.end();i++)

#define two(X) (((ll)1)<<(X))
template<class T> inline void mini(T &a,T b){if(b<a)a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a)a=b;}
template<class T> inline void ord(T &a,T &b){if(a>b)swap(a,b);}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T gcd(T a,T b){if(a<0)a=-a;if(b<0)b=-b;return (b==0)?a:gcd(b,a%b);} // lnko
template<class T> inline T lcm(T a,T b){if(a<0)a=-a;if(b<0)b=-b;return a*(b/gcd(a,b));} // lkkt
template<class T> inline VV<pair<T,int>> factorize(T n)
	{VV<pair<T,int>> R;T _i=1;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.PUB(MP(i,C));}
	i+=_i;_i=2;if (i*i>n) i=n;}if (n>1) R.PUB(MP(n,1));return R;}
template<class T> inline bool prime(T n)
	{if(n<=1)return false;T _i=1;for (T i=2;i*i<=n;i+=_i,_i=2) if (n%i==0) return false;return true;}

//----------------------------------------------

/* printf:	   Char %c, String %s, Number %d, LL %lld, LPad %05d, Hex %#x, Float %5.2f, LD %.7Lf, Unsigned %u
 * scanf:      int n; scanf ("%d", &n);
 * array:      int x[1] = {1};
 * min/max:    LL max(0LL, x), LD max(0.L, x)
 * sort DESC:  REP(i,N) { int x=a[i]; REP(j,i) ord(x,b[j]); b[i]=x; }
 * translate:  string s; transform(s.begin(),s.end(),s.begin(),tr); // char tr(char c){return c;}
 * dp:         typedef pair<ld, PII> qitem; priority_queue<qitem, vector<qitem>, greater<qitem>> q; // q.push(MP(1,MP(1,2))); // qitem x=q.top();q.pop();
 *
 * http://www.cplusplus.com/reference/algorithm/
 */

//----------------------------------------------

int N,M;
ll a[100],b[100];
int A[100],B[100];
ll mx;

void go(ll r, int ai, ll an, int bi, ll bn) {
	if(A[ai]==B[bi]){
		ll d=min(an,bn);
		r+=d;
		an-=d;
		bn-=d;
	}
	maxi(mx,r);
	if(ai<N-1)go(r,ai+1,a[ai+1],bi,bn);
	if(bi<M-1)go(r,ai,an,bi+1,b[bi+1]);
}

void solve() {
	CLR(a,0);
	CLR(A,0);
	CLR(b,0);
	CLR(B,0);
	mx= 0;
	cin >> N >>M;
	REP(i,N) cin>>a[i]>>A[i];
	REP(i,M) cin>>b[i]>>B[i];

	go(0,0,a[0],0,b[0]);
	//getline(cin,line);
	printf(" %lld", mx);
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
	int caseCount; cin >> caseCount;
	string temp; getline(cin,temp);
	FOR (c, 1, caseCount) {
		printf("Case #%lld:", c);
		solve();
		cout << endl;
	}
	return 0;
}
