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

double solve(double C, double F, double X) {
	double ret = X / 2.0;
	double extra = C / 2.0;
	FOR(i,1,1<<20) {
		double div = F * i + 2.0;
		double temp = X / div + extra;
		if(temp<ret) {
			ret = temp;
		}else {
			break;
		}
		extra += (C / div);
	}
	return ret;
}

int main() {
	OPEN("B");
	double C,F,X;
	REP(ncase,getint()) {
		scanf("%lf %lf %lf",&C,&F,&X);
		printf("Case #%d: %.7lf\n", ncase+1, solve(C,F,X));
	}
	return 0;
}
