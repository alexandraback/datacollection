#include <cstdio>
#include <cstring>

long queue[11111111], step[11111111];

long reverse(long v) {
	long result = 0;
	while (v) {
		result = result * 10 + v % 10;
		v /= 10;
	}
	return result;
}

long solve() {
	long n;
	scanf("%ld", &n);

	memset(step, 0, sizeof(step));
	long head = 0, tail = 1;
	queue[0] = 1;
	step[1] = 1;
	while (head < tail) {
		long v = queue[head++], v0;
		if (v == n) return step[v];
		
		v0 = v + 1;
		if (v0 < 10000000 && !step[v0]) {
			queue[tail++] = v0;
			step[v0] = step[v] + 1;
		}

		v0 = reverse(v);
		if (v0 < 10000000 && !step[v0]) {
			queue[tail++] = v0;
			step[v0] = step[v] + 1;
		}
	}

	return 0;
}

int main(void) {
	int test_count;
	scanf("%d", &test_count);
	for (int test = 1; test <= test_count; ++ test) {
		printf("Case #%d: %ld\n", test, solve());
	}
	return 0;
}
