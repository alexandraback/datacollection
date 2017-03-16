#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int T = 1;

	while (tc--) {
		int n;
		scanf("%d", &n);

		printf("Case #%d: ", T++);

		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}

		int d[10];
		for (int i = 0; i < 10; ++i)
			d[i] = 0;

		int cnt = 0;

		for (int i = n; ; i += n) {
			int num = i;
			while (num) {
				if (!d[num % 10]) {
					++cnt;
					d[num % 10] = 1;
				}
				num /= 10;
			}

			if (cnt == 10) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}