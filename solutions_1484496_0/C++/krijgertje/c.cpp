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


void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	map<int,vector<int> > ways;
	FOR(i,1,1<<n) {
		int sum=0; REP(j,n) if(i&(1<<j)) sum+=x[j];
		ways[sum].PB(i);
	}
	for(map<int,vector<int> >::iterator i=ways.begin();i!=ways.end();++i) {
		REPSZ(j,i->second) FORSZ(k,j+1,i->second) if((i->second[j]&i->second[k])==0) {
			printf("Case #%d:\n",casenr);
			int a=i->second[j]; bool firsta=true; REP(q,n) if(a&(1<<q)) { if(firsta) firsta=false; else printf(" "); printf("%d",x[q]); } puts("");
			int b=i->second[k]; bool firstb=true; REP(q,n) if(b&(1<<q)) { if(firstb) firstb=false; else printf(" "); printf("%d",x[q]); } puts("");
			return;
		}
	}
	printf("Case #%d:\nImpossible\n",casenr);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
