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

int n;
int x[1000],cnt[1000],t[1000];

ll calc() {
	ll ret=LLONG_MAX;
	REP(i,n) REP(j,cnt[i]) {
		int ct=t[i]+j;
		// (360-x[i])/360*ct
		ll cur=0;
		REP(ii,n) REP(jj,cnt[ii]) {
			int ctt=t[ii]+jj;
			if((360LL-x[ii])*ctt>(360LL-x[i])*ct) { ++cur; continue; }
			ll times=((360LL-x[i])*ct-(360LL-x[ii])*ctt)/(360LL*ctt);
			cur+=times;
		}
		//printf("%d %d -> %lf -> %d\n",i,j,(360-x[i])/360.0*ct,cur);
		if(cur<ret) ret=cur;
	}
	return ret;
}

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&x[i],&cnt[i],&t[i]);
	printf("Case #%d: %lld\n",casenr,calc());
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
