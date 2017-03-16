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

int nums[1024];

int main() {
	OPEN("B");
	REP(nc,getint()) {
		int D = getint();
		REP(i,D) nums[i] = getint();
		sort(nums,nums+D);
		int best = nums[D-1];
		FOR(maks,1,best) {
			int extra = 0;
			REP(i,D) {
				if(nums[i] <= maks) continue;
				extra += (nums[i] + maks - 1) / maks;
				extra--;
			}
			best = min(best, maks+extra);
		}
		printf("Case #%d: %d\n",nc+1,best);
	}
	return 0;
}
