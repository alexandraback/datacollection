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

typedef bitset<1000> bs;

queue<int> q;

int M[1001];
int I[1001][10];
bs a;

bool go(int x) {
	REP(i,M[x]) {
		q.push(I[x][i]); if (a[I[x][i]]) return true; a.set(I[x][i]);
	}
	return false;
}

bool solve() {
	int N;

	CLR(M,0);
	CLR(I,0);

	cin >> N;
	FOR(i,1,N) {
		cin >> M[i];
		REP(j, M[i]) {
			cin >> I[i][j];
		}
	}
	
	bool f;
	FOR(i,1,N){
		a.reset();
		f = go(i);
		while(!q.empty()) {
			if (!f) f = go(q.front());
			q.pop();
		}
		if (f) return true;
	}
	
	return false;
	//getline(cin,line);
	
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
	int caseCount; cin >> caseCount;
	string temp; getline(cin,temp);
	FOR (c, 1, caseCount) {
		printf("Case #%lld:", c);
		printf(" %s", solve()?"Yes":"No");
		cout << endl;
	}
	return 0;
}
