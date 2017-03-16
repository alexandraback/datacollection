#include <stdio.h>
const int MAX = 200;
int person[MAX];
int N, S, p;

int pass() {
	int i, j, mini = 3*p-4;
	int concrete = 0, abstrac = 0;
	if (p == 0) return N;
	if (p == 1) {
		for (i = 0; i < N; ++i)
			if (person[i] >= 1) ++concrete;
		return concrete;
	}
	for (i = 0; i < N; ++i) {
		if (person[i] == mini || person[i] == mini + 1) ++abstrac;
		else if (person[i] >= mini + 2) ++concrete;
	}
	if (abstrac > S) abstrac = S;
	return concrete + abstrac;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\test\\codejam\\B-small-attempt0.in", "r", stdin);
	freopen("E:\\test\\codejam\\test.out", "w", stdout);
#endif

	int caseno, i, T;
	scanf("%d", &T);
	getchar();
	for (caseno = 1; caseno <= T; ++caseno) {
		scanf("%d%d%d", &N, &S, &p);
		for (i = 0; i < N; ++i) {
			scanf("%d", &person[i]);
		}
		printf("Case #%d: %d\n", caseno, pass());
	}
	return 0;
}