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

int n,h,w;

bool test() {
	if(n>=7) return false;
	if(h*w%n!=0) return false;
	if(h<w) swap(h,w);
	switch(n) {
		case 1: return true;
		case 2: return true;
		case 3: return w>=2&&h>=3;
		case 4: return w>=3&&h>=4;
		case 5: return w>=4&&h>=5;
		case 6: return w>=4&&h>=6;
		default: return false;
	}
}

void run(int casenr) {
	scanf("%d%d%d",&n,&h,&w);
	printf("Case #%d: %s\n",casenr,test()?"GABRIEL":"RICHARD");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
