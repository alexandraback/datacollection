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
#include <ctime>
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


int N=3;
int K=7;
int M=5;

typedef struct Case {
	vector<int> numbers;
	vector<ll> prods;
} Case;

Case gen() {
	Case ret;
	REP(i,N) ret.numbers.PB(rand()%(M-2)+2); sort(ret.numbers.begin(),ret.numbers.end());
	REP(i,K) { ll cur=1; REP(j,N) if(rand()%2) cur*=ret.numbers[j]; ret.prods.PB(cur); }
	return ret;
}

int cntok=0,cnttot=0;

/*
void test() {
	Case cur=gen();
	int cnt7=0,min7=0;
	REPSZ(i,cur.prods) { int now=0; while(cur.prods[i]%7==0) { ++cnt7; ++now; cur.prods[i]/=7; } if(now>min7) min7=now; }
	int guess7=min7; FORE(i,min7,N) if(abs(i*K-2*cnt7)<abs(guess7*K-2*cnt7)) guess7=i;

	int cnt5=0,min5=0;
	REPSZ(i,cur.prods) { int now=0; while(cur.prods[i]%5==0) { ++cnt5; ++now; cur.prods[i]/=5; } if(now>min5) min5=now; }
	int guess5=min5; FORE(i,min5,N-guess7) if(abs(i*K-2*cnt5)<abs(guess5*K-2*cnt5)) guess5=i;

	int cnt3=0,min36=0;
	REPSZ(i,cur.prods) { int now=0; while(cur.prods[i]%3==0) { ++cnt3; ++now; cur.prods[i]/=3; } if(now>min36) min36=now; }
	int guess36=min36; FORE(i,min36,N-guess7-guess5) if(abs(i*K-2*cnt3)<abs(guess36*K-2*cnt3)) guess36=i;

	int have36=0,have5=0,have7=0; REPSZ(i,cur.numbers) if(cur.numbers[i]==3||cur.numbers[i]==6) ++have36; else if(cur.numbers[i]==5) ++have5; else if(cur.numbers[i]==7) ++have7;

	if(guess36==have36&&guess5==have5&&guess7==have7) ++cntok;
	++cnttot;

	printf("%d vs %d + %d vs %d + %d vs %d\n",guess36,have36,guess5,have5,guess7,have7);
	REPSZ(i,cur.numbers) printf("%d ",cur.numbers[i]); puts("");
	REPSZ(i,cur.prods) printf("%lld ",cur.prods[i]); puts("");
}
*/

vector<ll> calc(vector<ll> prods) {
	int cnt5=0,min5=0;
	REPSZ(i,prods) { int now=0; while(prods[i]%5==0) { ++cnt5; ++now; prods[i]/=5; } if(now>min5) min5=now; }

	int cnt3=0,min3=0;
	REPSZ(i,prods) { int now=0; while(prods[i]%3==0) { ++cnt3; ++now; prods[i]/=3; } if(now>min3) min3=now; }

	int cnt2=0,min2=0; bool any2=false;
	REPSZ(i,prods) { int now=0; while(prods[i]%2==0) { ++cnt2; ++now; prods[i]/=2; } if(now>min2) min2=now; if(now%2==1) any2=true; }

	int guess5=min5; FORE(i,min5,N-min3-(any2?1:0)) if(abs(i*K-2*cnt5)<abs(guess5*K-2*cnt5)) guess5=i;
	int guess3=min3; FORE(i,min3,N-guess5-(any2?1:0)) if(abs(i*K-2*cnt3)<abs(guess3*K-2*cnt3)) guess3=i;

	int nrem=N-guess5-guess3;
	int guess4=0; FORE(i,0,nrem) if(abs((nrem-i)*K+i*2*K-2*cnt2)<abs((nrem-guess4)*K+guess4*2*K-2*cnt2)) guess4=i;
	if(nrem==1&&min2==2) guess4=1;
	if(any2&&guess4==nrem) --guess4;

	vector<ll> ret(M+1,0); if(5<SZ(ret)) ret[5]=guess5; if(3<SZ(ret)) ret[3]=guess3; if(4<SZ(ret)) ret[4]=guess4; ret[2]=nrem-guess4; return ret;
}

void test() {
	Case cur=gen();
	vector<ll> guess=calc(cur.prods);
	vector<ll> origprods=cur.prods;


//	if(nrem==1&&min2==2) assert(guess4==1);

	vector<int> have(M+1,0); REPSZ(i,cur.numbers) ++have[cur.numbers[i]];

	bool ok=guess[4]==have[4]&&guess[3]==have[3]&&guess[5]==have[5];
	if(ok) ++cntok;
	++cnttot;
	if(ok) return;

	REPSZ(i,cur.numbers) printf("%d ",cur.numbers[i]); puts("");
	REPSZ(i,cur.prods) printf("%lld ",cur.prods[i]); puts("");
	printf("%d vs %d + %d vs %d + %d vs %d\n",guess[4],have[4],guess[3],have[3],guess[5],have[5]);
}

void runtests() {
	srand(time(NULL));
	REP(i,100) test();
	printf("%lf\n",1.0*cntok/cnttot);
}



void run(int casenr) {
	int R;
	scanf("%d%d%d%d",&R,&N,&M,&K);
	printf("Case #%d:\n",casenr);
	REP(i,R) {
		vector<ll> prods(K); REP(j,K) scanf("%lld",&prods[j]);
		vector<ll> guess=calc(prods);
		REPSZ(i,guess) REP(j,guess[i]) printf("%d",i); puts("");
	}
}


int main() {
//	runtests();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
