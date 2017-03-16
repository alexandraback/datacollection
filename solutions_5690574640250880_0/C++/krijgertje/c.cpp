#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

// nxt[c][r][k] = whether possible to have k empty cells in c columns of nonincreasing length >=2, the longest=first of which is r
// if !=-1, then the value is the length of the next column
int nxt[51][51][2501]; 

int cnt[51];

char g[50][50];

int h,w,mines;

void check() {
	int cnt=0; REP(i,h) REP(j,w) if(g[i][j]=='*') ++cnt; assert(cnt==mines);
}

bool solve() {
	int empty=h*w-mines;
//	printf("=%d %d %d -> %d\n",h,w,mines,empty);
	if(h==1) {
		REP(i,h) REP(j,w) g[i][j]=j==0?'c':j<empty?'.':'*';
		return true;
	}
	if(w==1) { 
		REP(i,h) REP(j,w) g[i][j]=i==0?'c':i<empty?'.':'*';
		return true;
	}
	if(empty==1) {
		REP(i,h) REP(j,w) g[i][j]=i==0&&j==0?'c':'*';
		return true;
	}
	int c=-1,r=-1,k=empty;
	REPE(cc,w-1) { REPE(rr,h) if(empty>=rr&&nxt[cc][rr][k-rr]!=-1) { c=cc,r=rr; break; } if(c!=-1||r!=-1) break; }
	if(c==-1&&r==-1) return false;

	memset(cnt,0,sizeof(cnt));
	cnt[0]=r; k-=r; for(int i=1;c>0;++i) { cnt[i]=r; int nc=c-1,nr=nxt[c][r][k],nk=k-r; c=nc,r=nr,k=nk; }
	REP(i,h) REP(j,w) g[i][j]=i==0&&j==0?'c':i<cnt[j]?'.':'*';

	check();
	return true;
}

void print(bool ok) {
	if(!ok) { printf("Impossible\n"); return; }
	REP(i,h) { REP(j,w) printf("%c",g[i][j]); puts(""); }
}

void run(int casenr) {
	scanf("%d%d%d",&h,&w,&mines);
	printf("Case #%d:\n",casenr);
	bool ok=solve();
	print(ok);
}

void precalc() {
	memset(nxt,-1,sizeof(nxt));
	FORE(i,2,50) nxt[1][i][i]=0;
	FORE(r,2,50) FORE(c,1,50) FORE(k,1,2500) {
		if(nxt[r][c-1][k-1]!=-1) nxt[r][c][k]=nxt[r][c-1][k-1];
		if(k>=c&&nxt[r-1][c][k-c]!=-1) nxt[r][c][k]=c;
	}
}


int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//h=5,w=5; for(mines=0;mines<h*w;++mines) print(solve());
	return 0;
}
