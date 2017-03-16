#include <iostream>
#include <cmath>
using namespace std;

int n;
int s[1000];
int tot;

bool test(int j, double fac) {
	double myfrac = tot * fac;
	double myscore = s[j] + myfrac;
	double remain = tot - myfrac;

	for (int i = 0; i < n; i++) {
		if (i == j) continue;
		if (s[i] >= myscore) continue;
		double need = myscore - s[i];
		if (need > remain) return true;	//can gurantee

		remain -= need;
	}
	return false;
}

double bsearch(int j) {
	double low = 0, high = 1;

	while (abs(high - low) > 1e-9) {
		double mid = (low+high) /2;
		if (test(j, mid)) high = mid;
		else low = mid;
	}
	return low;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {

		scanf("%d", &n);
		tot = 0;
		for (int i= 0; i < n; i++) {
			scanf("%d", &s[i]);
			tot += s[i];
		}

		printf("Case #%d:", k+1);
		for (int i = 0; i < n; i++) {
			printf(" %f", bsearch(i) * 100);
		}

		if (k<t-1) printf("\n");
	}
	return 0;
}