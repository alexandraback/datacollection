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
#include <numeric>

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

int g[50][50];
int N;
int T;
int found = 0;

bool hasMultiPath(int from, int to)
{
	if (g[from][to]) {
		found++;
		if (found > 1) return true;
	}

	FOR(i,0,N) {
		if (g[from][i]) {
			if (hasMultiPath(i, to)) return true;
		}
	}	
	return false;
}

bool main2() {
	memset(g, 0, sizeof(g));
	scanf("%d",&N);
	FOR(i,0,N) {
		int n = ni();
		FOR(j,0,n) {
			int adj = ni();
			g[i][adj-1] = 1;
		}
	}

	FOR(i,0,N) {
		FOR(j,0,N) {
			if (i==j) continue;
			found = 0;
			if (hasMultiPath(i,j)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d",&T);

	FOR(t,0,T) {
		printf("Case #%d: ",t+1);
		if (main2()) printf("Yes\n");
		else printf("No\n");

	}
}
