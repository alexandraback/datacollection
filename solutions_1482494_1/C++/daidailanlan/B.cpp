#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 1;

int n, a[MAXN], b[MAXN], state[MAXN];

int calc() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (b[i] < b[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
	}
	int res = 0, m = n, rating = 0;
	while (true) {
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (state[i] < 2 && b[i] <= rating) {
				found = true;
				rating += 2 - state[i];
				state[i] = 2;
				res++;
//printf("2 step = %d idx = %d rating = %d\n", res, i, rating);
				m--;
			}
		}
		if (found) continue;
		for (int i = 0; i < n; i++) {
			if (state[i] < 1 && a[i] <= rating) {
				found = true;
				rating += 1 - state[i];
				state[i] = 1;
				res++;
//printf("1 step = %d idx = %d rating = %d\n", res, i, rating);
				break;
			}
		}
		if (!found) break;
	}
	return m == 0 ? res : -1;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			state[i] = 0;
		}
		printf("Case #%d: ", taskIdx + 1);
		int res = calc();
		if (res == -1) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}
