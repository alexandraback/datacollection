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

char input[1024];

int main() {
	OPEN("A");
	REP(nc,getint()) {
		int n=getint();
		scanf("%s",input);
		int ans = 0;
		int sum = input[0]-'0';
		FOR(i,1,n) {
			int extra = max( 0, i-sum );
			ans += extra;
			sum += extra;
			sum += (input[i]-'0');
		}
		printf("Case #%d: %d\n",nc+1,ans);
	}
	return 0;
}
