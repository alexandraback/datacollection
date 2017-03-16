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

const int MAXLEN=2000;

char s[MAXLEN+1]; int slen;
int cnt[26];
int ret[MAXLEN],nret;

void sub(char *s) { while(*s!='\0') --cnt[*s-'A'],++s; }

void run(int casenr) {
	scanf("%s",s); slen=strlen(s);
	memset(cnt,0,sizeof(cnt)); REP(i,slen) ++cnt[s[i]-'A'];
	nret=0;
	while(cnt['Z'-'A']>0) ret[nret++]=0,sub("ZERO");
	while(cnt['X'-'A']>0) ret[nret++]=6,sub("SIX");
	while(cnt['U'-'A']>0) ret[nret++]=4,sub("FOUR");
	while(cnt['F'-'A']>0) ret[nret++]=5,sub("FIVE");
	while(cnt['V'-'A']>0) ret[nret++]=7,sub("SEVEN");
	while(cnt['W'-'A']>0) ret[nret++]=2,sub("TWO");
	while(cnt['O'-'A']>0) ret[nret++]=1,sub("ONE");
	while(cnt['N'-'A']>0) ret[nret++]=9,sub("NINE");
	while(cnt['I'-'A']>0) ret[nret++]=8,sub("EIGHT");
	while(cnt['T'-'A']>0) ret[nret++]=3,sub("THREE");
	REP(i,26) assert(cnt[i]==0);
	sort(ret,ret+nret); printf("Case #%d: ",casenr); REP(i,nret) printf("%d",ret[i]); puts("");

}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
