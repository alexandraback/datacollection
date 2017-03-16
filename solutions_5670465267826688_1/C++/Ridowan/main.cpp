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

int cnv(char c) {
	switch(c) {
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
		default : assert(0);
	}
}

int mul(int a,int b) {
	int mul = 1;
	if(a<0) {
		mul=-mul;
		a=-a;
	}
	if(b<0) {
		mul=-mul;
		b=-b;
	}
	if(a==1 || b==1) return mul*a*b;
	if(a==b) return -mul;
	if(a==2) {
		if(b==3) return 4*mul;
		if(b==4) return -3*mul;
	}
	if(a==3) {
		if(b==2) return -4*mul;
		if(b==4) return 2*mul;
	}
	if(a==4) {
		if(b==2) return 3*mul;
		if(b==3) return -2*mul;
	}
	assert(0);
}

int pw(int b,i64 p) {
	int r=1;
	while(p) {
		if(p&1) r = mul(r, b);
		p>>=1;
		b = mul(b, b);
	}
	return r;
}

char ln[10019];

bool chk() {
	i64 x;
	int i,j,k,l;
	scanf("%d %lld %s",&l,&x,ln);
	int m=1, tm;

	for(i=0;i<l;i++) {
		m = mul(m,cnv(ln[i]));
	}
	tm=m;
	//cerr<<tm<<' '<<pw(m,x)<<'\n';
	if(pw(m,x)!=-1) return false;


	set<pii> vis;
	m=1;
	for(j=1;j<=x;j++) {
		for(i=0;i<l;i++) {
			m = mul(m,cnv(ln[i]));
			//cerr<<j<<' '<<i<<' '<<m<<'\n';
			if(m==2) break;
			if(vis.find({i,m})!=vis.end()) return false;
			vis.insert({i,m});
		}
		if(m==2) break;
	}
	//cerr<<j<<' '<<i<<' '<<m<<'\n';
	if(j>x) return false;

	m=1;
	vis.clear();
	int pm=j,pi=i;
	for(;j<=x;j++) {
		for(i=j==pm?(i+1):0;i<l;i++) {
			m = mul(m,cnv(ln[i]));
			//cerr<<' '<<j<<' '<<i<<' '<<m<<'\n';
			if(m==3) break;
			if(vis.find({i,m})!=vis.end()) return false;
			vis.insert({i,m});
		}
		if(m==3) break;	
	}
	if(j>x) return false;

	m=1;
	for(i++;i<l;i++) m = mul(m,cnv(ln[i]));
	//cerr<<m<<' '<<tm<<'\n';
	m=mul(m, pw(tm, x-j));
	return m==4;
}

int main() {
	// READ("input.in");
	// READ("C-small-attempt0.in");
	//READ("A-small-attempt1.in");
	//READ("A-small-attempt2.in");
	//READ("A-small-attempt3.in");
	READ("C-large.in");
	// WRITE("output.out");
	WRITE("outputLarge.out");
	int I,T;
	cin>>T;
	for(I=1;I<=T;I++) {
		cerr<<I<<'\n';
		printf("Case #%d: %s\n",I, chk()?"YES":"NO");
	}
	return 0;
}
