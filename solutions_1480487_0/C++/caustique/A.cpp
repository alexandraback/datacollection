#pragma comment(linker, "/stack:64000000")

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

typedef long long llong;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tests;
	cin >> tests;
	for (int tst = 1; tst <= tests; tst++) {
		printf("Case #%d: ", tst);
		int n;
		cin >> n;
		vector <int> v(n);
		REP(i, n) cin >> v[i];
		int sum = 0;
		REP(i, n) sum += v[i];		
		REP(i, n) {
			double L = 0, R = 100;
			REP(iter, 100) {
				double M = (L + R) / 2;
				double score = v[i] + sum * M / 100.;
				double Y = 0;
				REP(j, n) {
					Y += max(0., (score - v[j]) / sum);
				}
				if (Y >= 1 + 1e-9) {					
					R = M;
				} else {
					L = M;
				}
			}
			printf("%.10lf ", L);
		}
		printf("\n");
	}
	return 0;
}