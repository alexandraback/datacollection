#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int N, T, A;
double gra[10];
double d, t;
double ti[10], di[10];
int main() {
		freopen("input.in", "r", stdin);
		freopen("ans.txt", "w", stdout);
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca) {
		scanf("%lf %d %d", &d, &N, &A);
		for(int i = 0; i < N; ++i) {
			scanf("%lf %lf", &ti[i], &di[i]);
		}
		for(int i = 0; i < A; ++i) {
			scanf("%lf", &gra[i]);
		}
		printf("Case #%d:\n", ca);
		if(N == 1 || di[0] >= d) {
			for(int i = 0; i < A; ++i) {
				printf("%lf\n", sqrt(2 * d / gra[i]));
			}
		} else {
			for(int i = 0; i < A; ++i) {
				double t1 = (ti[1] - ti[0]) / (di[1] - di[0]) * (d - di[0]) + ti[0];
				double t2 = sqrt(2 * d / gra[i]);
				t1 = max(t1, t2);
				printf("%.9lf\n", t1);
			}

		}
	}
	return 0;
}