#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll R,N,M,K;

int pnum[20][10];
int func(int n2,int ne) {
	int x2,x4,x8,i,j;
	int ok[13][40];
	
	for(x2=0;x2<=ne;x2++) {
		for(x4=x2;x4<=ne;x4++) {
			ZERO(ok);
			ok[0][0]=1;
			FOR(i,ne) FOR(j,36) {
				ok[i+1][j]+=ok[i][j];
				if(i>=x4) ok[i+1][j+3]+=ok[i][j];
				else if(i>=x2) ok[i+1][j+2]+=ok[i][j];
				else ok[i+1][j+1]+=ok[i][j];
			}
			
			int ng=0;
			FOR(i,N) if(ok[ne][pnum[i][2]]==0) ng=1;
			if(ng==0) {
				FOR(i,ne) {
					if(i>=x4) _P("8");
					else if(i>=x2) _P("4");
					else _P("2");
				}
				return 0;
			}
		}
	}
	return 1;
}


void solve2(vector<ll>& V) {
	int s1,s2,s3,i,x;
	ll p10[20],p5[20];
	int id2m[5]={2,3,4,6,8};
	
	p10[0]=p5[0]=1;
	FOR(i,13) p10[i+1]=p10[i]*10;
	FOR(i,13) p5[i+1]=p5[i]*5;
	
	ZERO(pnum);
	FOR(i,V.size()) {
		ll v=V[i];
		while(v%2==0) {pnum[i][2]++; v/=2;}
		while(v%3==0) {pnum[i][3]++; v/=3;}
		while(v%5==0) {pnum[i][5]++; v/=5;}
		while(v%7==0) {pnum[i][7]++; v/=7;}
		pnum[13][2]=max(pnum[i][2],pnum[13][2]);
		pnum[13][3]=max(pnum[i][3],pnum[13][3]);
		pnum[13][5]=max(pnum[i][5],pnum[13][5]);
		pnum[13][7]=max(pnum[i][7],pnum[13][7]);
	}
	
	vector<int> res;
	FOR(i,pnum[13][5]) res.push_back(5);
	FOR(i,pnum[13][7]) res.push_back(7);
	FOR(i,pnum[13][3]) {
		if(pnum[13][2]--) res.push_back(6);
		else res.push_back(3);
	}
	while(func(pnum[13][2],N-res.size())==1) {
		FOR(i,res.size()) if(res[i]==6) {
			res[i]=3;
			pnum[13][2]++;
			break;
		}
		if(i==res.size()) break;
	}
	FOR(i,res.size()) _P("%d",res[i]);
	_P("\n");
	
	
	return;
	/*
	if(num[2]==num[3]) {
		FOR(i,(num[2]+6)/12) res.push_back(6);
	}
	else if(num[2]%3==0){
		FOR(i,(num[2]/3+6)/12) res.push_back(8);
	}
	else if(num[2]%2==0){
		FOR(i,(num[2]/2+6)/12) res.push_back(4);
	}
	int RS=res.size();
	res.resize(N);
	
	if(RS==N) {
		FOR(i,N) _P("%d",res[i]);
		return;
	}
	
	int cand[40][30][13][13];
	vector<pair<ll,ll> > C;
	
	for(ll ty=0;ty<p5[N-RS];ty++) {
		if(N-RS>10){
			if((ty/5)%5<ty%5) continue;
			if((ty/25)%5<(ty/5)%5) continue;
		}
		
		FOR(i,N-RS) res[RS+i]=id2m[(ty/p5[i])%5];
		ZERO(cand);
		FOR(i,1<<N) {
			int P[10];
			ZERO(P);
			FOR(x,N) if(i&(1<<x)) P[res[x]]++;
			cand[res[2]+res[4]*2+res[6]+res[8]*3][res[3]+res[6]][res[5]][res[7]]++;
		}
		
		ll prop=1;
		FOR(i,V.size()){
			ll c=V[i];
			int P2[10];
			ZERO(P2);
			while(c%2==0) {P2[2]++; c/=2;}
			while(c%3==0) {P2[3]++; c/=3;}
			while(c%5==0) {P2[5]++; c/=5;}
			while(c%7==0) {P2[7]++; c/=7;}
			prop *= cand[P2[2]][P2[3]][P2[5]][P2[7]];
		}
		if(prop) {
			ll key=0;
			FOR(i,N) key+=p10[i]*res[i];
			C.push_back(make_pair(prop,key));
		}
		
	}
	
	
	sort(C.begin(),C.end());
	_P("%lld\n",C[0].second);
	*/
}



void solve(int _loop) {
	int i,j,x,y,ne=0;
	
	_PE("Case #%d:\n",_loop);
	
	cin >> R >> N >> M >> K;
	FOR(y,R) {
		vector<ll> V;
		FOR(x,K) V.push_back(GETi());
		sort(V.begin(),V.end());
		solve2(V);
	}
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



