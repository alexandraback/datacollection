#include <cstdio>
#include <string>
#include <algorithm>

int get_result(int *mass, int init_mass, int n) {
	std::sort(mass, mass + n);
	int result = n;
	if (init_mass == 1)
		return result;

	int ops = 0;
	for (int i = 0; i < n; ++i) {
		if (n - i + ops < result)
			result = n - i + ops;
		while (init_mass <= mass[i]) {
			++ops;
			init_mass = init_mass * 2 - 1;
		}
		init_mass += mass[i];
	}
	if (ops < result)
		result = ops;

	return result;
}

void read_data(int *mass, int *p_init_mass, int *p_n) {
	scanf("%d %d", p_init_mass, p_n);
	for (int i = 0; i < *p_n; ++i)
		scanf("%d", mass + i);
}

const int MAXN = 100;

int main() {
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		int mass[MAXN];
		int init_mass;
		int n;
		read_data(mass, &init_mass, &n);
		printf("Case #%d: %d\n", i, get_result(mass, init_mass, n));
	}
	return 0;
}
