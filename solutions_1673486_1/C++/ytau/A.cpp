


#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;



const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;

int T, A, B;
double p[100005], ans;

double solve1() {
	double tmp = 1;
	for (int i=1; i<=A; i++) {
		tmp *= p[i];
	}
//printf("%f\n", tmp * (B-A+1) + (1-tmp) * (B-A+1 + B+1));
	return tmp * (B-A+1) + (1-tmp) * (B-A+1 + B+1);
}

double solve2() {
	double P[100005];
	P[0] = 1;
	for (int i=1; i<=A; i++) {
		P[i] = P[i-1]*p[i];
	}
	double ret = finf;
	for (int i=1; i<=A; i++) {
//printf("%f %f %d\n", P[A-i] * (i+ (B-A+i+1)) , (1-P[A-i]) , (i+ (B-A+i+1) + B + 1));
//printf("%f\n", P[A-i] * (i+ (B-A+i+1)) + (1-P[A-i]) * (i+ (B-A+i+1) + B + 1));
		ret = min(ret, P[A-i] * (i+ (B-A+i+1)) + (1-P[A-i]) * (i+ (B-A+i+1) + B + 1));
	}
	return ret;
}

double solve3() {
//printf("%f\n", 1.0+B+1.0);
	return 1.0+B+1.0;
}

int main() {

	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d%d",&A, &B);
		for (int i=1; i<=A; i++) {
			scanf("%lf", &p[i]);
		}
		ans = finf;
		ans = min(ans, solve1());
		ans = min(ans, solve2());
		ans = min(ans, solve3());
		printf("Case #%d: %f\n",tt, ans);
	}
	
	return 0;
}


