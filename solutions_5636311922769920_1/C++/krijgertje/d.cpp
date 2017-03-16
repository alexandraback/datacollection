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

const int MAXHAVE=100;

int len,times,have;
ll ret[MAXHAVE]; int nret;

void run(int casenr) {
	scanf("%d%d%d",&len,&times,&have);
	if(have*times<len) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
	nret=0; REP(i,(len+times-1)/times) { ll cur=0; REP(j,times) { int now=i*times+j<len?i*times+j:0; cur=cur*len+now; } ret[nret++]=cur; }
	printf("Case #%d:",casenr); REP(i,nret) printf(" %lld",ret[i]+1); puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
