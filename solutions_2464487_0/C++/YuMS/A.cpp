#include <cstdio>
unsigned long long int deal() {
	unsigned long long int r, t;
	unsigned long long int nowr, need;
	unsigned long long int counter;
	scanf("%llu%llu", &r, &t);
	nowr = r;
	counter = 0;
	need = nowr * 2 + 1;
	while (t >= need) {
		t -= need;
		counter++;
		nowr += 2;
		need = nowr * 2 + 1;
	}
	return counter;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: %llu\n", i + 1, deal());
	}
	return 0;
}
