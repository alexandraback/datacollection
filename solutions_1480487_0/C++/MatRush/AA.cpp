#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1111;
int a[MAXN];
double ans[MAXN];
int main() {
	freopen("A-small-attempt4.in", "r", stdin);
	freopen("A-small-attempt4.out", "w", stdout);
	int n, cas, T = 0;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case #%d:", ++T);
		double avg = sum / (double)n;
		int c = 0;
		double s = sum;
		for (int i = 0; i < n; i++) {
			if (avg * 2 >= a[i]) {
				s += a[i];
				c++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (avg * 2 < a[i]) {
				printf(" 0.0");
			} else {
				printf(" %.6lf", 100 * (s / c - a[i]) / sum);
			}
		}
		puts("");
	}
}
