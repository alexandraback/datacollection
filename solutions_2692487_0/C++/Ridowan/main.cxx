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

int d[110];

char ds[104][1000010];

int main() {
	//READ("input.in");
	READ("A-small-attempt0.in");
	//READ("A-small-attempt1.in");
	//READ("A-small-attempt2.in");
	//READ("A-small-attempt3.in");
	//READ("A-large.in.in");
	WRITE("output1.out");
	int I,T;
	cin>>T;
	for(I=1;I<=T;I++) {
		int n,a,i,c,t;
		cin>>a>>n;
		for(i=0;i<n;i++) {
			cin>>d[i];
		}
		sort(d,d+n);
		queue < pii > q;
		MEM(ds,63);
		ds[0][a]=0;
		q.push(pii(0,a));
		while(!q.empty()) {
			c=q.front().ff;
			a=q.front().ss;
			q.pop();
			t=ds[c][a];
			while(c<n && a>d[c]) {
				a=min(a+d[c],1000001);
				c++;
				if(ds[c][a]>t) ds[c][a]=t;
			}
			if(c==n) break;
			if(ds[c][a]>=n) continue;
			t++;
			if(ds[c+1][a]>t) {
				ds[c+1][a]=t;
				q.push(pii(c+1,a));
			}
			a=min(a+a-1,1000001);
			if(ds[c][a]>t) {
				ds[c][a]=t;
				q.push(pii(c,a));
			}
		}
		printf("Case #%d: %d\n",I,min(n,t));
	}
	return 0;
}
