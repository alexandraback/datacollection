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

int T, N;
vector<double> naomi, ken;

int sign(double x) {
	const double EPS = 1.0e-9;
	return (x > EPS) - (x < -EPS);
}

int main() {
	scanf("%d", &T);
	REP(tid, T) {
		scanf("%d", &N);
		naomi.resize(N);
		REP(i, N) scanf("%lf", &naomi[i]);
		ken.resize(N);
		REP(i, N) scanf("%lf", &ken[i]);

		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		// REP(i, N) printf("%.3f ", naomi[i]);
		// printf("\n");

		// REP(i, N) printf("%.3f ", ken[i]);
		// printf("\n");

		int i = 0, j = 0, ans1 = 0, ans2 = 0;

		i = 0;
		for (j = 0; j < N; j++) {
			while (i < N && sign(naomi[i] - ken[j]) <= 0) ++i;
			if (i < N) {
				ans1 += 1;
				++i;
			}
		}

		j = 0;
		for (i = 0; i < N; i++) {
			while (j < N && sign(ken[j] - naomi[i]) <= 0) ++j;
			// if (j < N) printf("naomi %.3f ken %.3f\n", naomi[i], ken[j]);
			if (j < N) {
				++j;
			} else {
				ans2 = N - i;
				break;
			}
		}

		printf("Case #%d: %d %d\n", tid + 1, ans1, ans2);
	}
	return 0;
}