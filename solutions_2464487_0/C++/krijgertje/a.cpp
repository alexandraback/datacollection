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

bool can(ll r,ll x,ll have) {
	ll rem=have;
	if(2*r-1>rem/x) return false; else rem-=(2*r-1)*x;
	if(2*(x-1)>rem/x) return false; else rem-=2*x*(x-1);
//	printf("\t %lld -> remaining %lld\n",x,rem);
	return rem>=0;
}

void run(int casenr) {
	ll r,have;
	scanf("%lld%lld",&r,&have); ++r;

	ll l=0,h=1;
	while(can(r,h,have)) l=h,h+=h;
	while(l+1<h) { ll m=l+(h-l)/2; if(can(r,m,have)) l=m; else h=m; }
	printf("Case #%d: %lld\n",casenr,l);
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
