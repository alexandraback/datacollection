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
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define REP(i,n)        FOR(i,0,n)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
	#define SSTR( x )		dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

LL dp [31][2][2][2];
string a, b, c;
string convert (int A)
{
	string r = "";
//	cout << A << "=";
	REP(i,32) {
		r += ((A&1) ? "1" : "0");
		A /= 2;
	}
//	cout << r << endl;
	return r;
}

bool valid (int t, int x, int y, int z, int ea, int eb, int ec)
{
	bool va = (ea == 0) || (x <= a[t-1]-'0' );
	bool vb = (eb == 0) || (y <= b[t-1]-'0' );
	bool vc = (ec == 0) || (z <= c[t-1]-'0' );
	return va && vb && vc;
}

LL solve (int t, int ea, int eb, int ec)
{
	LL &ans = dp[t][ea][eb][ec];
	if (ans == -1) {
		if (t == 0) {
			ans = 1;
		}
		else {
			ans = 0;
			REP(x,2) REP(y,2) {
				int z = x&y;
				if (valid (t, x, y, z, ea, eb, ec))
				{
					ans += solve (t-1, ea && (x == a[t-1]-'0'), eb && (y == b[t-1]-'0'), ec && (z == c[t-1]-'0'));
				}
			}
		}
	}
	return ans;
}

int main()
{
	int T = rint();
	REP(t,T)
	{
		int na = rint(), nb = rint(), nk = rint();
		a = convert (na-1);
		b = convert (nb-1);
		c = convert (nk-1);
		CL (dp, -1);
		printf("Case #%d: %lld\n", t+1, solve (30, 1,1,1));
	}
	return 0;
}
