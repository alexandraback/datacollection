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

i64 inv(i64 a) {
	i64 r=0;
	while(a) {
		r=r*10+a%10;
		a/=10;
	}
	return r;
}

int main() {
	//READ("input.in");
	READ("A-small-attempt0.in");
	//READ("A-small-attempt1.in");
	//READ("A-small-attempt2.in");
	//READ("A-small-attempt3.in");
	//READ("A-large.in");
	WRITE("output.out");
	int I,T,v,r;
	i64 n,t,tt;
	cin>>T;
	for(I=1;I<=T;I++) {
		cerr<<I<<'\n';
		map<i64,int> vis;
		cin>>n;
		vis[n]=0;
		queue<pair<i64,int>> q;
		q.push({n,0});
		while(!q.empty()) {
			t=q.front().ff;
			v=q.front().ss+1;
			q.pop();
			//cerr<<t<<' '<<v<<'\n';
			if(t<10) {
				r=t+v-1;
				break;
			}
			if(vis.find(t-1)==vis.end()) {
				vis[t-1]=v;
				q.push({t-1,v});
			}
			if(t%10) {
				tt=inv(t);
				if(tt>=t) continue;
				t=tt;
				if(vis.find(t)==vis.end()) {
					vis[t]=v;
					q.push({t,v});
				}
			}
		}
		printf("Case #%d: %d\n",I,r);
	}
	return 0;
}
