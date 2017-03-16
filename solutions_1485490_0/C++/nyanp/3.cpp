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

using namespace std;

typedef map<char,char> dict;
typedef vector<int> VI;
typedef long long LL;
#define VLL vector<long long>
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  


char buf[1024];

int ni(){
	int i;
	scanf("%d", &i);
	return i;
}

char nc(){
	char c;
	scanf("%c", &c);
	return c;
}

double nd(){
	double i;
	scanf("%lf", &i);
	return i;
}

string ns() { 
	scanf( "%s", buf ); return buf; 
}

string nl() {
	scanf("%[a-z ]\n", buf); return buf;
}

#define NMAX 3
#define MMAX 100

int a[NMAX];
LL na[NMAX];
int b[MMAX];
LL nb[MMAX];
int N,M;

LL dp[NMAX+1][MMAX+1];

void update(LL init, int ai, int bi, LL suma, LL sumb) {
	LL nsuma = suma + na[ai];
	LL nsumb = sumb + nb[bi];

	dp[ai+1][bi+1] = max(dp[ai+1][bi+1], init+min(nsuma,nsumb));

	if (nsumb > nsuma) {
		FOR(i,ai+1,N) {
			if (a[i] == a[ai]) {
				update(init, i, bi, nsuma, sumb);
				break;
			}
		}
	}

	if (nsuma > nsumb) {
		FOR(i,bi+1,M) {
			if (b[i] == b[bi]) {
				update(init, ai, i, suma, nsumb);
				break;
			}
		}
	}

}

LL main2() {
	N = ni();
	M = ni();
	FOR(i,0,N) { na[i] = ni(); a[i] = ni(); }
	FOR(i,0,M) { nb[i] = ni(); b[i] = ni(); }

	memset(dp,0,sizeof(dp));

	FOR(i,0,N) {
		FOR(j,0,M) {
			if (a[i] == b[j]) {
				update(dp[i][j],i,j,0LL,0LL);
			} //else {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
			//}
		}
	}
	return max(dp[N][M], max(dp[N-1][M], dp[N][M-1]));
}

int main(void){
	int T = ni();

	FOR(t,0,T) {
		LL res = main2();
		printf("Case #%d: %lld\n", t+1, res);
	}
}