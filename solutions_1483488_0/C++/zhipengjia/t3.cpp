
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i ++) {
		int A, B;
		scanf("%d%d", &A, &B);
		int ans = 0;
		for (int n = A; n < B; n ++) {
			int tmp = n, cnt = 0, digits[7];
			while (tmp > 0) {
				digits[cnt ++] = tmp % 10;
				tmp /= 10;
			}
			for (int j = 0; j * 2 < cnt; j ++)
				swap(digits[j], digits[cnt - j - 1]);
			for (int j = 1; j < cnt; j ++) {
				int m = 0;
				for (int k = j; k < cnt; k ++)
					m = m * 10 + digits[k];
				for (int k = 0; k < j; k ++)
					m = m * 10 + digits[k];
				if (n < m && m <= B) {
					//printf("%d %d\n", n, m);
					ans ++;
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	
	return 0;
}