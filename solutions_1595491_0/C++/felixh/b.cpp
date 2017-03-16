#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

int TC,N,S,p,T[101];
int memo[101][101];

int rec(int idx, int sur){
	int &ret = memo[idx][sur];
	if (ret != -1) return ret;
	ret = -1000000000;

	if (idx == N){
		if (sur == 0) ret = 0;
		return ret;
	}

	REP(i,11) REP(j,11) if (abs(i-j)<=2)
		REP(k,11) if (abs(i-k)<=2 && abs(j-k)<=2 && i+j+k==T[idx]){
			if (abs(i-j)==2 || abs(i-k)==2 || abs(j-k)==2){
				int best = max(i, max(j,k)) >= p;
				if (sur > 0) ret = max(ret, best + rec(idx+1, sur-1));
			} else {
				int best = max(i, max(j,k)) >= p;
				ret = max(ret, best + rec(idx+1, sur));
			}
		}
	return ret;
}

int main(){
	scanf("%d",&TC);
	for (int tc=1; TC--; tc++){
		scanf("%d %d %d",&N,&S,&p);
		REP(i,N) scanf("%d",&T[i]);
		memset(memo,-1,sizeof(memo));
		printf("Case #%d: %d\n",tc,rec(0,S));
		fprintf(stderr,"Case #%d: %d\n",tc,rec(0,S));
	}
}
