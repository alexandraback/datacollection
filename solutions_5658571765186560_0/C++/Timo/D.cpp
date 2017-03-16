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

int ans(int X,int R,int C) {

	if(X==1) return 1;

	if( (R*C) % X != 0) return 0;

	if(X==2) {
		return 1;
	}

	if(X==3) {
		if(R==3 && C==4) return 1;
		if(R==4 && C==3) return 1;
		if(R==3 && C==3) return 1;
		if(R==3 && C==2) return 1;
		if(R==2 && C==3) return 1;
	}

	if(X==4) {
		if(R==4 && C==4) return 1;
		if(R==3 && C==4) return 1;
		if(R==4 && C==3) return 1;
	}
	return 0;
}

int main() {
	OPEN("D");
	REP(nc,getint()) {
		int X=getint();
		int R=getint();
		int C=getint();
		printf("Case #%d: %s\n",nc+1,ans(X,R,C)?"GABRIEL":"RICHARD");
	}

	return 0;
}
