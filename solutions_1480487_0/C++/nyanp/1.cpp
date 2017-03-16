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

int main() {
	int n = ni();

	FOR(i,0,n) {
		int N = ni();
		VI v(N,0);
		VI flag(N,0);

		FOR(j,0,N) v[j] = ni();
		int sum = accumulate(v.begin(), v.end(), 0);
		double Alpha = 2.0 * sum / N;

		printf("Case #%d: ", i+1);

		FOR(j,0,N) {
			if (Alpha - v[j] < 0.0) flag[j] = 1;
			else flag[j] = 0;
		}
		int sum2 = 0;
		int N2 = 0;
		FOR(j,0,N) {
			if (flag[j] == 0) { sum2 += v[j]; N2++; }
		}
		Alpha = (sum + sum2) * 1.0 / N2;

		FOR(j,0,N) {
			if (flag[j]) printf("0.000000");
			else printf("%.6f", 100.0*(Alpha - v[j])/sum);
			printf("%c", j==N-1?'\n':' ');
		}
	}
}