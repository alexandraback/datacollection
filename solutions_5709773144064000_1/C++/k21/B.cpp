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
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);
	REP(t,T) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double m = X / 2;
		int k = 0;
		while (true) {
			double lm = m;
			m += (C-X) / (2+k*F);
			++k;
			m += X / (2+k*F);
			if (m > lm) {
				//DEBUG(k);
				printf("Case #%d: %lf\n", t+1, lm);
				break;
			}
		}
	}
	return 0;
}
