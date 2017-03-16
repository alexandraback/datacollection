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

const int MAXN=32;
const int MAXWANT=500;
typedef struct Sol { int msk; int val[11]; } Sol;
bool operator<(const Sol &a,const Sol &b) { FORE(x,2,10) if(a.val[x]!=b.val[x]) return a.val[x]<b.val[x]; return false; }


int n,want;
char ret[MAXWANT][MAXN+1]; int retdv[MAXWANT][11]; int nret;

int amod[11][2]={{0,0},{0,0},{3,5},{2,5},{3,5},{2,3},{5,7},{2,3},{3,5},{2,5},{3,7}};
int mlt[MAXN];
int mod[11];

Sol a[1<<((MAXN-2)/2)]; int na;
Sol b[1<<((MAXN-2)/2)]; int nb;


void calc() {
	int n1=(n-2)/2,n2=(n-2)-n1;
	//mod[2]=3; mod[3]=2; mod[4]=3; mod[5]=2; mod[6]=5; mod[7]=2; mod[8]=3; mod[9]=2; mod[10]=3;
	FORE(x,2,10) mod[x]=amod[x][rand()%2];
	// 1*x^(n-1)+ai*x^(n-2)+...+ai*x^(1)+1 % mod[x] = 0
	na=nb=0;
	REP(i,1<<n1) {
		FORE(x,2,10) {
			mlt[0]=1; FOR(j,1,n) mlt[j]=mlt[j-1]*x%mod[x];
			int cur=mlt[0]; REP(j,n1) if(i&(1<<j)) cur+=mlt[1+j]; cur%=mod[x]; a[na].val[x]=cur;
		}
		a[na++].msk=i;
	}
	REP(i,1<<n2) {
		FORE(x,2,10) {
			mlt[0]=1; FOR(j,1,n) mlt[j]=mlt[j-1]*x%mod[x];
			int cur=mlt[1+n1+n2]; REP(j,n2) if(i&(1<<j)) cur+=mlt[1+n1+j]; cur%=mod[x]; b[nb].val[x]=cur;
		}
		b[nb++].msk=i;
	}
	sort(a,a+na);
	//REP(i,na) { printf("a%x:",a[i].msk); FORE(x,2,10) printf(" %d",a[i].val[x]); puts(""); }
	//REP(i,nb) { printf("b%x:",b[i].msk); FORE(x,2,10) printf(" %d",b[i].val[x]); puts(""); }
	REP(i,nb) {
		int l=-1,h=na; // b[i]+a[l] niet te groot
		while(l+1<h) {
			int m=l+(h-l)/2;
			bool diff=false;
			FORE(x,2,10) {
				if(b[i].val[x]==0&&a[m].val[x]>0) { h=m; diff=true; break; }
				if(b[i].val[x]!=0&&b[i].val[x]+a[m].val[x]!=mod[x]) { if(b[i].val[x]+a[m].val[x]<mod[x]) l=m; else h=m; diff=true; break; }
			}
			if(!diff) l=m;
			//printf("\t"); FORE(x,2,10) printf("%d ",a[m].val[x]); printf("-> %s\n",l==m?"->":"<-");
		}
		if(l==-1) continue;
		//FORE(x,2,10) printf("%d ",(b[i].val[x]+a[l].val[x])%mod[x]); puts("");
		bool match=true;
		if(l!=-1) FORE(x,2,10) if(b[i].val[x]+a[l].val[x]!=0&&b[i].val[x]+a[l].val[x]!=mod[x]) { match=false; break; }
		if(!match) continue;
		ret[nret][0]='1'; REP(j,n1) ret[nret][1+j]=(a[l].msk&(1<<j))?'1':'0'; REP(j,n2) ret[nret][1+n1+j]=(b[i].msk&(1<<j))?'1':'0'; ret[nret][1+n1+n2]='1'; ret[nret][1+n1+n2+1]='\0'; reverse(ret[nret]+0,ret[nret]+1+n1+n2+1);
		FORE(x,2,10) retdv[nret][x]=mod[x];
		bool have=false;
		REP(j,nret) if(strcmp(ret[j],ret[nret])==0) have=true;
		if(have) continue;
		if(++nret>=want) break;
	}
}


void run(int casenr) {
	scanf("%d%d",&n,&want);
	nret=0;
	REP(x,1000) if(nret<want) calc();
	/*REP(i,nret) {
		printf("%s\n",ret[i]);
		FORE(x,2,10) { ll val=0; REP(j,n) val=val*x+ret[i][j]-'0'; if(val%retdv[i][x]!=0) printf("\t%d: %lld %% %d = %lld\n",x,val,retdv[i][x],val%retdv[i][x]); }
	}*/
	printf("Case #%d:\n",casenr);
	REP(i,nret) { printf("%s",ret[i]); FORE(x,2,10) printf(" %d",retdv[i][x]); puts(""); }
	if(nret<want) printf("not enough!\n");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
