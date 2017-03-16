#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

#define SET(v,i) memset(v,i,sizeof(v));
#define FOR(i,n,k) for(int i=n;i<k;++i)
#define FORD(i,n,k) for(int i=n;i>=k;--i)
#define WHILE(i,n) while(i<n)
#define RI(i) scanf("%d",&i);
#define RS(i) scanf("%s",i);
#define RF(i) scanf("%lf",&i);
#define RL(i) scanf("%lld",&i);
#define OPEN(s) freopen(s,"r",stdin);
#define CLOSE(s) freopen(s,"w",stdout);

const int INF=0x3F3F3F3F;
const int MAXN=101;
typedef long long int i64;
typedef pair<int,int> pii;
typedef pair<string,int> psi;

int E,R,N;
int arr[MAXN];
int memo[MAXN][MAXN];
bool mark[MAXN][MAXN];

int DP(int idx,int left){
	if(left<0) return -INF;
	if(idx>=N) return 0;
	int &best = memo[idx][left];
	if(mark[idx][left]) return best;
	mark[idx][left]=true;
	best=-INF;
	FORD(i,left,0){
		best=max(best,DP(idx+1,min(E,left-i+R))+(i*arr[idx]));
	}
	return best;
}

int main(){
	#ifdef DM1_MACHINE
		OPEN("FILE.in");
		//CLOSE("FILE.out");
	#endif
	int T; RI(T);
	FOR(ic,1,T+1){
		SET(mark,0)
		RI(E); RI(R); RI(N);
		FOR(i,0,N)
			RI(arr[i]);
		printf("Case #%d: %d\n",ic,DP(0,E));
	}
	return 0;
}


////////////////////////////////////////////
/////////////Code by David Moran////////////
/////////////////////////////P=NP///////////
