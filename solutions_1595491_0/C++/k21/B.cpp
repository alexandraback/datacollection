#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<a;++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int T, N, S, P;
int score[200];

int main() {
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d%d%d", &N, &S, &P);
		REP(i,N) scanf("%d", score+i);
		int minc = 3*P-2, mins = max(3*P-4,P);
		int res = 0;
		REP(i,N) {
			if (score[i] >= minc) ++res;
			else if (score[i] >= mins && S) { ++res; --S; }
		}
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
