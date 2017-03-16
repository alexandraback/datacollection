#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int lcm (int a, int b) {
	if (b == 0) return a;
	return lcm(b, a%b);
}
int r, n, m, k, has[20], can[20], primes[] = {5, 7};
void factorize(int x) {
	
	for (int i = 2; i <= m; ++i) {
		int count = 0;
		int t = x;
		while (t % i == 0) {
			t /= i;
			++count;
		}
		has[i] = max(has[i], count);
	}
}
int main () {
	scanf("%d", &r);
	printf("Case #1:\n");
	scanf("%d%d%d%d", &r, &n, &m, &k);
	for (int i = 0; i < r; ++i) {
		memset(has, 0, sizeof(has));
		memset(can, 0, sizeof(can));
		for (int j = 0; j < k; ++j) {
			int t;
			scanf("%d", &t);
			factorize(t);
		}
		int sumhas = 0;
		for (int i = 2; i <= m; ++i) sumhas += has[i];
		if (sumhas == n) {
			for (int i = 2; i <=m; ++i) {
				while (has[i]--) printf("%d", i);
			}
			printf("\n");
			continue;
		}
		int c= 0;
		while (has[7]>0) {
			has[7]--;
			printf("7");
			c++;
			sumhas--;
		}
		while (has[5]>0) {
			has[5]--;
			printf("5");
			c++;
			sumhas--;
		}
		
		for (int x = 8, c = 0; x >= 2 && c < n; --x) {
			while (c < n && has[x] > 0) {
				has[x]--;
				if (x == 6) has[3]--, has[2]--;
				if (x == 8) has[2] -= 3;
				if (x == 4) has[2] -= 2;
				c++;
				printf("%d", x);
			}
		}
		while (c < n) {
			printf("2");
			++c;
			if (c < n) {
				printf("3");
				++c;
			}
		}
		printf("\n");
	}
}