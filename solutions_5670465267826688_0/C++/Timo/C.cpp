#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

char input[10002];
char data[10002];
int ok[10002];

int mul(int a,int b) {
	if(a<0) return -mul(-a,b);
	if(b<0) return -mul(a,-b);
	if(a==1) return b;
	if(b==1) return a;
	if(a=='i' && b=='j') return 'k';
	if(a=='i' && b=='k') return -'j';
	if(a=='j' && b=='i') return -'k';
	if(a=='j' && b=='k') return 'i';
	if(a=='k' && b=='i') return 'j';
	if(a=='k' && b=='j') return -'i';
	return -1;
}

int can(int len) {

	REP(i,len) {
		int v = 1;
		ok[i] = 0;
		FOR(j,i,len-1) v = mul(v,data[j]);
		if(v=='k') ok[i] = 1;
	}

	int curr1 = 1;
	REP(i,len) {
		curr1 = mul(curr1,data[i]);
		if(curr1=='i') {
			int curr2 = 1;
			FOR(j,i+1,len-1) {
				curr2 = mul(curr2,data[j]);
				if(curr2=='j') {
					if(j+1<len && ok[j+1]) return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	OPEN("C");
	REP(nc,getint()) {
		int L = getint();
		int X = getint();
		scanf("%s",input);
		data[0]=0;
		REP(i,X) strcat(data,input);
		int len = L*X;
		printf("Case #%d: %s\n",nc+1,can(len)?"YES":"NO");
	}
	return 0;
}
