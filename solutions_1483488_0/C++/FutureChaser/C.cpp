#include <stdio.h>
#include <string.h>

const int MAXN = 2000010;

int a, b;
int hash[MAXN];
bool used[MAXN];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int k = 0; k < cases; ++k) {
		scanf("%d%d", &a, &b);
		int numdigit = 0;
		int temp = a;
		int tens = 1;
		while (temp > 0) { temp /= 10; tens *= 10; ++numdigit; }
		tens /= 10;
//		fprintf(stderr, "numdigit = %d, tens = %d\n", numdigit, tens);
		memset(hash, 0, sizeof(hash));
		memset(used, 0, sizeof(used));
		for (int i = a; i <= b; ++i) {
			if (used[i]) continue;
			int mini = i;
			int num = i;
			int count = 0;
			for (int j = 0; j < numdigit; ++j) {
				num = (num / 10) + (num % 10) * tens;
				if ((num >= a) && (num <= b) && !used[num]) {
					used[num] = true;
					++count;
					if (num < mini) mini = num;
				}
			}
//			fprintf(stderr, "i = %d, mini = %d\n", i, mini);
			hash[mini] = count;
		}
		int ans = 0;
		for (int i = tens; i < tens * 10; ++i) {
			if (hash[i] == 0) continue;
//			fprintf(stderr, "i = %d, hash = %d\n", i, hash[i]);
			ans += hash[i] * (hash[i] - 1) / 2;
		}
		printf("Case #%d: %d\n", k + 1, ans);
	}
	return 0;
}
