#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 1;

int A, B;
double p[MAXN], right[MAXN];

double calc() {
	right[0] = 1;
	for (int i = 1; i <= A; i++) {
		right[i] = right[i - 1] * p[i];
	}
	double res = min(B + 2, A + B + 1);
	for (int i = 1; i <= A; i++) {
		res = min(res, right[i] * (A - i + B - i + 1) + (1 - right[i]) * (A - i + B - i + 1 + B + 1));
	}
	return res;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		scanf("%d%d", &A, &B);
		for (int i = 1; i <= A; i++) {
			scanf("%lf", &p[i]);
		}
		printf("Case #%d: %.13lf\n", taskIdx + 1, calc());
	}
	return 0;
}
