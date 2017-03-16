#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> tb[2000000];

void gaoTB(int maxi) {
	for (int n = 0; n < maxi; ++n) {
		printf("\ngao n = %d\n", n);
		int x = n;
		int mod = 10;
		while(1) {
			int rem = n % mod;
			int head = n / mod;
			if (head == 0)
				break;
			printf("%d, %d\n", head, rem);
			mod *= 10;
		}
	}
}

inline int dig(int n) {
	int ret = 0;
	while (n > 0) {
		++ret;
		n /= 10;
	}
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	//gaoTB(1001);
	int cas, ans, A, B, n, m, pw[10];
	pw[0] = 1;
	for (int i = 1; i < 9; ++i)
		pw[i] = pw[i - 1] * 10;
	scanf("%d%*c", &cas);
	for (int c = 1; c <= cas; ++c) {
		ans = 0;
		scanf("%d%d", &A, &B);
		for (int n = A; n <= B; ++n) {
			int dn = dig(n);
			vector<int> ss;
			//printf("n = %d, dig = %d\n", n, dn);
			for (int i = 1; i < dn; ++i) {
				int amod = pw[i];
				int bmod = pw[dn - i];
				//printf("i = %d, amod = %d, bmod = %d\n", i, amod, bmod);
				int a = n / amod;
				int b = n % amod;
				if (a > 0 && b > 0 && dig(b) == i) {
					int m = b * bmod + a;
					if (m > n && m <= B && dig(m) == dn) {
						bool find = false;
						for (int ii = 0; ii < ss.size(); ++ii) {
							if (ss[ii] == m) {
								find = true;
								break;
							}
						}
						if (find)
							break;
						ss.push_back(m);
						++ans;
					}
				}
			}
		}
		printf("Case #%d: %d\n", c, ans);
	}

	return 0;
}