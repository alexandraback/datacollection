#include <iostream>
#include <string>

using namespace std;

int main() {
	
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t, k, c, s;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		cin >> k >> c >> s;
		printf("Case #%d: ", test + 1);
		if (s < (k / c + (k % c > 0))) {
			printf("IMPOSSIBLE");
		} else {
			for (int pointer = 0; pointer < k;) {
				long long left = 0;
				for (int level = 0; level < c; ++level, ++pointer) {
					left = min(pointer, k - 1) + left * k;
				}
				printf("%I64d ", left + 1);
			}
		}
		printf("\n");
	}
    return 0;
}