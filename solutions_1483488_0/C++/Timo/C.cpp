#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

int f[1<<21];
int cc=0;

int calc(int i,int A,int B) {

	if(i<=10) return 0;
	cc++;

	int ten = 1;
	while(ten<i) ten*=10;

	A = max( A, ten/10 );

	int m=10;

	int ret = 0;
	while(m<ten) {
		int y = (i%m) * (ten/m) + (i/m);
		if(y>=A && y<=B) {
			if(f[y]!=cc) {
				f[y]=cc;
				ret++;
			}
		}
		m*=10;
	}

	return ret;
}

int main() {
	OPEN("C");
	REP(nc,getint()) {
		int A=getint();
		int B=getint();
		int ans = 0;
		FOR(i,A,B) {
			ans += calc(i,i+1,B);
		}

		printf("Case #%d: %d\n",nc+1,ans);
	}
	return 0;
}
