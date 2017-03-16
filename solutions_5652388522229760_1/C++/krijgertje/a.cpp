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

int calc(int n) {
	int seen=0;
	for(int i=1;;++i) {
		int x=n*i;
		while(x>0) seen|=1<<(x%10),x/=10;
		if(seen==(1<<10)-1) return n*i;
	}
}

int n;
void run(int casenr) {
	scanf("%d",&n);
	if(n==0) { printf("Case #%d: INSOMNIA\n",casenr); return; }
	printf("Case #%d: %d\n",casenr,calc(n));
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
