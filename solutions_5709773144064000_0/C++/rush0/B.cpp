#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

int T;
double C, F, X;

int main() {
	scanf("%d", &T);
	REP(tid, T) {
		scanf("%lf%lf%lf", &C, &F, &X);

		double ans = X / 2.0;
		double build = 0.0, prev = X / 2.0;
		int cnt = 0;
		for (int k = 1; true; k++) {
			build += C / (2.0 + (k - 1) * F);
			double curr = build + X / (2.0 + k * F);
			ans = min(ans, curr);
			if (curr > prev) ++cnt;
			if (cnt > 10) break;
			prev = curr;
		}

		printf("Case #%d: %.7f\n", tid + 1, ans);
	}
	return 0;
}