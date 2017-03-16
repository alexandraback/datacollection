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
int x[1000];
int y[1000];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,n) y[i]=1;
	int ret=0; REP(i,n) if(x[i]>ret) ret=x[i];
	for(int ysum=1;ysum<ret;++ysum) {
		int best=-1,besti=-1;
		REP(i,n) { int val=(x[i]+y[i]-1)/y[i]; if(val>best) best=val,besti=i; }
		++y[besti];
		int cur=0; REP(i,n) { int val=(x[i]+y[i]-1)/y[i]; if(val>cur) cur=val; } cur+=ysum;
		if(cur<ret) ret=cur;
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
