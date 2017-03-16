#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

#define GI(n) scanf("%d", &n)
#define GI2(n,m) scanf("%d %d", &n, &m)

const char* decstr = "yhesocvxduiglbkrztnwjpfmaq";


int main() {
//freopen("input.txt", "rt", stdin);
freopen("A-small-attempt0.in", "rt", stdin);
freopen("A-small-attempt0.out", "w", stdout);

int ntc; GI(ntc);
string s;
getline(cin, s);
FORE(tc, 1, ntc) {
	getline(cin, s);
	FIR(s.size()) if (isalpha(s[i]))
		s[i] = decstr[s[i] - 'a'];
	printf("Case #%d: ", tc);
	cout << s << endl;
}

}
