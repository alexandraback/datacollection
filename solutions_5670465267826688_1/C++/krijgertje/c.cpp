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

// 1=unit, 2=i, 3=j, 4=k

int tab[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};


int mult(int a,int b) {	assert(1<=abs(a)&&abs(a)<=4); assert(1<=abs(b)&&abs(b)<=4); int ret=1; if(a<0) ret=-ret,a=-a; if(b<0) ret=-ret,b=-b; ret*=tab[a-1][b-1]; return ret; }
ll mypow(int val,ll n) {
	if(n==0) return 1;
	if(n%2==1) return mult(val,mypow(val,n-1));
	return mypow(mult(val,val),n/2);
}


int len; ll times;
char s[10001];
int d[10000];

bool test() {
	//REP(i,len) printf("%d ",d[i]); puts("");
	int prod=1; REP(i,len) prod=mult(prod,d[i]); prod=mypow(prod,times); 
	//printf("prod=%d\n",prod);
	if(prod!=-1) return false;
	ll totlen=len*times;
	int at=0;
	int ival=1,ilen=0;
	while(at<totlen&&ilen<4*len&&ival!=2) { ival=mult(ival,d[at%len]); ++at; ++ilen; }
	if(ival!=2) return false;
	int jval=1,jlen=0;
	while(at<totlen&&jlen<4*len&&jval!=3) { jval=mult(jval,d[at%len]); ++at; ++jlen; }
	if(jval!=3) return false;
	//int kval=1,klen=0;
	//while(at<totlen) { kval=mult(kval,d[at%len]); ++at; ++klen; }
	//assert(kval==4);
	return true;
}

void run(int casenr) {
	scanf("%d%lld%s",&len,&times,&s);
	REP(i,len) d[i]=s[i]=='i'?2:s[i]=='j'?3:s[i]=='k'?4:1;
	printf("Case #%d: %s\n",casenr,test()?"YES":"NO");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
