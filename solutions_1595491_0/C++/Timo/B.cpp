#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define PB push_back
#define MP make_pair

typedef pair<int,int > PII; 
template<class T> inline int size(const T&c) { return c.size(); }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

map< int, vector< PII > > M;
map< int, vector< PII > > S;
int nums[128];

int main() {
	OPEN("B");
	REP(nc,getint()) {
		int n = getint();
		int s = getint();
		int p = getint();
		REP(i,n) nums[i]=getint();

		M.clear();
		S.clear();
		FOR(a,0,10) FOR(b,0,10) FOR(c,0,10) {
			int v[]={a,b,c};
			int maks = *max_element(v,v+3);
			int d = maks - *min_element(v,v+3);
			if(maks < p) continue;
			if(d <= 2) {
				int sum = a+b+c;
				PII temp = MP(a,b);
				if(d==2) S[sum].PB( temp );
				else M[sum].PB( temp );
			}
		}

		int ans = 0;
		REP(i,n) {
			if( size(M[nums[i]]) > 0) ans++;
			else if(s>0 && size(S[nums[i]])>0) ans++, s--;
		}
		printf("Case #%d: %d\n",nc+1,ans);
	}

	return 0;
}
