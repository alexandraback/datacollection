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

int main(void){
	int T = ni();
	for (int c = 0; c < T; c++) {
		int A = ni();
		int B = ni();
		vector<double> p(A,0);
		FOR(i,0,A) p[i] = nd();

		int cost[4][4];
		double pn[4];

		cost[0][0] = B-A+1;   cost[0][1] = B-A+3;   cost[0][2] = B-A+5; cost[0][3] = B+2;
		cost[1][0] = 2*B-A+2; cost[1][1] = B-A+3; cost[1][2]=B-A+5; cost[1][3]=B+2;
		cost[2][0] = 2*B-A+2; cost[2][1]=2*B-A+4; cost[2][2]=B-A+5; cost[2][3]=B+2;
		cost[3][0] = 2*B-A+2; cost[3][1]=2*B-A+4; cost[3][2]=2*B-A+6; cost[3][3]=B+2;

		pn[0] = 1.0; FOR(i,0,A) pn[0] *= p[i];
		pn[1] = 1 - p[A-1]; FOR(i,0,A-1) pn[1] *= p[i];
		if (A == 1) {
			pn[2]= 0;
		} else {
			pn[2] = 1 - p[A-2]; FOR(i,0,A-2) pn[2] *= p[i];
		}
		pn[3] = 1 - pn[0] -pn[1] - pn[2];

		double exp[4];
		double minC = 1E10;
		FOR(i,0,4) {
			exp[i] = pn[0]*cost[0][i] + pn[1]*cost[1][i] + pn[2]*cost[2][i] + pn[3]*cost[3][i];
			minC = min(minC, exp[i]);
		}
		printf("Case #%d: %.6f\n", c+1, minC);
	}
}