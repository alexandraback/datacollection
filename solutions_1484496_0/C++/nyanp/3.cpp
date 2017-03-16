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


int dp[20] = {0};

bool solve(VLL& vec) {
	LL a = 0;
	LL b = 0;

	FOR(i,0,20) {
		if (dp[i] == 1) a += vec[i];
		else if (dp[i] == 2) b += vec[i];
	}
	return a > 0 && a == b;
}

void printRes(VLL& vec) {
	VI a, b;

	FOR(i,0,20) {
		if (dp[i] == 1) a.push_back(vec[i]);
		else if (dp[i] == 2) b.push_back(vec[i]);
	}

	FOR(i,0,a.size()) {
		printf("%d%c", a[i], i == a.size()-1 ? '\n':' ');
	}
	FOR(i,0,b.size()) {
		printf("%d%c", b[i], i == b.size()-1 ? '\n':' ');
	}
}

#define LOOP(x,i) FOR(x,0,3) { dp[i] = x;

int main(void){
	int T = ni();

	FOR(i,0,T) {
		int N = ni();
		bool res = false;

		VLL v(N,0);
		FOR(j,0,N) v[j] = ni();

		LOOP(a0,0)
		LOOP(a1,1)
		LOOP(a2,2)
		LOOP(a3,3)
		LOOP(a4,4)
		LOOP(a5,5)
		LOOP(a6,6)
		LOOP(a7,7)
		LOOP(a8,8)
		LOOP(a9,9)
		LOOP(a10,10)
		LOOP(a11,11)		
		LOOP(a12,12)
		LOOP(a13,13)
		LOOP(a14,14)
		LOOP(a15,15)
		LOOP(a16,16)
		LOOP(a17,17)
		LOOP(a18,18)
		LOOP(a19,19)
		if (res = solve(v)) {goto N;}
		}}}}}}}}}}}}}}}}}}}}
		N:
		printf("Case #%d:\n",i+1);
		if (res) {
			printRes(v);
		} else {
			printf("Impossible\n");
		}
	}
}