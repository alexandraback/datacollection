#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
	
int T, N, A;
double D, a[251], t[2001], x[2001], aa;
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt","w",stdout);
	int tt, i, j, k;
	double p, v, re, vo, gap, vdiff, t_gap, ss, xx;
	scanf("%d", &T);
	for (tt = 1; tt <= T; tt++) {
		scanf("%lf", &D);
		scanf("%d%d", &N, &A);
		for (i = 0; i < N; i++) {
			scanf("%lf%lf", &t[i], &x[i]);
		}
		printf("Case #%d:\n", tt);
		bool complete = false;
		for (i = 0; i < A; i++) {
			scanf("%lf", &aa);
			if (tt == 3)
				int dsf = 1;
			p = 0; v = 0, re = 0; 
			ss = 0.5 * aa * t[0] * t[0];
			if (x[0] >= D){
				re = sqrt(D * 2 / aa);
			} else {
				if (x[0] - 0 < 0.000000001) {
					p = 0;
					v = 0;
				}
				else if (ss >= x[0]) {
					p = x[0];
					v = (x[1] - x[0]) / (t[1] - t[0]);
				} else {
					p = ss;
					v = aa * t[0];
				}
				re = t[0];
				for (j = 0; j < N - 1; j++) {
					vo = (x[j + 1] - x[j]) / (t[j + 1] - t[j]);
					t_gap = t[j + 1] - t[j];
					double ddd = x[j + 1] - D;
					if (x[j + 1] > D + 0.0000001) {
						t_gap = (D - x[j]) / (x[j + 1] - x[j]) * (t[j + 1] - t[j]);
					}
					ss = v * t_gap + 0.5 * aa * t_gap * t_gap;
					if (ss >= x[j + 1] - p) {
						p = x[j + 1];
						v = vo;
					} else {
						p += ss;
						v += aa * t_gap;
					}
					re += t_gap;
					if (complete)
						break;
				}
				if (p < D) {
					double dt = (-2 * v  + sqrt(4 * v * v - 8 * aa * (p - D))) / (2 * aa);
					re += dt;
				}
			}	
			printf("%.8lf\n", re);
		}
	}
	return 0;
}