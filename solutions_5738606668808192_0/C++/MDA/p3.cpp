#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <assert.h>
#include <set>

using namespace std;

int N = 16;
int J = 50;
int ans[10];

int dv[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 };

void print(long long n) {
	char str[100];
	str[0] = str[N-1] = '1';
	str[N] = 0;
	for (int i = 1; i + 1 < N; ++i) {
		str[i] = '0' + n % 2;
		n /= 2;
	}
	reverse(str, str + N);
	printf(str);
}

bool check(long long n, int b, int d) {
	int rem = 1, mul = 1;
	for (int i = 0; i + 2 < N; ++i) {
		mul = (mul*b) % d;
		if (n & 1) {
			rem = (rem + mul);
			if (rem > d)
				rem -= d;
		}
		n >>= 1;
	}
	rem = (rem + mul*b) % d;
	return rem == 0;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("C:\\Users\\dmarin3\\Downloads\\B-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	printf("Case #1:\n");
	for (long long n = 0; n < (1ll << N-2); ++n) {
		bool good = true;
		for (int b = 2; b <= 10; ++b) {
			int ok = 0;
			for (int i = 0; i < 10; ++i) {
				if (check(n, b, dv[i])) {
					ok = dv[i];
					break;
				}
			}
			if (!ok) {
				good = false;
				break;
			}
			ans[b - 2] = ok;
		}
		if (good) {
			print(n);
			for (int i = 0; i < 9; ++i)
				printf(" %d", ans[i]);
			printf("\n");
			J--;
			if (J == 0)
				break;
		}
	}
}