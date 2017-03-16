#include <cstdio>
#include <stack>

using namespace std;

const int MAX = 2000005;

bool used[MAX];

int main() {
	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		int a, b; scanf("%d %d", &a, &b);

		stack < int > ms;

		int ans = 0;

		for (int n = a; n < b; n++) {
			int digits = 0;
			int tmp = n;
			int mult = 1;
			while (tmp > 0) {
				digits++;
				tmp /= 10;
				mult *= 10;
			}

			mult /= 10;

			int m = n;
			tmp = n;
			for (int i = 0; i < digits - 1; i++) {
				int digit = tmp % 10;
				tmp /= 10;

				m /= 10;
				m += mult * digit;

				if (a <= n && n < m && m <= b && !used[m]) {
					ans++;

					ms.push(m);
					used[m] = true;
				}
			}

			while (!ms.empty()) {
				used[ms.top()] = false;
				ms.pop();
			}

		}

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
