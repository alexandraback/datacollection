//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int main() {
	//READ("input.in");
	//READ("C-small-1-attempt0.in");
	READ("C-small-1-attempt1.in");
	//READ("C-small-attempt1.in");
	//READ("C-small-attempt2.in");
	//READ("C-small-attempt3.in");
	//READ("C-large.in");
	WRITE("outputSmall2-a.out");
	int I,T,i,j,k,n,h,m,l,d;
	pii hk[231];
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		l=0;
		while(n--) {
			cin>>d>>h>>m;
			while(h--) {
				//cerr<<l<<'\n';
				hk[l].ff=d;
				hk[l].ss=m;
				m++;
				l++;
			}
		}
		cerr<<I<<' '<<l<<'\n';
		int r;
		if(l==1) r=0;
		else if(hk[0].ss==hk[1].ss) r=0;
		else {
			if(hk[0].ss<hk[1].ss) swap(hk[0],hk[1]);
			double v0=360./hk[0].ss;
			double v1=360./hk[1].ss;
			double t0=(360-hk[0].ff)/v0;
			double t1=(360-hk[1].ff)/v1;
			if(t0+1e-7<t1) r=0;
			else {
				double d1=t0*v1+hk[1].ff;
				if(d1>=720+1e-7) r=1;
				else r=0;
			}
		}
		printf("Case #%d: %d\n",I,r);
	}
	return 0;
}
