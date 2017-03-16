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

int nstartkeys,nchests;
vector<int> startkeys;
vector<int> need;
vector<vector<int> > have;

int typecnt;
vector<int> curtypes;

int mem[1<<20];
bool ok(int mask) {
	if(mask==(1<<nchests)-1) return 1;
	int &ret=mem[mask];
	if(ret==-1) {
		ret=0;
		REP(at,nchests) if((mask&(1<<at))==0&&curtypes[need[at]]>0) {
			REPSZ(i,have[at]) ++curtypes[have[at][i]]; --curtypes[need[at]]; mask|=1<<at;
			if(ok(mask)) ret=1;
			REPSZ(i,have[at]) --curtypes[have[at][i]]; ++curtypes[need[at]]; mask&=~(1<<at);
		}
	}
	return ret;
}

void run(int casenr) {
	scanf("%d%d",&nstartkeys,&nchests);
	startkeys.clear(); REP(i,nstartkeys) { int x; scanf("%d",&x); startkeys.PB(x); }
	need=vector<int>(nchests); have=vector<vector<int> >(nchests);
	REP(i,nchests) { int cnt; scanf("%d%d",&need[i],&cnt); REP(j,cnt) { int x; scanf("%d",&x); have[i].PB(x); } }

	vector<int> alltypes; REPSZ(i,startkeys) alltypes.PB(startkeys[i]); REP(i,nchests) alltypes.PB(need[i]); REP(i,nchests) REPSZ(j,have[i]) alltypes.PB(have[i][j]);
	sort(alltypes.begin(),alltypes.end()); alltypes.erase(unique(alltypes.begin(),alltypes.end()),alltypes.end()); map<int,int> typemap; REPSZ(i,alltypes) typemap[alltypes[i]]=i;
	REPSZ(i,startkeys) startkeys[i]=typemap[startkeys[i]]; REP(i,nchests) need[i]=typemap[need[i]]; REP(i,nchests) REPSZ(j,have[i]) have[i][j]=typemap[have[i][j]];

	typecnt=SZ(alltypes);
	curtypes=vector<int>(typecnt,0);
	REPSZ(i,startkeys) curtypes[startkeys[i]]++;

	memset(mem,-1,sizeof(mem));
	int mask=0; vector<int> path;
	while(mask!=(1<<nchests)-1) {
		bool found=false;
		REP(at,nchests) if((mask&(1<<at))==0&&curtypes[need[at]]>0) {
			REPSZ(i,have[at]) ++curtypes[have[at][i]]; --curtypes[need[at]]; mask|=1<<at;
			if(ok(mask)) {
				found=true;
				path.PB(at);
				break;
			}
			REPSZ(i,have[at]) --curtypes[have[at][i]]; ++curtypes[need[at]]; mask&=~(1<<at);
		}
		if(!found) break;
	}
	if(mask!=(1<<nchests)-1) {
		printf("Case #%d: IMPOSSIBLE\n",casenr);
	} else {
		printf("Case #%d:",casenr); REPSZ(i,path) printf(" %d",path[i]+1); puts("");
	}
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}