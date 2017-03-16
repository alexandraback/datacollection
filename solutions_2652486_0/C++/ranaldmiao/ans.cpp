#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int lcm (int a, int b) {
	if (b == 0) return a;
	return lcm(b, a%b);
}
int r, n, m, k, has[20];
void factorize(int x) {
	for (int i = 2; i <= m; ++i) {
		int count = 0;
		while (x % i == 0) {
			x /= i;
			++count;
		}
		has[i] = max(has[i], count);
	}
}
int main () {
	scanf("%d", &r);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	for (int i = 0; i < r; ++i) {
		memset(has, 0, sizeof(has));
		for (int j = 0; j < k; ++j) {
			int t;
			scanf("%d", &t);
			factorize(t);
		}
		int sumhas = 0;
		for (int i = 2; i <= 5; ++i) sumhas += has[i];
		while (sumhas > 3) has[2]-=2, has[4]++, sumhas--;
		int c= 0;
		for (int x = 5; x >= 2 && c < 3; --x) {
			while (c < 3 && has[x] > 0) {
				has[x]--;
				c++;
				printf("%d", x);
			}
		}
		while (c++ < 3) printf("2");
		printf("\n");
	}
}