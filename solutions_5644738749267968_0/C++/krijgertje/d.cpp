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

int calc(double *a,double *b) {
	int ret=0;
	int i=0,j=0;
	while(i<n&&j<n) {
		while(i<n&&a[i]<b[j]) ++i;
		if(i<n) { ++ret; ++i; ++j; }
	}
	return ret;
}


double a[1000],b[1000];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%lf",&a[i]);
	REP(i,n) scanf("%lf",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	int deceit=calc(a,b),normal=n-calc(b,a);
	printf("Case #%d: %d %d\n",casenr,deceit,normal);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
