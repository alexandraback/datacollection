#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define N 10

char n[N];
int t;
long long sum, mod;

int main() {
	int cas = 0;
	while (1) {
		scanf("%s%d", n, &t);
		if (t == -1) break;
		int l = strlen(n);
		sum = 0;
		mod = 0;
		for (int i = 0; i < l; ++i) {
			int tmp = n[i] - '0';
			sum += tmp;
			mod = (mod * 10 + tmp) % 11;
		}
		for (int i = 0; i < t; ++i) {
			long long new_sum = sum;
			long long tmp_sum = sum;
			long long p = 1;
			while (sum > 0) {
				new_sum += sum % 10;
				p *= 10;
				sum /= 10;
			}
			mod = (mod * p + tmp_sum) % 11;
			sum = new_sum;
		}
		// printf("%lld\n", sum);
		printf("Case #%d: %s\n", ++cas, mod == 0? "Yes": "No");
	}
	return 0;
}