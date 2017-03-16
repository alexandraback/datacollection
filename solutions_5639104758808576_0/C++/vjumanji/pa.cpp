// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
	#include <sstream>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define REP(i,n)        FOR(i,0,n)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
	#define SSTR( x )		dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()
	#define TI(x)		int x = rint()
	#define TII(x,y)		int x = rint(),y = rint()
	#define TIII(x,y,z)		int x = rint(),y = rint(),z = rint()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%I64d",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

char s[10010];
int n;

LL solve() {
	LL ans = 0;
	LL p = s[0] - '0';
	REP(i, n) {
		if (p >= i+1) {
			p += s[i+1] - '0';
		}
		else if (s[i+1] > '0') {
			LL k = (LL)(i+1) - p;
			ans += k;
			p += k + (s[i+1] - '0');
		}
	}
	return ans;
}

int main()
{
	TI(t);
	REP(i, t) {
		n = rint();
		scanf("%s", s);
		printf("Case #%d: %lld\n", i+1, solve());
	}
	return 0;
}
