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

const int MAXLEN=18;

int n;
char s[2][MAXLEN+1];

bool haveres;
ll res[2];

bool better(ll i,ll j) {
	 return !haveres||abs(i-j)<abs(res[1]-res[0])||abs(i-j)==abs(res[1]-res[0])&&(i<res[0]||i==res[0]&&j<res[1]);
}

void test(int neq,int B) {
	int A=1-B; ll ret[2]; ret[A]=ret[B]=0;
	REP(i,neq) {
		ret[A]=ret[A]*=10,ret[B]=ret[B]*=10;
		if(s[A][i]=='?'&&s[B][i]=='?') ret[A]+=0,ret[B]+=0;
		else if(s[A][i]=='?') ret[A]+=s[B][i]-'0',ret[B]+=s[B][i]-'0';
		else if(s[B][i]=='?') ret[A]+=s[A][i]-'0',ret[B]+=s[A][i]-'0';
		else if(s[A][i]==s[B][i]) ret[A]+=s[A][i]-'0',ret[B]+=s[B][i]-'0';
		else return;
	}
	if(neq<n) {
		ret[A]=ret[A]*=10,ret[B]=ret[B]*=10;
		if(s[A][neq]=='?'&&s[B][neq]=='?') ret[A]+=0,ret[B]+=1;
		else if(s[A][neq]=='?') { if(s[B][neq]=='0') return; ret[A]+=s[B][neq]-'0'-1,ret[B]+=s[B][neq]-'0'; }
		else if(s[B][neq]=='?') { if(s[A][neq]=='9') return; ret[A]+=s[A][neq]-'0',ret[B]+=s[A][neq]-'0'+1; }
		else if(s[A][neq]<s[B][neq]) ret[A]+=s[A][neq]-'0',ret[B]+=s[B][neq]-'0';
		else return;
	}
	FOR(i,neq+1,n) {
		ret[A]=ret[A]*=10,ret[B]=ret[B]*=10;
		if(s[A][i]=='?') ret[A]+=9; else ret[A]+=s[A][i]-'0';
		if(s[B][i]=='?') ret[B]+=0; else ret[B]+=s[B][i]-'0';
	}
	if(better(ret[0],ret[1])) haveres=true,res[0]=ret[0],res[1]=ret[1];
}

void printdig(ll x) {
	char buff[MAXLEN+1]; REP(i,n) buff[i]='0'+x%10,x/=10; reverse(buff,buff+n); buff[n]='\0'; printf("%s",buff);
}

bool match(char *s,int x) {
	REP(i,n) {
		int y=x%10; x/=10;
		char c=s[n-i-1]; if(c!='?'&&c-'0'!=y) return false;
	}
	return true;
}


void run(int casenr) {
	scanf("%s%s",s[0],s[1]); n=strlen(s[0]);
	haveres=false;
	REPE(neq,n) REP(lrg,2) test(neq,lrg);
	assert(haveres);

	//if(n==1) REP(i,10) REP(j,10) if(match(s[0],i)&&match(s[1],j)&&better(i,j)) { printf("err: "); printdig(i); printf(" "); printdig(j); puts(""); }
	//if(n==2) REP(i,100) REP(j,100) if(match(s[0],i)&&match(s[1],j)&&better(i,j)) { printf("err: "); printdig(i); printf(" "); printdig(j); puts(""); }
	//if(n==3) REP(i,1000) REP(j,1000) if(match(s[0],i)&&match(s[1],j)&&better(i,j)) { printf("err: "); printdig(i); printf(" "); printdig(j); puts(""); }

	printf("Case #%d: ",casenr); printdig(res[0]); printf(" "); printdig(res[1]); puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
