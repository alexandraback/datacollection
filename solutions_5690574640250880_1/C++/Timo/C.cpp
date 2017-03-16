#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define DEBUGxy(x,y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define CLEAR(x) memset(x,0,sizeof(x))

inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

char ans[256][256];
char visit[256][256];

int DI[4]={0,+1,0,-1};
int DJ[4]={1,0,-1,0};

int dfs(int i,int j) {

	if(ans[i][j]!='.') return 0;

	if(visit[i][j]) return 0;
	visit[i][j]=1;

	int score=0;
	FOR(di,-1,+1) FOR(dj,-1,+1) {
		if(di==0&&dj==0) continue;
		if(ans[i+di][j+dj]=='*')
			score++;
	}

	int ret = 1;
	if(score==0) {
		FOR(di,-1,+1) FOR(dj,-1,+1) {
			if(di==0&&dj==0) continue;
			ret += dfs(i+di,j+dj);
		}
	}

	return ret;
}

bool solve(int R,int C,int &M) {
	int oriR = R;
	int RC = R * C;
	int oriM = M;

	CLEAR(ans);
	FOR(i,1,R) FOR(j,1,C) ans[i][j]='.';

	if(M==0) {
		ans[1][1]='c';
		return true;
	}

	if(R==1) {
		ans[R][C]='c';
		FOR(i,1,M) ans[R][i]='*';
		M=0;
		return true;
	}
	if(C==1) {
		ans[R][C]='c';
		FOR(i,1,M) ans[i][C]='*';
		M=0;
		return true;
	}

	if(M+1==R*C) {
		ans[1][1]='c';
		FOR(i,1,R) FOR(j,1,C) if(ans[i][j]=='.') ans[i][j]='*';
		M=0;
		return true;
	}

	if(R<=2 && C<=2) {
		return false;
	}

	while(M>0 && R>=4) {
		if(M >= C) {
			FOR(i,1,C) ans[R][i]='*';
			M -= C;
			R--;
		}else {
			break;
		}
	}

	while(M>0 && C>=4) {
		if(M >= R) {
			FOR(i,1,R) ans[i][C]='*';
			M -= R;
			C--;
		}else {
			break;
		}
	}


	while(M>0 && R>=3) {
		if(M >= C) {
			FOR(i,1,C) ans[R][i]='*';
			M -= C;
			R--;
		}else {
			break;
		}
	}

	while(M>0 && C>=3) {
		if(M >= R) {
			FOR(i,1,R) ans[i][C]='*';
			M -= R;
			C--;
		}else {
			break;
		}
	}

	if(M>0 && R>=3) {
		int take = min(M,C-2);
		M -= take;
		REP(i,take) ans[R][C-i]='*';
		R--;
	}

	if(M>0 && C>=3) {
		int take = min(M,R-2);
		M -= take;
		REP(i,take) ans[R-i][C]='*';
		C--;
	}

	if(M==0) {
		CLEAR(visit);
		int ctr = dfs(1,1);
		if(ctr+oriM == RC) {
			ans[1][1] = 'c';
			return true;
		}
	}

	return false;

}

int main() {
	OPEN("C");
	REP(ncase,getint()) {
		int R=getint();
		int C=getint();
		int M=getint();
		int oriM = M;

		printf("Case #%d:\n",ncase+1);
		if(solve(R,C,M)) {
			FOR(i,1,R) puts(ans[i]+1);
			DEBUGxy(M,"YES");
		}else {
			puts("Impossible");
			//printf("Impossible input %d %d %d\n",R,C,oriM);
			DEBUGxy(M,"NO");
		}

	}
	return 0;
}
