#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)

inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

int main() {
	OPEN("B");
	REP(nc,getint()) {
		int A=getint();
		int B=getint();
		int K=getint();
		int ans=0;
		REP(i,A) REP(j,B) if( (i&j) < K) {
			ans++;
		}
		printf("Case #%d: %d\n",nc+1,ans);
	}
	return 0;
}
