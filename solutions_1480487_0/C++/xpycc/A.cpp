#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5000];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n; scanf("%d", &n);
		double s = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i), s += a[i];
		double avg = s / n;
		int m = 0; double s2 = s;
		for (int i = 0; i < n; ++i)
			if (avg * 2 >= a[i]) {
				m++; s2 += a[i];
			}
		printf("Case #%d:", cas);
		for (int i = 0; i < n; ++i)
			if (avg * 2 < a[i])
				printf(" 0.0");
			else
				printf(" %.8f", (s2 / m - a[i]) / s * 100);
		puts("");
	}
	return 0;
}
