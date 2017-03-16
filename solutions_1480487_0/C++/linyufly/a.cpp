#include <cstdio>

const int maxn = 1000;
const double eps = 1e-8;

int Sign(double a) {
	return a < -eps ? -1 : a > eps;
}

int s[maxn];
int n;

bool Check(int idx, double percentage, double sum) {
	double left = 1 - percentage;
	double value = s[idx] + sum * percentage;
	for (int i = 0; i < n; i++)
		if (i != idx) {
			double diff = value - s[i];
			if (diff < 0) continue;
			double needed = diff / sum;
			if (left >= needed) {
				left -= needed;
				continue;
			}
			return true;
		}
	return false;
}

void Solve() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	for (int i = 0; i < n; i++) {
		double left = 0;
		double right = 1;
		for (int k = 0; k < 40; k++) {
			double mid = (left + right) / 2;
			if (Check(i, mid, sum)) right = mid;
			else left = mid;
		}
		printf(" %lf", (left + right) * 50);
	}
	printf("\n");
}

int main() {
	int t, i;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d:", i + 1);
		Solve();
	}
	return 0;
}