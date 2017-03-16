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

const int MAXHAVE=1000;
const int MAXL=MAXHAVE;
const int MAXR=MAXHAVE;
const int MAXLEN=20;

int have;
char s[MAXLEN+1];
map<string,int> id[2];

int n[2];
int head[MAXL],nxt[MAXHAVE],to[MAXHAVE];

bool done[MAXL];
int match[MAXR];

int getid(int x) { if(id[x].count(s)) return id[x][s]; return id[x][s]=n[x]++; }
bool augment(int at) {
	if(done[at]) return false; else done[at]=true;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(match[to[x]]==-1||augment(match[to[x]])) { match[to[x]]=at; return true; }
	}
	return false;
}



void run(int casenr) {
	scanf("%d",&have);
	n[0]=n[1]=0; id[0].clear(); id[1].clear();
	memset(head,-1,sizeof(head));
	REP(i,have) {
		scanf("%s",s); int lid=getid(0);
		scanf("%s",s); int rid=getid(1);
		nxt[i]=head[lid]; head[lid]=i; to[i]=rid;
	}
	memset(match,-1,sizeof(match));
	int nmatch=0;
	REP(i,n[0]) {
		memset(done,false,sizeof(done));
		if(augment(i)) ++nmatch;
	}
	int need=nmatch+n[0]-nmatch+n[1]-nmatch;
	printf("Case #%d: %d\n",casenr,have-need);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
