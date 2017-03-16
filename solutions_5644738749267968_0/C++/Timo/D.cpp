#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define PB push_back

inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

inline double getDouble() {
	double x;
	scanf("%lf",&x);
	return x;
}

int N;
vector<double> A;
vector<double> B;
char visit[1024];
int matchA[1024];
int matchB[1024];

bool dfs(int i) {
	if(visit[i]) {
		return false;
	}

	visit[i]=1;
	REP(j,N) {
		if(A[i] > B[j]) {
			if(matchB[j]==-1 || dfs(matchB[j])) {
				matchA[i] = j;
				matchB[j] = i;
				return true;
			}
		}
	}

	return false;
}

int calc() {
	int ret=0;
	REP(i,N) matchA[i]=matchB[i]=-1;
	REP(i,N) {
		if(matchA[i]==-1) {
			REP(j,N) visit[j] = 0;
			if(dfs(i)) ret++;
		}
	}
	return ret;
}

int main() {
	OPEN("D");
	REP(ncase,getint()) {
		N=getint();

		A.clear(); B.clear();
		REP(i,N) A.PB(getDouble());
		REP(i,N) B.PB(getDouble());

		int ans1 = calc();
		swap(A,B);
		int ans2 = N - calc();
		printf("Case #%d: %d %d\n",ncase+1,ans1,ans2);
	}
	return 0;
}
