#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-10;
const double pi = acos(-1.0);
double sum = 0;


double Dist(double v0, double t, double a) {
	return v0 * t  + 0.5 * a * t * t;
}

double Time(double d, double a) {
	return sqrt(2 * d / a);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("outputB.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		printf("Case #%lld:\n", test + 1);
		double D;
		int N, A;
		cin >> D >> N >> A;
		vector<pair<double, double> > car(N);
		REP(i, N) {
			cin >> car[i].first >> car[i].second;
		}
		REP(i, A) {
			double a;
			cin >> a;
			if (N == 1) {
				printf("%.7llf\n", Time(D, a));
				continue;
			}
			if (N == 2) {
				if (Dist(0, car[0].first, a) > car[0].second || car[0].second >= D) {
					printf("%.7llf\n", Time(D, a));
					continue;
				} else {
					if (car[1].second > D) {
						printf("%.8llf\n", car[0].first + (D - car[0].second) * (car[0].first - car[1].first) / (car[0].second - car[1].second));
						continue;
					}
					double tt = Time(car[1].second, a);
					double vv = tt * a;
					if (tt > car[1].first) {
						printf("%.7llf\n", Time(D, a));
						continue;
					}
					printf("%.7llf\n", Time(D, a) + (car[1].first - tt));
					continue;
				}

			}
		}


	}
	return 0;
}